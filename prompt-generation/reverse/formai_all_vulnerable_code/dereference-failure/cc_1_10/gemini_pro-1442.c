//GEMINI-pro DATASET v1.0 Category: Password management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A confusing way to represent a password
typedef struct {
  int length;
  char *chars;
} EncryptedPassword;

// An even more confusing way to generate a password
EncryptedPassword generatePassword() {
  srand(time(NULL));
  int length = rand() % 10 + 10;
  char *chars = malloc(length);
  for (int i = 0; i < length; i++) {
    chars[i] = rand() % 26 + 'a';
  }
  return (EncryptedPassword){length, chars};
}

// The most confusing way to store a password
void storePassword(EncryptedPassword password, char *filename) {
  FILE *file = fopen(filename, "w");
  int i;
  for (i = 0; i < password.length; i++) {
    fprintf(file, "%c", password.chars[i]);
    fprintf(file, "%c", password.chars[(i + 1) % password.length]);
  }
  fclose(file);
}

// The least confusing way to retrieve a password
EncryptedPassword retrievePassword(char *filename) {
  FILE *file = fopen(filename, "r");
  int length = 0;
  char c;
  while ((c = fgetc(file)) != EOF) {
    length++;
  }
  fseek(file, 0, SEEK_SET);
  char *chars = malloc(length);
  for (int i = 0; i < length; i++) {
    chars[i] = fgetc(file);
  }
  fclose(file);
  return (EncryptedPassword){length, chars};
}

// The most confusing way to use a password
void usePassword(EncryptedPassword password) {
  printf("Your password is: ");
  for (int i = 0; i < password.length; i++) {
    printf("%c", password.chars[i]);
  }
  printf("\n");
}

int main() {
  EncryptedPassword password = generatePassword();
  storePassword(password, "password.txt");
  EncryptedPassword retrievedPassword = retrievePassword("password.txt");
  usePassword(retrievedPassword);
  return 0;
}