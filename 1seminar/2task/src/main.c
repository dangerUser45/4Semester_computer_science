#include "animal.h"
#include "cat.h"
#include "dog.h"

int main() {
  struct animal* cat1 = (struct animal*) cat_create_with_init("Мурка");
  struct animal* cat2 = (struct animal*) cat_create_with_init("Матроскин");
  struct animal* dog1 = (struct animal*) dog_create_with_init("Бобик");
  struct animal* dog2 = (struct animal*) dog_create_with_init("Шарик");

  cat1->vt.voice(cat1);
  cat2->vt.voice(cat2);
  dog1->vt.voice(dog1);
  dog2->vt.voice(dog2);

  cat_scratch((struct cat*)cat1);
  cat_scratch((struct cat*)cat2);
  dog_bite((struct dog*)dog1);
  dog_bite((struct dog*)dog2);

  cat1->vt.destroy(cat1);
  cat2->vt.destroy(cat2);
  dog1->vt.destroy(dog1);
  dog2->vt.destroy(dog2);
}
