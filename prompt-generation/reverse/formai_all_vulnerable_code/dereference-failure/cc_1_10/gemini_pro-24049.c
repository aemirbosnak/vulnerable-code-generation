//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our cyberpunk-themed cipher
#define H4CK3R_CYPH3R(c) ((c + 13) % 256)

// Create a function to encrypt a string
char* encrypt(char* plaintext) {
  // Allocate memory for the ciphertext
  char* ciphertext = malloc(strlen(plaintext) + 1);

  // Loop through each character in the plaintext
  for (int i = 0; plaintext[i] != '\0'; i++) {
    // Encrypt the character using our cyberpunk cipher
    ciphertext[i] = H4CK3R_CYPH3R(plaintext[i]);
  }

  // Terminate the ciphertext with a null character
  ciphertext[strlen(plaintext)] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Create a function to decrypt a string
char* decrypt(char* ciphertext) {
  // Allocate memory for the plaintext
  char* plaintext = malloc(strlen(ciphertext) + 1);

  // Loop through each character in the ciphertext
  for (int i = 0; ciphertext[i] != '\0'; i++) {
    // Decrypt the character using our cyberpunk cipher
    plaintext[i] = H4CK3R_CYPH3R(ciphertext[i] - 13);
  }

  // Terminate the plaintext with a null character
  plaintext[strlen(ciphertext)] = '\0';

  // Return the plaintext
  return plaintext;
}

// Main function
int main() {
  // Get the plaintext from the user
  printf("\nEnter your secret message, netrunner: ");
  char plaintext[1024];
  fgets(plaintext, 1024, stdin);

  // Encrypt the plaintext
  char* ciphertext = encrypt(plaintext);

  // Print the ciphertext
  printf("\nYour encrypted message, my friend: %s\n", ciphertext);

  // Decrypt the ciphertext
  char* decryptedText = decrypt(ciphertext);

  // Print the decrypted text
  printf("\nYour decrypted message, netrunner: %s\n", decryptedText);

  // Free the allocated memory
  free(ciphertext);
  free(decryptedText);

  return 0;
}