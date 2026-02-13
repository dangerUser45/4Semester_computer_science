#pragma once

#include "class.h"

struct obj {
  struct class* isa;
  void* memory_for_obj;
};

struct obj* classCreateObj(struct class* class);
void classDestroyObj(struct obj* obj);

int obj_send(struct obj* obj, const char* selector, ...);
int obj_vsend(struct obj* obj, const char* selector, va_list* ap);
func_ptr obj_lookup(struct obj* obj, const char* selector);
