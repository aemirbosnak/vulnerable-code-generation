//Gemma-7B DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <openssl/sha.h>

#define MAX_PASSWORDS 1024

typedef struct Password {
  char *name;
  char *password;
  int length;
  struct Password *next;
} Password;

Password *createPassword(char *name, char *password, int length) {
  Password *newPass = malloc(sizeof(Password));
  newPass->name = strdup(name);
  newPass->password = strdup(password);
  newPass->length = length;
  newPass->next = NULL;

  return newPass;
}

void addPassword(Password **head, char *name, char *password, int length) {
  Password *newPass = createPassword(name, password, length);

  if (*head == NULL) {
    *head = newPass;
  } else {
    (*head)->next = newPass;
  }
}

void printPasswords(Password *head) {
  while (head) {
    printf("%s: %s (Length: %d)\n", head->name, head->password, head->length);
    head = head->next;
  }
}

int main() {
  Password *passwords = NULL;

  addPassword(&passwords, "John Doe", "StrongPass", 16);
  addPassword(&passwords, "Jane Doe", "SecretPass", 12);
  addPassword(&passwords, "Peter Pan", "NeverLand", 20);

  printPasswords(passwords);

  return 0;
}