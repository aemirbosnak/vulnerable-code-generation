//Gemma-7B DATASET v1.0 Category: Password management ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char *name;
  char *password;
  struct Password *next;
} Password;

void create_password(Password **head) {
  *head = (Password *)malloc(sizeof(Password));
  (*head)->name = strdup("Romantic");
  (*head)->password = strdup("LoveMe");
  (*head)->next = NULL;
}

void add_password(Password **head, char *name, char *password) {
  Password *new_password = (Password *)malloc(sizeof(Password));
  new_password->name = strdup(name);
  new_password->password = strdup(password);
  new_password->next = NULL;

  if (*head == NULL) {
    *head = new_password;
  } else {
    (*head)->next = new_password;
  }
}

void search_password(Password *head, char *name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      printf("Password: %s\n", head->password);
      return;
    }
    head = head->next;
  }

  printf("Password not found.\n");
}

int main() {
  Password *head = NULL;
  create_password(&head);
  add_password(&head, "Passionate", "Heartthrob");
  add_password(&head, "Serene", "Soulful");
  add_password(&head, "Spirited", "Wildest");

  search_password(head, "Passionate");
  search_password(head, "Serene");

  return 0;
}