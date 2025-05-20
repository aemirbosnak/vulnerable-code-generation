//GEMINI-pro DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char **passwords;
  int size;
} PasswordManager;

PasswordManager *create_password_manager(int initial_size) {
  PasswordManager *pm = malloc(sizeof(PasswordManager));
  pm->passwords = malloc(sizeof(char *) * initial_size);
  pm->size = 0;
  return pm;
}

void destroy_password_manager(PasswordManager *pm) {
  for (int i = 0; i < pm->size; i++) {
    free(pm->passwords[i]);
  }
  free(pm->passwords);
  free(pm);
}

void add_password(PasswordManager *pm, char *password) {
  if (pm->size == 0) {
    pm->passwords = malloc(sizeof(char *));
    pm->size = 1;
  } else {
    char **new_passwords = malloc(sizeof(char *) * pm->size * 2);
    for (int i = 0; i < pm->size; i++) {
      new_passwords[i] = pm->passwords[i];
    }
    free(pm->passwords);
    pm->passwords = new_passwords;
    pm->size *= 2;
  }
  pm->passwords[pm->size - 1] = strdup(password);
}

char *get_password(PasswordManager *pm, int index) {
  if (index < 0 || index >= pm->size) {
    return NULL;
  }
  return pm->passwords[index];
}

int main() {
  PasswordManager *pm = create_password_manager(10);
  add_password(pm, "password1");
  add_password(pm, "password2");
  add_password(pm, "password3");
  printf("%s\n", get_password(pm, 0));
  printf("%s\n", get_password(pm, 1));
  printf("%s\n", get_password(pm, 2));
  destroy_password_manager(pm);
  return 0;
}