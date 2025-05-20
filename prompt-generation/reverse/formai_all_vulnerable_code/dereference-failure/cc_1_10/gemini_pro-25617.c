//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int key;
char *ciphertext;
char *plaintext;

// Function to generate a random key
int generateKey() {
  return rand() % 100;
}

// Function to encrypt a message using a key
char *encrypt(char *message) {
  int i;
  for (i = 0; message[i] != '\0'; i++) {
    message[i] = (message[i] + key) % 128;
  }
  return message;
}

// Function to decrypt a message using a key
char *decrypt(char *message) {
  int i;
  for (i = 0; message[i] != '\0'; i++) {
    message[i] = (message[i] - key) % 128;
  }
  return message;
}

// Function to print a message
void printMessage(char *message) {
  printf("%s\n", message);
}

// Main function
int main() {
  // Generate a random key
  key = generateKey();

  // Get the message to be encrypted
  printf("Enter the message to be encrypted: ");
  plaintext = malloc(100);
  scanf("%s", plaintext);

  // Encrypt the message
  ciphertext = encrypt(plaintext);

  // Print the ciphertext
  printf("The ciphertext is: %s\n", ciphertext);

  // Decrypt the ciphertext
  plaintext = decrypt(ciphertext);

  // Print the plaintext
  printf("The plaintext is: %s\n", plaintext);

  // Free the allocated memory
  free(plaintext);
  free(ciphertext);

  return 0;
}