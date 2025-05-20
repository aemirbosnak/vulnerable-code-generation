//Gemma-7B DATASET v1.0 Category: Password management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char *name;
  char *password;
  int strength;
  struct Password *next;
} Password;

void create_password(Password **head) {
  *head = malloc(sizeof(Password));
  (*head)->name = malloc(20);
  (*head)->password = malloc(20);
  (*head)->strength = 0;
  (*head)->next = NULL;
}

void add_password(Password **head, char *name, char *password, int strength) {
  Password *new_password = malloc(sizeof(Password));
  new_password->name = malloc(20);
  new_password->password = malloc(20);
  new_password->strength = strength;
  new_password->next = NULL;

  if (*head == NULL) {
    *head = new_password;
  } else {
    (*head)->next = new_password;
  }
}

void print_passwords(Password *head) {
  while (head) {
    printf("%s: %s, Strength: %d\n", head->name, head->password, head->strength);
    head = head->next;
  }
}

int main() {
  Password *head = NULL;

  create_password(&head);
  add_password(&head, "John Doe", "Secret1", 8);
  add_password(&head, "Jane Doe", "Secret2", 7);
  add_password(&head, "Peter Pan", "Neverland", 9);

  print_passwords(head);

  return 0;
}