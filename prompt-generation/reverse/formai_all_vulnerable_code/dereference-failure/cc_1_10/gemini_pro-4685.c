//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using XOR encryption
char *xor_encrypt(char *plaintext, char *key) {
  int plaintext_len = strlen(plaintext);
  int key_len = strlen(key);
  char *ciphertext = malloc(plaintext_len + 1); // Allocate memory for ciphertext
  int i;

  for (i = 0; i < plaintext_len; i++) {
    ciphertext[i] = plaintext[i] ^ key[i % key_len]; // XOR each character of plaintext with corresponding character of key
  }

  ciphertext[plaintext_len] = '\0'; // Null-terminate the ciphertext
  return ciphertext;
}

// Function to decrypt a string encrypted using XOR encryption
char *xor_decrypt(char *ciphertext, char *key) {
  int ciphertext_len = strlen(ciphertext);
  int key_len = strlen(key);
  char *plaintext = malloc(ciphertext_len + 1); // Allocate memory for plaintext
  int i;

  for (i = 0; i < ciphertext_len; i++) {
    plaintext[i] = ciphertext[i] ^ key[i % key_len]; // XOR each character of ciphertext with corresponding character of key
  }

  plaintext[ciphertext_len] = '\0'; // Null-terminate the plaintext
  return plaintext;
}

int main() {
  char *plaintext = "Hello, world!";
  char *key = "my_secret_key";

  // Encrypt the plaintext using XOR encryption
  char *ciphertext = xor_encrypt(plaintext, key);
  printf("Encrypted ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext using XOR encryption
  char *decrypted_plaintext = xor_decrypt(ciphertext, key);
  printf("Decrypted plaintext: %s\n", decrypted_plaintext);

  // Free the allocated memory
  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}