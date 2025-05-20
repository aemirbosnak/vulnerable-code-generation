//Gemma-7B DATASET v1.0 Category: Password management ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char *name;
  char *password;
  struct Password *next;
} Password;

void addPassword(Password **head) {
  Password *newPass = malloc(sizeof(Password));
  newPass->name = malloc(20);
  newPass->password = malloc(20);
  newPass->next = NULL;

  printf("Enter name: ");
  scanf("%s", newPass->name);

  printf("Enter password: ");
  scanf("%s", newPass->password);

  if (*head == NULL) {
    *head = newPass;
  } else {
    ((*head)->next = newPass);
    *head = newPass;
  }
}

void displayPasswords(Password *head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Password: %s\n", head->password);
    printf("\n");
    head = head->next;
  }
}

int main() {
  Password *passwords = NULL;

  while (1) {
    int choice;

    printf("1. Add Password\n");
    printf("2. Display Passwords\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addPassword(&passwords);
        break;
      case 2:
        displayPasswords(passwords);
        break;
      default:
        exit(0);
    }
  }

  return 0;
}