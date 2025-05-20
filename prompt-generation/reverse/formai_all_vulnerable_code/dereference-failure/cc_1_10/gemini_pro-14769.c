//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key and the plaintext
char key[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char plaintext[] = "HELLOWORLD";

// Function to encrypt the plaintext using the key
char* encrypt(char* plaintext, char* key) {
  int key_len = strlen(key);
  int plaintext_len = strlen(plaintext);

  // Allocate memory for the ciphertext
  char* ciphertext = malloc(plaintext_len + 1);

  // Encrypt the plaintext
  for (int i = 0; i < plaintext_len; i++) {
    int key_index = i % key_len;
    int plaintext_char = plaintext[i];
    int key_char = key[key_index];

    // Perform the encryption
    ciphertext[i] = (plaintext_char + key_char - 'A') % 26 + 'A';
  }

  // Null-terminate the ciphertext
  ciphertext[plaintext_len] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Function to decrypt the ciphertext using the key
char* decrypt(char* ciphertext, char* key) {
  int key_len = strlen(key);
  int ciphertext_len = strlen(ciphertext);

  // Allocate memory for the plaintext
  char* plaintext = malloc(ciphertext_len + 1);

  // Decrypt the ciphertext
  for (int i = 0; i < ciphertext_len; i++) {
    int key_index = i % key_len;
    int ciphertext_char = ciphertext[i];
    int key_char = key[key_index];

    // Perform the decryption
    plaintext[i] = (ciphertext_char - key_char + 26) % 26 + 'A';
  }

  // Null-terminate the plaintext
  plaintext[ciphertext_len] = '\0';

  // Return the plaintext
  return plaintext;
}

// Main function
int main() {
  // Encrypt the plaintext
  char* ciphertext = encrypt(plaintext, key);

  // Print the ciphertext
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  char* plaintext_decrypted = decrypt(ciphertext, key);

  // Print the decrypted plaintext
  printf("Plaintext (decrypted): %s\n", plaintext_decrypted);

  // Free the allocated memory
  free(ciphertext);
  free(plaintext_decrypted);

  return 0;
}