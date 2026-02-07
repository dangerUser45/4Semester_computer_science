#pragma once

struct cat* cat_create_with_init(char* name);
void cat_destroy(struct cat* cat);

void cat_voice(struct cat* cat);
double cat_scratch(struct cat* cat);
