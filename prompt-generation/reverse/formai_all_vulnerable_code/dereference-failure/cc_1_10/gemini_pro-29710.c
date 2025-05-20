//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 1024
#define MAX_PLAINTEXT_LENGTH 1024

char *encrypt(char *plaintext, char *key);
char *decrypt(char *ciphertext, char *key);

int main() {
  // Get the plaintext and key from the user.
  char plaintext[MAX_PLAINTEXT_LENGTH];
  char key[MAX_KEY_LENGTH];
  printf("Enter the plaintext: ");
  gets(plaintext);
  printf("Enter the key: ");
  gets(key);

  // Encrypt the plaintext.
  char *ciphertext = encrypt(plaintext, key);

  // Print the ciphertext.
  printf("ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext.
  char *decryptedText = decrypt(ciphertext, key);

  // Print the decrypted text.
  printf("decryptedText: %s\n", decryptedText);

  return 0;
}

char *encrypt(char *plaintext, char *key) {
  int plaintext_length = strlen(plaintext);
  int key_length = strlen(key);
  char *ciphertext = malloc(plaintext_length + 1);
  int i;
  for (i = 0; i < plaintext_length; i++) {
    ciphertext[i] = plaintext[i] ^ key[i % key_length];
  }
  ciphertext[plaintext_length] = '\0';
  return ciphertext;
}

char *decrypt(char *ciphertext, char *key) {
  int ciphertext_length = strlen(ciphertext);
  int key_length = strlen(key);
  char *plaintext = malloc(ciphertext_length + 1);
  int i;
  for (i = 0; i < ciphertext_length; i++) {
    plaintext[i] = ciphertext[i] ^ key[i % key_length];
  }
  plaintext[ciphertext_length] = '\0';
  return plaintext;
}