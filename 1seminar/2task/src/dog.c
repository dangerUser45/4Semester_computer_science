#include <stdlib.h>
#include <stdio.h>

#include "animal.h"

#define NUM_TEETH 42

struct dog {
  struct animal super;

  int teeth;
};

void dog_voice(struct dog* dog) {
  printf("гав-гав: %s\n", dog->super.name);
}

double dog_bite(struct dog* dog, int teeth) {
  double damage = (double)(dog->teeth + rand()%10);
  printf("Я %s. Укусила на урон = %f\n",
         dog->super.name, damage);
  return damage;
}

void dog_destroy(struct dog* dog) {
  free(dog);
}

struct dog* dog_create_with_init(char* name) {
  struct dog* dog_ptr = malloc(sizeof(struct dog));
  dog_ptr->super.name = name;
  dog_ptr->teeth = NUM_TEETH;
  dog_ptr->super.vt.voice   = (animal_voice_t)dog_voice;
  dog_ptr->super.vt.destroy = (animal_destroy_t)dog_destroy;

  return dog_ptr;
}
