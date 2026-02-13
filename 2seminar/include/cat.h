#pragma once

#include <stdarg.h>

#include "animal.h"

struct cat {
  struct animal parent;
  int claws;
};

void cat_init(struct cat* cat, const char* name);
void cat_voice(struct cat* cat);
void cat_scratch(struct cat*);

int cat_init_v(void* self, va_list* arg_list);
int cat_voice_v(void* self, va_list* arg_list);
int cat_scratch_v(void* self, va_list* arg_list);
