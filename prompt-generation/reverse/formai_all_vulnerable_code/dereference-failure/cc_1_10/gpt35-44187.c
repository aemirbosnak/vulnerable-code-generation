//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

int main() {
  char key[MAX_INPUT_LENGTH];
  char text[MAX_INPUT_LENGTH];
  char encrypted[MAX_INPUT_LENGTH];
  char decrypted[MAX_INPUT_LENGTH];

  printf("Enter the key: ");
  fgets(key, MAX_INPUT_LENGTH, stdin);
  key[strcspn(key, "\n")] = '\0';

  printf("Enter the message: ");
  fgets(text, MAX_INPUT_LENGTH, stdin);
  text[strcspn(text, "\n")] = '\0';

  int key_len = strlen(key);
  int text_len = strlen(text);
  int encrypted_len, decrypted_len;

  char *key_copy = (char *) malloc(key_len + 1);
  strcpy(key_copy, key);

  char *text_copy = (char *) malloc(text_len + 1);
  strcpy(text_copy, text);

  char *encrypted_copy = (char *) malloc(text_len + 1);
  char *decrypted_copy = (char *) malloc(text_len + 1);

  for (int i = 0, j = 0; i < text_len; ++i, j = (j + 1) % key_len) {
    encrypted_copy[i] = text_copy[i] ^ key_copy[j];
  }
  encrypted_copy[text_len] = '\0';

  printf("Encrypted message: %s\n", encrypted_copy);

  for (int i = 0, j = 0; i < text_len; ++i, j = (j + 1) % key_len) {
    decrypted_copy[i] = encrypted_copy[i] ^ key_copy[j];
  }
  decrypted_copy[text_len] = '\0';

  printf("Decrypted message: %s\n", decrypted_copy);

  free(key_copy);
  free(text_copy);
  free(encrypted_copy);
  free(decrypted_copy);

  return 0;
}