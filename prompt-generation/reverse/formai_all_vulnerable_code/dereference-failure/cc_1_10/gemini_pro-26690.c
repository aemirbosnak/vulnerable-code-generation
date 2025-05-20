//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()"

// Define the encryption function
char *encrypt(char *plaintext, char *key) {
  int keylen = strlen(key);
  int plaintextlen = strlen(plaintext);
  char *ciphertext = malloc(plaintextlen + 1);
  for (int i = 0; i < plaintextlen; i++) {
    ciphertext[i] = plaintext[i] ^ key[i % keylen];
  }
  ciphertext[plaintextlen] = '\0';
  return ciphertext;
}

// Define the decryption function
char *decrypt(char *ciphertext, char *key) {
  int keylen = strlen(key);
  int ciphertextlen = strlen(ciphertext);
  char *plaintext = malloc(ciphertextlen + 1);
  for (int i = 0; i < ciphertextlen; i++) {
    plaintext[i] = ciphertext[i] ^ key[i % keylen];
  }
  plaintext[ciphertextlen] = '\0';
  return plaintext;
}

// Get the plaintext from the user
char *get_plaintext() {
  char *plaintext;
  printf("Enter the plaintext: ");
  scanf("%s", plaintext);
  return plaintext;
}

// Get the key from the user
char *get_key() {
  char *key;
  printf("Enter the key: ");
  scanf("%s", key);
  return key;
}

// Print the ciphertext
void print_ciphertext(char *ciphertext) {
  printf("The ciphertext is: %s\n", ciphertext);
}

// Print the plaintext
void print_plaintext(char *plaintext) {
  printf("The plaintext is: %s\n", plaintext);
}

// Main function
int main() {
  // Get the plaintext from the user
  char *plaintext = get_plaintext();

  // Get the key from the user
  char *key = get_key();

  // Encrypt the plaintext
  char *ciphertext = encrypt(plaintext, key);

  // Print the ciphertext
  print_ciphertext(ciphertext);

  // Decrypt the ciphertext
  char *decrypted_plaintext = decrypt(ciphertext, key);

  // Print the plaintext
  print_plaintext(decrypted_plaintext);

  // Free the allocated memory
  free(plaintext);
  free(key);
  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}