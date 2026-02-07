#include <stdlib.h>
#include <stdio.h>

#include "animal.h"

#define NUM_CLAWS 10

struct cat {
  struct animal super;

  int claws;
};

void cat_voice(struct cat* cat) {
  printf("мяу-мяу: %s\n", cat->super.name);
}

double cat_scratch(struct cat* cat) {
  double damage = (double)(cat->claws + rand()%10);
  printf("Я %s. Поцарапала на урон = %f\n",
         cat->super.name, damage);
  return damage;
}

void cat_destroy(struct cat* cat) {
  free(cat);
}

struct cat* cat_create_with_init(char* name) {
  struct cat* cat_ptr = malloc(sizeof(struct cat));
  cat_ptr->super.name = name;
  cat_ptr->claws = NUM_CLAWS;
  cat_ptr->super.vt.voice   = (animal_voice_t)cat_voice;
  cat_ptr->super.vt.destroy = (animal_destroy_t)cat_destroy;

  return cat_ptr;
}
