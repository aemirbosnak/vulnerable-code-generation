//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: Donald Knuth
// Donald Knuth's Modern Encryption Example

// Includes the necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the maximum size of the input and output strings
#define MAX_SIZE 1024

// The encryption function
char* encrypt(char* input, char* key) {
  // Initializes the output string
  char* output = (char*) malloc(MAX_SIZE);

  // Loops through the input string
  for (int i = 0; i < strlen(input); i++) {
    // XORs the input character with the key character
    output[i] = input[i] ^ key[i % strlen(key)];
  }

  // Returns the output string
  return output;
}

// The decryption function
char* decrypt(char* input, char* key) {
  // Initializes the output string
  char* output = (char*) malloc(MAX_SIZE);

  // Loops through the input string
  for (int i = 0; i < strlen(input); i++) {
    // XORs the input character with the key character
    output[i] = input[i] ^ key[i % strlen(key)];
  }

  // Returns the output string
  return output;
}

// The main function
int main() {
  // Gets the input string from the user
  char* input = (char*) malloc(MAX_SIZE);
  printf("Enter the input string: ");
  scanf("%s", input);

  // Gets the key from the user
  char* key = (char*) malloc(MAX_SIZE);
  printf("Enter the key: ");
  scanf("%s", key);

  // Encrypts the input string
  char* encrypted = encrypt(input, key);

  // Prints the encrypted string
  printf("The encrypted string is: %s\n", encrypted);

  // Decrypts the encrypted string
  char* decrypted = decrypt(encrypted, key);

  // Prints the decrypted string
  printf("The decrypted string is: %s\n", decrypted);

  // Frees the allocated memory
  free(input);
  free(key);
  free(encrypted);
  free(decrypted);

  // Returns 0 to indicate success
  return 0;
}