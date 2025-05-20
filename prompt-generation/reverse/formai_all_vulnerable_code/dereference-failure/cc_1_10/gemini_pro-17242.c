//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "1234567890ABCDEF"

// Function to encrypt a string
char *encrypt(char *plaintext) {
  // Get the length of the plaintext
  size_t plaintext_len = strlen(plaintext);

  // Create a buffer to store the ciphertext
  char *ciphertext = malloc(plaintext_len + 1);

  // Iterate over each character in the plaintext
  for (size_t i = 0; i < plaintext_len; i++) {
    // Get the current character from the plaintext
    char plaintext_char = plaintext[i];

    // Get the corresponding character from the key
    char key_char = KEY[i % strlen(KEY)];

    // Encrypt the character by XORing it with the key
    char ciphertext_char = plaintext_char ^ key_char;

    // Append the encrypted character to the ciphertext
    ciphertext[i] = ciphertext_char;
  }

  // Add a null terminator to the ciphertext
  ciphertext[plaintext_len] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Function to decrypt a string
char *decrypt(char *ciphertext) {
  // Get the length of the ciphertext
  size_t ciphertext_len = strlen(ciphertext);

  // Create a buffer to store the plaintext
  char *plaintext = malloc(ciphertext_len + 1);

  // Iterate over each character in the ciphertext
  for (size_t i = 0; i < ciphertext_len; i++) {
    // Get the current character from the ciphertext
    char ciphertext_char = ciphertext[i];

    // Get the corresponding character from the key
    char key_char = KEY[i % strlen(KEY)];

    // Decrypt the character by XORing it with the key
    char plaintext_char = ciphertext_char ^ key_char;

    // Append the decrypted character to the plaintext
    plaintext[i] = plaintext_char;
  }

  // Add a null terminator to the plaintext
  plaintext[ciphertext_len] = '\0';

  // Return the plaintext
  return plaintext;
}

int main() {
  // Get the plaintext from the user
  char *plaintext = malloc(100);
  printf("Enter the plaintext: ");
  scanf("%s", plaintext);

  // Encrypt the plaintext
  char *ciphertext = encrypt(plaintext);

  // Print the ciphertext
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  char *decrypted_plaintext = decrypt(ciphertext);

  // Print the decrypted plaintext
  printf("Decrypted plaintext: %s\n", decrypted_plaintext);

  // Free the allocated memory
  free(plaintext);
  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}