struct cat {
  char* name;
};

struct cat* cat_create();
struct cat* cat_create_with_name(char* name);
void cat_destroy(struct cat*);
void cat_voice(struct cat* cat);
