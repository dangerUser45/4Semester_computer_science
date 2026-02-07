struct dog {
  char* name;
};

struct dog* dog_create();
struct dog* dog_create_with_name(char* name);
void dog_destroy(struct dog*);
void dog_voice(struct dog* dog);
