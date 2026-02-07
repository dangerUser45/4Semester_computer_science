#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>

#include "animal.h"

#define NUM_TEETH 42

struct dog {
  struct animal super;
  int teeth;
};

void dog_voice(struct dog* dog) {
  printf("гав-гав: %s\n", dog->super.name);
}

void dog_bite(struct dog* dog, int teeth) {
  unsigned int damage = 0;
  getrandom(&damage, sizeof(unsigned int), 0);
  printf("Я %s. Укусила на урон = %d\n",
         dog->super.name, damage % 10);
}

void dog_destroy(struct dog* dog) {
  free(dog);
}

struct dog* dog_create_with_init(char* name) {
  struct dog* dog_ptr = calloc(sizeof(struct dog), 1);
  dog_ptr->super.name = name;
  dog_ptr->teeth = NUM_TEETH;
  dog_ptr->super.vt.voice   = (animal_voice_t)dog_voice;
  dog_ptr->super.vt.destroy = (animal_destroy_t)dog_destroy;

  return dog_ptr;
}
