#include <assert.h>
#include <stdarg.h>

#include "animal.h"

//------------------------------------------------------------------------------
void animal_init(struct animal* animal, const char* name) {
  assert(animal); assert(name);
  animal->name = name;
}
//------------------------------------------------------------------------------
int animal_init_v(void* self, va_list* arg_list) {
  const char* name = va_arg(*arg_list , const char*);
  animal_init((struct animal*) self, name);
  return 0;
}
//------------------------------------------------------------------------------
