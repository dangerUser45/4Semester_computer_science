#pragma once

typedef struct animal* (*animal_voice_t) (struct animal*);
typedef void (*animal_destroy_t) (struct animal*);

struct vtable {  
  animal_voice_t   voice;
  animal_destroy_t destroy;
};

struct animal {
  char* name;
  struct vtable vt;
};

