//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "SuperSecretKey"

// Define the encryption function
char *encrypt(char *plaintext) {
  // Allocate memory for the ciphertext
  char *ciphertext = malloc(strlen(plaintext) + 1);

  // Encrypt the plaintext using XOR encryption
  for (int i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = plaintext[i] ^ KEY[i % strlen(KEY)];
  }

  // Terminate the ciphertext string
  ciphertext[strlen(plaintext)] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Define the decryption function
char *decrypt(char *ciphertext) {
  // Allocate memory for the plaintext
  char *plaintext = malloc(strlen(ciphertext) + 1);

  // Decrypt the ciphertext using XOR encryption
  for (int i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] = ciphertext[i] ^ KEY[i % strlen(KEY)];
  }

  // Terminate the plaintext string
  plaintext[strlen(ciphertext)] = '\0';

  // Return the plaintext
  return plaintext;
}

// Main function
int main() {
  // Get the plaintext from the user
  char plaintext[100];
  printf("Enter the plaintext: ");
  gets(plaintext);

  // Encrypt the plaintext
  char *ciphertext = encrypt(plaintext);

  // Print the ciphertext
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  char *decrypted_plaintext = decrypt(ciphertext);

  // Print the decrypted plaintext
  printf("Decrypted plaintext: %s\n", decrypted_plaintext);

  // Free the allocated memory
  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}