#include <stdlib.h>
#include <stdio.h>
#include "../include/dog.h"

struct dog* dog_create() {
  struct dog* dog_ptr = (struct dog*) malloc(sizeof(struct dog));
  dog_ptr->name = "бобик";

  return dog_ptr;
}

struct dog* dog_create_with_name(char* name) {
  struct dog* dog_ptr = malloc(sizeof(struct dog));
  dog_ptr->name = name;

  return dog_ptr;
}

void dog_destroy(struct dog* dog) {
  free(dog);
}

void dog_voice(struct dog* dog) {
  printf("гав-гав: %s\n", dog->name);
}
