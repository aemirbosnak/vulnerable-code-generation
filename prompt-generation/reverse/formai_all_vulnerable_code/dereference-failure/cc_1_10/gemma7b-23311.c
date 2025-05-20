//Gemma-7B DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_PASSWORD_LENGTH 255

typedef struct Password {
  char *name;
  char *password;
  struct Password *next;
} Password;

Password *create_password(char *name, char *password) {
  Password *new_password = malloc(sizeof(Password));
  new_password->name = strdup(name);
  new_password->password = strdup(password);
  new_password->next = NULL;

  return new_password;
}

void hash_password(Password *password) {
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, password->password, strlen(password->password));
  SHA256_Final(hash, &sha256);

  password->password = malloc(SHA256_DIGEST_LENGTH);
  memcpy(password->password, hash, SHA256_DIGEST_LENGTH);
}

void print_passwords(Password *passwords) {
  Password *current = passwords;

  while (current) {
    printf("%s: %s\n", current->name, current->password);
    current = current->next;
  }
}

int main() {
  Password *passwords = NULL;

  passwords = create_password("John Doe", "Secret123");
  passwords = create_password("Jane Doe", "StrongPasssword");

  hash_password(passwords);

  print_passwords(passwords);

  return 0;
}