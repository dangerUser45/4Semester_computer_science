#pragma once

#include <stdarg.h>

struct animal {
  const char* name;
};

void animal_init(struct animal* animal, const char* name);
int animal_init_v(void* self, va_list* arg_list);
