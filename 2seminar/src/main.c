#include "animal.h"
#include "cat.h"
#include "class.h"
#include "dog.h"
#include "obj.h"

//------------------------------------------------------------------------------
int main() {
  // create classes:

  // Animal
  struct class* Animal = class_CreateClass(NULL, "Animal",
    sizeof(struct animal));
  class_AddMethod(Animal, "animal_init", (func_ptr)animal_init_v);

  // Dog
  struct class* Dog = class_CreateClass(Animal, "Dog",
    sizeof(struct dog));
  class_AddMethod(Dog, "dog_init_v", (func_ptr)dog_init_v);
  class_AddMethod(Dog, "dog_voice_v", (func_ptr)dog_voice_v);
  class_AddMethod(Dog, "dog_bite_v", (func_ptr)dog_bite_v);
  
  // Cat
  struct class* Cat = class_CreateClass(Animal, "Cat",
    sizeof(struct cat));
  class_AddMethod(Cat, "cat_init_v", (func_ptr)cat_init_v);
  class_AddMethod(Cat, "cat_voice_v", (func_ptr)cat_voice_v);
  class_AddMethod(Cat, "cat_scratch_v", (func_ptr)cat_scratch_v);

  // create Objects:

  // Dogs
  struct obj* Bobik = classCreateObj(Dog);
  obj_send(Bobik, "dog_init_v", "Бобик");
  struct obj* Sharik = classCreateObj(Dog);
  obj_send(Sharik, "dog_init_v", "Шарик");

  // Cats
  struct obj* Murka = classCreateObj(Cat);
  obj_send(Murka, "cat_init_v", "Мурка");
  struct obj* Matroskin = classCreateObj(Cat);
  obj_send(Matroskin, "cat_init_v", "Кот Матроскин");

  // Voices
  obj_send(Bobik, "dog_voice_v");
  obj_send(Sharik, "dog_voice_v");
  
  obj_send(Murka, "cat_voice_v");
  obj_send(Matroskin, "cat_voice_v");

  // Action
  obj_send(Bobik, "dog_bite_v");
  obj_send(Sharik, "dog_bite_v");
  
  obj_send(Murka, "cat_scratch_v");
  obj_send(Matroskin, "cat_scratch_v");

  // destroy Objects
  classDestroyObj(Bobik);
  classDestroyObj(Sharik);
  classDestroyObj(Murka);
  classDestroyObj(Matroskin);

  // destroy all classes
  class_DestroyClass(Animal);
  class_DestroyClass(Dog);
  class_DestroyClass(Cat);
}
//------------------------------------------------------------------------------
