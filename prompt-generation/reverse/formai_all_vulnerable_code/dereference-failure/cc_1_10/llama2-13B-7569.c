//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_MAX_LENGTH 20
#define SALT_LENGTH 10

// Global variables
char *passwords[5];
int passwordCount = 0;

void initPasswords() {
  passwords[0] = malloc(PASSWORD_MAX_LENGTH * sizeof(char));
  passwords[1] = malloc(PASSWORD_MAX_LENGTH * sizeof(char));
  passwords[2] = malloc(PASSWORD_MAX_LENGTH * sizeof(char));
  passwords[3] = malloc(PASSWORD_MAX_LENGTH * sizeof(char));
  passwords[4] = malloc(PASSWORD_MAX_LENGTH * sizeof(char));

  for (int i = 0; i < 5; i++) {
    char *p = passwords[i];
    *p = 0;
  }
}

void addPassword(const char *password) {
  if (passwordCount == 5) {
    printf("Error: Maximum number of passwords reached\n");
    return;
  }

  char *newPassword = malloc(PASSWORD_MAX_LENGTH * sizeof(char));
  strcpy(newPassword, password);

  for (int i = 0; i < passwordCount; i++) {
    if (strcmp(passwords[i], newPassword) == 0) {
      printf("Error: Duplicate password entered\n");
      free(newPassword);
      return;
    }
  }

  passwords[passwordCount] = newPassword;
  passwordCount++;
}

void printPasswords() {
  for (int i = 0; i < passwordCount; i++) {
    printf("%d: %s\n", i + 1, passwords[i]);
  }
}

int main() {
  srand(time(NULL));

  initPasswords();

  while (1) {
    char *password = malloc(PASSWORD_MAX_LENGTH * sizeof(char));
    printf("Enter a password (max %d characters): ", PASSWORD_MAX_LENGTH);
    fgets(password, PASSWORD_MAX_LENGTH, stdin);

    addPassword(password);

    printPasswords();

    printf("Do you want to add another password? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'n') {
      break;
    }
  }

  for (int i = 0; i < passwordCount; i++) {
    free(passwords[i]);
  }

  return 0;
}