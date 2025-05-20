//GEMINI-pro DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
  char *password;
  int length;
} Password;

Password *create_password(char *password) {
  Password *new_password = malloc(sizeof(Password));
  new_password->password = strdup(password);
  new_password->length = strlen(password);
  return new_password;
}

void delete_password(Password *password) {
  free(password->password);
  free(password);
}

int main() {
  // Create an array of passwords
  Password *passwords[10];

  // Add some passwords to the array
  passwords[0] = create_password("password1");
  passwords[1] = create_password("password2");
  passwords[2] = create_password("password3");
  passwords[3] = create_password("password4");
  passwords[4] = create_password("password5");
  passwords[5] = create_password("password6");
  passwords[6] = create_password("password7");
  passwords[7] = create_password("password8");
  passwords[8] = create_password("password9");
  passwords[9] = create_password("password10");

  // Print the passwords
  for (int i = 0; i < 10; i++) {
    printf("Password %d: %s\n", i + 1, passwords[i]->password);
  }

  // Delete the passwords
  for (int i = 0; i < 10; i++) {
    delete_password(passwords[i]);
  }

  return 0;
}