//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input and output buffers
#define MAX_BUFFER_SIZE 1024

// Define the key to be used for encryption and decryption
#define KEY "my_secret_key"

// Function to encrypt a string using the XOR cipher
char* encrypt(char* input) {
  // Allocate memory for the output buffer
  char* output = malloc(MAX_BUFFER_SIZE);

  // Get the length of the input string
  int length = strlen(input);

  // Loop through each character in the input string
  for (int i = 0; i < length; i++) {
    // XOR the character with the key
    output[i] = input[i] ^ KEY[i % strlen(KEY)];
  }

  // Return the encrypted string
  return output;
}

// Function to decrypt a string using the XOR cipher
char* decrypt(char* input) {
  // Allocate memory for the output buffer
  char* output = malloc(MAX_BUFFER_SIZE);

  // Get the length of the input string
  int length = strlen(input);

  // Loop through each character in the input string
  for (int i = 0; i < length; i++) {
    // XOR the character with the key
    output[i] = input[i] ^ KEY[i % strlen(KEY)];
  }

  // Return the decrypted string
  return output;
}

// Function to print a message to the console
void print_message(char* message) {
  printf("%s\n", message);
}

// Function to get input from the console
char* get_input() {
  // Allocate memory for the input buffer
  char* input = malloc(MAX_BUFFER_SIZE);

  // Get the input from the console
  scanf("%s", input);

  // Return the input
  return input;
}

// Main function
int main() {
  // Print a welcome message
  print_message("Welcome to the Quantum Cryptography Interface!");

  // Get the input string from the user
  char* input = get_input();

  // Encrypt the input string
  char* encrypted = encrypt(input);

  // Print the encrypted string
  print_message("Encrypted string:");
  print_message(encrypted);

  // Decrypt the encrypted string
  char* decrypted = decrypt(encrypted);

  // Print the decrypted string
  print_message("Decrypted string:");
  print_message(decrypted);

  // Free the allocated memory
  free(input);
  free(encrypted);
  free(decrypted);

  return 0;
}