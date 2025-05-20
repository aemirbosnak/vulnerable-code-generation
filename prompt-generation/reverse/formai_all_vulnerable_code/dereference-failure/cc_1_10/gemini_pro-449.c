//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a random number
int genRand(int max) {
  return rand() % max;
}

// Function to encrypt a character
char encryptChar(char c, int key) {
  int offset = 'a' - 1;
  return (((c - offset) + key) % 26) + offset;
}

// Function to decrypt a character
char decryptChar(char c, int key) {
  int offset = 'a' - 1;
  return (((c - offset) - key) % 26) + offset;
}

// Function to encrypt a string
char* encrypt(char* str, int key) {
  char* encryptedStr = malloc(strlen(str) + 1);
  int i;
  for (i = 0; i < strlen(str); i++) {
    encryptedStr[i] = encryptChar(str[i], key);
  }
  encryptedStr[i] = '\0';
  return encryptedStr;
}

// Function to decrypt a string
char* decrypt(char* str, int key) {
  char* decryptedStr = malloc(strlen(str) + 1);
  int i;
  for (i = 0; i < strlen(str); i++) {
    decryptedStr[i] = decryptChar(str[i], key);
  }
  decryptedStr[i] = '\0';
  return decryptedStr;
}

// Main function
int main() {
  // Generate a random key
  int key = genRand(26);

  // Get the message from the user
  char* message = malloc(100);
  printf("Enter the message to encrypt: ");
  gets(message);

  // Encrypt the message
  char* encryptedMessage = encrypt(message, key);

  // Decrypt the message
  char* decryptedMessage = decrypt(encryptedMessage, key);

  // Print the encrypted and decrypted messages
  printf("Encrypted message: %s\n", encryptedMessage);
  printf("Decrypted message: %s\n", decryptedMessage);

  // Free the allocated memory
  free(message);
  free(encryptedMessage);
  free(decryptedMessage);

  return 0;
}