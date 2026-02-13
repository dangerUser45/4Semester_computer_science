#pragma once

#include <stdarg.h>

#include "animal.h"

struct dog {
  struct animal parent;
  int teeth;
};

void dog_init(struct dog* dog, const char* name);
void dog_voice(struct dog* dog);
void dog_bite(struct dog* dog);

int dog_init_v(void* self, va_list* arg_list);
int dog_voice_v(void* self, va_list* arg_list);
int dog_bite_v(void* self, va_list* arg_list);
