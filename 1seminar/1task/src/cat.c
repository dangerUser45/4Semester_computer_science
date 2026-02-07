#include <stdio.h>
#include <stdlib.h>

#include "cat.h"

struct cat* cat_create() {
  struct cat* cat_ptr = (struct cat*) malloc(sizeof(struct cat));
  cat_ptr->name = "мурка";

  return cat_ptr;
}

struct cat* cat_create_with_name(char* name) {
  struct cat* cat_ptr = malloc(sizeof(struct cat));
  cat_ptr->name = name;

  return cat_ptr;
}

void cat_destroy(struct cat* cat) {
  free(cat);
}

void cat_voice(struct cat* cat) {
  printf("мяу-мяу: %s\n", cat->name);
}
