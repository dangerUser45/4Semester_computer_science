#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "class.h"

//------------------------------------------------------------------------------
struct class* class_CreateClass(struct class* parent,
  const char* name_class, size_t size) {
  
  assert(name_class);
        
  struct class* new_class = calloc(1, sizeof(struct class));
  if(!new_class) {
    printf("%s:%d: Error: memory is not allocated\n", __FILE__, __LINE__);
    return 0;
  }

  new_class->parent = parent;
  new_class->name_class = name_class;
  new_class->size = size;

  return new_class;
}
//------------------------------------------------------------------------------
void class_DestroyClass (struct class* class) {
  assert(class);
  if(class != NULL) free(class);
}
//------------------------------------------------------------------------------
void class_AddMethod(struct class* class, const char* selector, func_ptr func) {
  assert(class); assert(selector); assert(func);
  
  int current_method = class->methods_table.current_method;
  if(current_method >= NUM_METHODS_IN_TABLE) {
    fprintf(stderr, "%s:%d: Error:"
      " the place in the methods array is not enough\n", __FILE__, __LINE__);
    return;
  }

  struct pair* array = class->methods_table.array;
  array[current_method].func = func;
  array[current_method].name_func = selector;

  ++(class->methods_table.current_method);
}
//------------------------------------------------------------------------------
