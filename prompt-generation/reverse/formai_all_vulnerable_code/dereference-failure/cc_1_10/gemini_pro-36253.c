//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key to be used for encryption/decryption
#define KEY "abcdefghijklmnopqrstuvwxyz"

// Define the size of the key
#define KEY_SIZE 26

// Define the size of the buffer to be used for encryption/decryption
#define BUFFER_SIZE 1024

// Define the function to encrypt a message
char* encrypt(char* message) {
  // Allocate memory for the encrypted message
  char* encrypted_message = malloc(BUFFER_SIZE);

  // Get the length of the message
  int message_length = strlen(message);

  // Encrypt the message
  for (int i = 0; i < message_length; i++) {
    // Get the index of the character in the key
    int key_index = message[i] - 'a';

    // Encrypt the character
    encrypted_message[i] = KEY[key_index];
  }

  // Return the encrypted message
  return encrypted_message;
}

// Define the function to decrypt a message
char* decrypt(char* encrypted_message) {
  // Allocate memory for the decrypted message
  char* decrypted_message = malloc(BUFFER_SIZE);

  // Get the length of the encrypted message
  int encrypted_message_length = strlen(encrypted_message);

  // Decrypt the message
  for (int i = 0; i < encrypted_message_length; i++) {
    // Get the index of the character in the key
    int key_index = 0;
    for (int j = 0; j < KEY_SIZE; j++) {
      if (encrypted_message[i] == KEY[j]) {
        key_index = j;
        break;
      }
    }

    // Decrypt the character
    decrypted_message[i] = key_index + 'a';
  }

  // Return the decrypted message
  return decrypted_message;
}

// Define the main function
int main() {
  // Get the message to be encrypted
  char message[] = "Hello, world!";

  // Encrypt the message
  char* encrypted_message = encrypt(message);

  // Print the encrypted message
  printf("Encrypted message: %s\n", encrypted_message);

  // Decrypt the message
  char* decrypted_message = decrypt(encrypted_message);

  // Print the decrypted message
  printf("Decrypted message: %s\n", decrypted_message);

  // Free the allocated memory
  free(encrypted_message);
  free(decrypted_message);

  return 0;
}