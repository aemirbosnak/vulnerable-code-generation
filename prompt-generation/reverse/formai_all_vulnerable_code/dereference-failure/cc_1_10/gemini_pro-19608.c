//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the substitution cipher key
#define KEY "SECRET"

// Function to encrypt a string using the substitution cipher
char *encrypt(char *plaintext) {
  // Allocate memory for the ciphertext
  char *ciphertext = (char *)malloc(strlen(plaintext) + 1);

  // Encrypt each character in the plaintext
  for (int i = 0; i < strlen(plaintext); i++) {
    // Find the index of the character in the key
    int index = strchr(KEY, plaintext[i]) - KEY;

    // If the character is not found in the key, leave it unchanged
    if (index == -1) {
      ciphertext[i] = plaintext[i];
    }

    // Otherwise, substitute the character with the character at the corresponding index in the key
    else {
      ciphertext[i] = KEY[index];
    }
  }

  // Add the null terminator to the ciphertext
  ciphertext[strlen(plaintext)] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Function to decrypt a string using the substitution cipher
char *decrypt(char *ciphertext) {
  // Allocate memory for the plaintext
  char *plaintext = (char *)malloc(strlen(ciphertext) + 1);

  // Decrypt each character in the ciphertext
  for (int i = 0; i < strlen(ciphertext); i++) {
    // Find the index of the character in the key
    int index = strchr(KEY, ciphertext[i]) - KEY;

    // If the character is not found in the key, leave it unchanged
    if (index == -1) {
      plaintext[i] = ciphertext[i];
    }

    // Otherwise, substitute the character with the character at the corresponding index in the key
    else {
      plaintext[i] = KEY[index];
    }
  }

  // Add the null terminator to the plaintext
  plaintext[strlen(ciphertext)] = '\0';

  // Return the plaintext
  return plaintext;
}

// Main function
int main() {
  // Get the plaintext from the user
  char plaintext[100];
  printf("Enter the plaintext: ");
  scanf("%s", plaintext);

  // Encrypt the plaintext
  char *ciphertext = encrypt(plaintext);

  // Print the ciphertext
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  char *decryptedText = decrypt(ciphertext);

  // Print the decrypted text
  printf("Decrypted text: %s\n", decryptedText);

  // Free the allocated memory
  free(ciphertext);
  free(decryptedText);

  return 0;
}