//GEMINI-pro DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Password {
  char *site;
  char *username;
  char *password;
};

struct PasswordManager {
  struct Password *passwords;
  int num_passwords;
};

void init_password_manager(struct PasswordManager *manager) {
  manager->passwords = NULL;
  manager->num_passwords = 0;
}

void add_password(struct PasswordManager *manager, char *site, char *username, char *password) {
  manager->passwords = realloc(manager->passwords, (manager->num_passwords + 1) * sizeof(struct Password));
  manager->passwords[manager->num_passwords].site = strdup(site);
  manager->passwords[manager->num_passwords].username = strdup(username);
  manager->passwords[manager->num_passwords].password = strdup(password);
  manager->num_passwords++;
}

void print_passwords(struct PasswordManager *manager) {
  for (int i = 0; i < manager->num_passwords; i++) {
    printf("%s\n", manager->passwords[i].site);
    printf("%s\n", manager->passwords[i].username);
    printf("%s\n", manager->passwords[i].password);
  }
}

void free_passwords(struct PasswordManager *manager) {
  for (int i = 0; i < manager->num_passwords; i++) {
    free(manager->passwords[i].site);
    free(manager->passwords[i].username);
    free(manager->passwords[i].password);
  }
  free(manager->passwords);
  manager->num_passwords = 0;
}

int main() {
  struct PasswordManager manager;
  init_password_manager(&manager);
  add_password(&manager, "google.com", "johndoe", "password1");
  add_password(&manager, "facebook.com", "janedoe", "password2");
  print_passwords(&manager);
  free_passwords(&manager);
  return 0;
}