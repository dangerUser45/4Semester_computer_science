#pragma once

#include <stddef.h>
#include <stdarg.h>

#define NUM_METHODS_IN_TABLE 10
 
typedef int (*func_ptr)(void* self, va_list* arg_list);

struct pair {
  func_ptr func;
  const char* name_func;
};

struct methods_table {
  struct pair array[NUM_METHODS_IN_TABLE];
  int current_method; // index to next (free) element
};

struct class {
  struct class* parent;
  const char* name_class;
  size_t size;

  struct methods_table methods_table;
};

struct class* class_CreateClass(struct class* parent,
  const char* name_class, size_t size);
void class_DestroyClass (struct class* class);

void class_AddMethod(struct class* class, const char* selector, func_ptr func);
