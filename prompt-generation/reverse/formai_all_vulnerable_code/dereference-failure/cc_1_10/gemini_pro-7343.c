//GEMINI-pro DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
  char *website;
  char *username;
  char *password;
};

struct Database {
  struct Account *accounts;
  int num_accounts;
};

struct Database *database;

void init_database() {
  database = malloc(sizeof(struct Database));
  database->accounts = NULL;
  database->num_accounts = 0;
}

void add_account(const char *website, const char *username, const char *password) {
  database->accounts = realloc(database->accounts, (database->num_accounts + 1) * sizeof(struct Account));
  database->accounts[database->num_accounts].website = strdup(website);
  database->accounts[database->num_accounts].username = strdup(username);
  database->accounts[database->num_accounts].password = strdup(password);
  database->num_accounts++;
}

void remove_account(int index) {
  if (index >= 0 && index < database->num_accounts) {
    free(database->accounts[index].website);
    free(database->accounts[index].username);
    free(database->accounts[index].password);
    for (int i = index; i < database->num_accounts - 1; i++) {
      database->accounts[i] = database->accounts[i + 1];
    }
    database->num_accounts--;
  }
}

void print_database() {
  for (int i = 0; i < database->num_accounts; i++) {
    printf("%s %s %s\n", database->accounts[i].website, database->accounts[i].username, database->accounts[i].password);
  }
}

void destroy_database() {
  for (int i = 0; i < database->num_accounts; i++) {
    free(database->accounts[i].website);
    free(database->accounts[i].username);
    free(database->accounts[i].password);
  }
  free(database->accounts);
  free(database);
}

int main() {
  init_database();

  add_account("example.com", "johndoe", "password123");
  add_account("anothersite.com", "janedoe", "password456");

  print_database();

  remove_account(1);

  print_database();

  destroy_database();

  return 0;
}