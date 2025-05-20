//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alphabet for encryption
char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function to encrypt a character using Caesar cipher
char encryptChar(char c, int shift) {
  // Find the position of the character in the alphabet
  int index = strchr(alphabet, c) - alphabet;

  // Shift the character by the given amount
  index = (index + shift) % strlen(alphabet);

  // Return the encrypted character
  return alphabet[index];
}

// Function to encrypt a string using Caesar cipher
char *encryptString(char *str, int shift) {
  // Create a buffer for the encrypted string
  char *encrypted = malloc(strlen(str) + 1);

  // Encrypt each character in the string
  for (int i = 0; i < strlen(str); i++) {
    encrypted[i] = encryptChar(str[i], shift);
  }

  // Add the null terminator to the encrypted string
  encrypted[strlen(str)] = '\0';

  // Return the encrypted string
  return encrypted;
}

// Function to decrypt a character using Caesar cipher
char decryptChar(char c, int shift) {
  // Find the position of the character in the alphabet
  int index = strchr(alphabet, c) - alphabet;

  // Shift the character by the given amount
  index = (index - shift) % strlen(alphabet);

  // Return the decrypted character
  return alphabet[index];
}

// Function to decrypt a string using Caesar cipher
char *decryptString(char *str, int shift) {
  // Create a buffer for the decrypted string
  char *decrypted = malloc(strlen(str) + 1);

  // Decrypt each character in the string
  for (int i = 0; i < strlen(str); i++) {
    decrypted[i] = decryptChar(str[i], shift);
  }

  // Add the null terminator to the decrypted string
  decrypted[strlen(str)] = '\0';

  // Return the decrypted string
  return decrypted;
}

// Main function
int main() {
  // Get the input string and shift amount from the user
  char str[100];
  int shift;
  printf("Enter the string to be encrypted: ");
  gets(str);
  printf("Enter the shift amount (1-26): ");
  scanf("%d", &shift);

  // Encrypt the string
  char *encrypted = encryptString(str, shift);

  // Print the encrypted string
  printf("Encrypted string: %s\n", encrypted);

  // Decrypt the string
  char *decrypted = decryptString(encrypted, shift);

  // Print the decrypted string
  printf("Decrypted string: %s\n", decrypted);

  // Free the allocated memory
  free(encrypted);
  free(decrypted);

  return 0;
}