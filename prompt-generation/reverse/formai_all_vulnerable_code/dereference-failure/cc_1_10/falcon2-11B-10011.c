//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str) {
  char *encrypted = (char *)malloc(strlen(str) * 2 + 1);
  int i;

  for (i = 0; i < strlen(str); i++) {
    encrypted[i] = str[i];
    encrypted[i + strlen(str)] = str[i] + 3;
  }

  encrypted[strlen(str) * 2] = '\0';
  printf("Encrypted: %s\n", encrypted);

  free(encrypted);
}

void decrypt(char *str) {
  char *decrypted = (char *)malloc(strlen(str) * 2 + 1);
  int i;

  for (i = 0; i < strlen(str); i++) {
    decrypted[i] = str[i];
    decrypted[i + strlen(str)] = str[i] - 3;
  }

  decrypted[strlen(str) * 2] = '\0';
  printf("Decrypted: %s\n", decrypted);

  free(decrypted);
}

int main() {
  char *plaintext = "Hello, World!";
  char *encrypted_text = (char *)malloc(strlen(plaintext) * 2 + 1);
  char *decrypted_text = (char *)malloc(strlen(plaintext) * 2 + 1);

  encrypt(plaintext);
  decrypt(encrypted_text);

  printf("Original: %s\n", plaintext);
  printf("Encrypted: %s\n", encrypted_text);
  printf("Decrypted: %s\n", decrypted_text);

  free(encrypted_text);
  free(decrypted_text);

  return 0;
}