#include "cat.h"
#include "dog.h"

int main() {
  struct dog* dog_default = dog_create();
  struct dog* dog         = dog_create_with_name("dog1");

  struct cat* cat_default = cat_create();
  struct cat* cat         = cat_create_with_name("cat1");
  

  dog_voice(dog_default);
  dog_voice(dog);
  
  cat_voice(cat_default);
  cat_voice(cat);


  dog_destroy(dog_default);
  dog_destroy(dog);


  cat_destroy(cat_default);
  cat_destroy(cat);
}
