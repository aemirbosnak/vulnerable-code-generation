//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 256

typedef unsigned char byte;

void enigma(byte *plaintext, byte *ciphertext, byte *key, int key_size) {
  int i, j;
  byte k;

  for (i = 0; i < key_size; i++) {
    k = key[i];
    for (j = 0; j < key_size; j++) {
      if (plaintext[j] == k) {
        ciphertext[j] = (plaintext[j] + 1) % key_size;
        break;
      }
    }
  }
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s plaintext ciphertext key\n", argv[0]);
    return EXIT_FAILURE;
  }

  int plaintext_size = strlen(argv[1]);
  int ciphertext_size = strlen(argv[2]);
  int key_size = strlen(argv[3]);

  if (plaintext_size != ciphertext_size || key_size > MAX_KEY_SIZE) {
    fprintf(stderr, "Invalid input\n");
    return EXIT_FAILURE;
  }

  byte *plaintext = malloc(plaintext_size);
  byte *ciphertext = malloc(ciphertext_size);
  byte *key = malloc(key_size);

  strcpy(plaintext, argv[1]);
  strcpy(ciphertext, argv[2]);
  strcpy(key, argv[3]);

  enigma(plaintext, ciphertext, key, key_size);

  printf("Plaintext: %s\n", plaintext);
  printf("Ciphertext: %s\n", ciphertext);

  free(plaintext);
  free(ciphertext);
  free(key);

  return EXIT_SUCCESS;
}