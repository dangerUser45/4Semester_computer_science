#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/random.h>

#include "animal.h"
#include "cat.h"

#define NUM_CLAWS 10

//------------------------------------------------------------------------------
void cat_init(struct cat* cat, const char* name) {
  assert(cat); assert(name);

  animal_init((struct animal*)cat, name);
  cat->claws = NUM_CLAWS;
}
//------------------------------------------------------------------------------
void cat_voice(struct cat* cat) {
  assert(cat);
  
  printf("мяу-мяу: %s\n", cat->parent.name);
}
//------------------------------------------------------------------------------
void cat_scratch(struct cat* cat) {
  assert(cat);

  unsigned int damage = 0u;
  ssize_t bytes_read = getrandom(&damage, sizeof(damage), 0);
  if (bytes_read != (ssize_t)sizeof(damage)) {
    damage = 0u;
  }

  int total_damage = cat->claws + (int)(damage % 10u);
  printf("Я %s. Поцарапала на урон = %d\n",
         cat->parent.name, total_damage);
}
//------------------------------------------------------------------------------
int cat_init_v(void* self, va_list* arg_list) {
  assert(self); assert(arg_list);
  
  const char* name = va_arg(*arg_list, const char*);
  cat_init((struct cat*) self, name);
  return 0;
}
//------------------------------------------------------------------------------
int cat_voice_v(void* self, va_list* arg_list) {
  assert(self); assert(arg_list);
  
  cat_voice((struct cat*)self);
  return 0;
}
//------------------------------------------------------------------------------
int cat_scratch_v(void* self, va_list* arg_list) {
  assert(self); assert(arg_list);

  cat_scratch((struct cat*) self);
  return 0;
}
//------------------------------------------------------------------------------
