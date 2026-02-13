#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "obj.h"
#include "class.h"

//------------------------------------------------------------------------------
struct obj* classCreateObj(struct class* class) {
  assert(class);
  
  struct obj* new_obj = calloc(1, sizeof(struct obj));
  if (!new_obj) {
    fprintf(stderr, "%s:%d: Error: new_obj is not allocated\n", __FILE__, __LINE__);
    return NULL;
  }

  new_obj->isa = class;

  size_t size = class->size;
  void* memory_for_obj = calloc(1, size);
  if (!memory_for_obj) {
    fprintf(stderr, "%s:%d: Error: memory_for_obj is not allocated\n",
            __FILE__, __LINE__);
    free(new_obj);
    return NULL;
  }

  new_obj->memory_for_obj = memory_for_obj;

  return new_obj;
}
//------------------------------------------------------------------------------
void classDestroyObj(struct obj* obj) {
  assert(obj);
  
  free(obj->memory_for_obj);
  free(obj);
}
//------------------------------------------------------------------------------
int obj_send(struct obj* obj, const char* selector, ...) {
  assert(obj); assert(selector);
  
  va_list arg_list;
  va_start(arg_list, selector);
  int return_value = obj_vsend(obj, selector, &arg_list);
  va_end(arg_list);
  return return_value;
}
//------------------------------------------------------------------------------
int obj_vsend(struct obj* obj, const char* selector, va_list* arg_list) {
  assert(obj); assert(selector); assert(arg_list);

  func_ptr func = obj_lookup(obj, selector);
  if (!func) return -1;
  return func(obj->memory_for_obj, arg_list);
}
//------------------------------------------------------------------------------
func_ptr obj_lookup(struct obj* obj, const char* selector) {
  assert(obj); assert(selector);

  for (struct class* class = obj->isa; class != NULL; class = class->parent) {
    int current_method = class->methods_table.current_method;
    struct pair* array = class->methods_table.array;

    for (int i = 0; i < current_method; ++i) {
      if (!strcmp(selector, array[i].name_func)) {
        return array[i].func;
      }
    }
  }

  fprintf(stderr, "%s:%d: Error: func in methods table is not found\n",
          __FILE__, __LINE__);
  return NULL;
}
//------------------------------------------------------------------------------
