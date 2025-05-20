//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alphabet used for encryption/decryption
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

// Define the key used for encryption/decryption
const char key[] = "SECRETKEY";

// Function to encrypt a character using the Caesar cipher
char encrypt_character(char c) {
  // Find the index of the character in the alphabet
  int index = strchr(alphabet, c) - alphabet;

  // Shift the index by the amount specified by the key
  index = (index + strlen(key)) % strlen(alphabet);

  // Return the encrypted character
  return alphabet[index];
}

// Function to decrypt a character using the Caesar cipher
char decrypt_character(char c) {
  // Find the index of the character in the alphabet
  int index = strchr(alphabet, c) - alphabet;

  // Shift the index by the amount specified by the key
  index = (index - strlen(key)) % strlen(alphabet);

  // Return the decrypted character
  return alphabet[index];
}

// Function to encrypt a string using the Caesar cipher
char *encrypt_string(char *s) {
  // Allocate memory for the encrypted string
  char *encrypted_string = malloc(strlen(s) + 1);

  // Encrypt each character in the string
  for (int i = 0; i < strlen(s); i++) {
    encrypted_string[i] = encrypt_character(s[i]);
  }

  // Add the null terminator to the end of the string
  encrypted_string[strlen(s)] = '\0';

  // Return the encrypted string
  return encrypted_string;
}

// Function to decrypt a string using the Caesar cipher
char *decrypt_string(char *s) {
  // Allocate memory for the decrypted string
  char *decrypted_string = malloc(strlen(s) + 1);

  // Decrypt each character in the string
  for (int i = 0; i < strlen(s); i++) {
    decrypted_string[i] = decrypt_character(s[i]);
  }

  // Add the null terminator to the end of the string
  decrypted_string[strlen(s)] = '\0';

  // Return the decrypted string
  return decrypted_string;
}

// Main function
int main() {
  // Get the string to be encrypted/decrypted from the user
  char s[100];
  printf("Enter a string to encrypt/decrypt: ");
  scanf("%s", s);

  // Encrypt the string
  char *encrypted_string = encrypt_string(s);

  // Print the encrypted string
  printf("Encrypted string: %s\n", encrypted_string);

  // Decrypt the string
  char *decrypted_string = decrypt_string(encrypted_string);

  // Print the decrypted string
  printf("Decrypted string: %s\n", decrypted_string);

  // Free the memory allocated for the encrypted and decrypted strings
  free(encrypted_string);
  free(decrypted_string);

  return 0;
}