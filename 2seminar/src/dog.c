#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/random.h>

#include "animal.h"
#include "dog.h"

#define NUM_TEETH 42

//------------------------------------------------------------------------------
void dog_init(struct dog* dog, const char* name) {
  assert(dog); assert(name);
  
  animal_init((struct animal*)dog, name);
  dog->teeth = NUM_TEETH;
}
//------------------------------------------------------------------------------
void dog_voice(struct dog* dog) {
  assert(dog);
  
  printf("гав-гав: %s\n", dog->parent.name);
}
//------------------------------------------------------------------------------
void dog_bite(struct dog* dog) {
  assert(dog);

  unsigned int damage = 0u;
  ssize_t bytes_read = getrandom(&damage, sizeof(damage), 0);
  if (bytes_read != (ssize_t)sizeof(damage)) {
    damage = 0u;
  }

  int total_damage = dog->teeth + (int)(damage % 10u);
  printf("Я %s. Укусила на урон = %d\n",
         dog->parent.name, total_damage);
}
//------------------------------------------------------------------------------
int dog_init_v(void* self, va_list* arg_list) {
  assert(self); assert(arg_list);
  
  const char* name = va_arg(*arg_list, const char*);
  dog_init((struct dog*) self, name);
  return 0;
}
//------------------------------------------------------------------------------
int dog_voice_v(void* self, va_list* arg_list) {
  assert(self); assert(arg_list);
  
  dog_voice((struct dog*)self);
  return 0;  
}
//------------------------------------------------------------------------------
int dog_bite_v(void* self, va_list* arg_list) {
  assert(self); assert(arg_list);
  
  dog_bite((struct dog*) self);
  return 0;
}
//------------------------------------------------------------------------------
