//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define KEY_SIZE 16

void encrypt(char* plaintext, char* ciphertext, char* key) {
  int i, j, k;
  char temp;

  for (i = 0; i < KEY_SIZE; i++) {
    for (j = i + 1; j < KEY_SIZE; j++) {
      if (key[i] > key[j]) {
        temp = key[i];
        key[i] = key[j];
        key[j] = temp;
      }
    }
  }

  for (i = 0; i < KEY_SIZE; i++) {
    for (j = 0; j < KEY_SIZE - i - 1; j++) {
      if (key[j] == key[j + 1]) {
        for (k = j + 2; k < KEY_SIZE; k++) {
          if (key[j] != key[k]) {
            temp = key[j + 1];
            key[j + 1] = key[k];
            key[k] = temp;
            break;
          }
        }
      }
    }
  }

  for (i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = plaintext[i] ^ key[i % KEY_SIZE];
  }
}

void decrypt(char* ciphertext, char* plaintext, char* key) {
  int i, j, k;
  char temp;

  for (i = 0; i < KEY_SIZE; i++) {
    for (j = i + 1; j < KEY_SIZE; j++) {
      if (key[i] > key[j]) {
        temp = key[i];
        key[i] = key[j];
        key[j] = temp;
      }
    }
  }

  for (i = 0; i < KEY_SIZE; i++) {
    for (j = 0; j < KEY_SIZE - i - 1; j++) {
      if (key[j] == key[j + 1]) {
        for (k = j + 2; k < KEY_SIZE; k++) {
          if (key[j] != key[k]) {
            temp = key[j + 1];
            key[j + 1] = key[k];
            key[k] = temp;
            break;
          }
        }
      }
    }
  }

  for (i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] = ciphertext[i] ^ key[i % KEY_SIZE];
  }
}

int main() {
  char plaintext[] = "This is a secret message.";
  char ciphertext[strlen(plaintext)];
  char key[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  encrypt(plaintext, ciphertext, key);
  printf("Ciphertext: %s\n", ciphertext);

  decrypt(ciphertext, plaintext, key);
  printf("Plaintext: %s\n", plaintext);

  return 0;
}