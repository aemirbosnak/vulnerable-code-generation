//Gemma-7B DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char name[20];
  char password[20];
  struct Password* next;
} Password;

Password* createPassword(char* name, char* password) {
  Password* newPassword = (Password*)malloc(sizeof(Password));
  strcpy(newPassword->name, name);
  strcpy(newPassword->password, password);
  newPassword->next = NULL;
  return newPassword;
}

void addPassword(Password* head, char* name, char* password) {
  Password* newPassword = createPassword(name, password);
  if (head == NULL) {
    head = newPassword;
  } else {
    newPassword->next = head;
    head = newPassword;
  }
}

void searchPassword(Password* head, char* name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      printf("Password: %s\n", head->password);
      break;
    }
    head = head->next;
  }
  if (head == NULL) {
    printf("No password found for that name.\n");
  }
}

int main() {
  Password* head = NULL;
  addPassword(head, "Sir Robin", "Secret 1");
  addPassword(head, "Lady Alice", "Hidden 2");
  addPassword(head, "The Dragon", "Fire 3");

  searchPassword(head, "Sir Robin");
  searchPassword(head, "Lady Alice");

  return 0;
}