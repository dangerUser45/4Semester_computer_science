#pragma once

struct dog* dog_create_with_init(char* name);
void dog_destroy(struct dog* dog);

void dog_voice(struct dog* dog);
double dog_bite(struct dog* dog);
