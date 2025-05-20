//Gemma-7B DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_KEY_LENGTH 256

typedef struct Key {
  unsigned char *key;
  int key_length;
} Key;

Key *generate_key(int length) {
  Key *key = malloc(sizeof(Key));
  key->key = malloc(length);
  key->key_length = length;

  for (int i = 0; i < length; i++) {
    key->key[i] = rand() % 256;
  }

  return key;
}

void encrypt(Key *key, char *message) {
  for (int i = 0; message[i] != '\0'; i++) {
    message[i] ^= key->key[i % key->key_length];
  }
}

void decrypt(Key *key, char *message) {
  for (int i = 0; message[i] != '\0'; i++) {
    message[i] ^= key->key[i % key->key_length];
  }
}

int main() {
  Key *key = generate_key(16);
  char message[] = "Hello, world!";

  encrypt(key, message);
  printf("%s\n", message);

  decrypt(key, message);
  printf("%s\n", message);

  free(key->key);
  free(key);

  return 0;
}