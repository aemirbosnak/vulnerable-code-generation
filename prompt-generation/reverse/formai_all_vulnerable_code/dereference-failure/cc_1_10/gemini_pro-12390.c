//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a visionary encryption algorithm
char *encrypt(char *plaintext) {
  // Generate a random key for the encryption
  srand(time(NULL));
  int key = rand() % 256;

  // Create a ciphertext to store the encrypted data
  char *ciphertext = malloc(strlen(plaintext) + 1);

  // Encrypt each character in the plaintext using the key
  for (int i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = plaintext[i] ^ key;
  }

  // Add a null-terminator to the end of the ciphertext
  ciphertext[strlen(plaintext)] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Define a visionary decryption algorithm
char *decrypt(char *ciphertext, int key) {
  // Create a plaintext to store the decrypted data
  char *plaintext = malloc(strlen(ciphertext) + 1);

  // Decrypt each character in the ciphertext using the key
  for (int i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] = ciphertext[i] ^ key;
  }

  // Add a null-terminator to the end of the plaintext
  plaintext[strlen(ciphertext)] = '\0';

  // Return the plaintext
  return plaintext;
}

// Main function
int main() {
  // Get the plaintext from the user
  char *plaintext = malloc(1024);
  printf("Enter the plaintext: ");
  fgets(plaintext, 1024, stdin);

  // Encrypt the plaintext using the visionary encryption algorithm
  char *ciphertext = encrypt(plaintext);

  // Print the ciphertext
  printf("Ciphertext: %s", ciphertext);

  // Decrypt the ciphertext using the visionary decryption algorithm
  char *decryptedtext = decrypt(ciphertext, 15);

  // Print the decrypted text
  printf("Plaintext: %s", decryptedtext);

  // Free the allocated memory
  free(plaintext);
  free(ciphertext);
  free(decryptedtext);

  return 0;
}