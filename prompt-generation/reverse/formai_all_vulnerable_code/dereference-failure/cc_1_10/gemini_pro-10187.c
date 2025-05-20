//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our jolly key - we'll use this to encrypt our message
const char *key = "H@ppY-E-n_cRypTiOn";

// Function to encrypt a given message using a key
char *encrypt(char *message) {
  // Calculate the length of the message and create a new buffer for the encrypted message
  size_t message_length = strlen(message);
  char *encrypted_message = malloc(message_length + 1);

  // Initialize the index for both the message and the key
  int message_index = 0, key_index = 0;

  // Loop through the message, character by character
  while (message_index < message_length) {
    // Get the current character from the message
    char character = message[message_index];

    // XOR the character with the current character from the key
    character ^= key[key_index];

    // Store the encrypted character in the encrypted message
    encrypted_message[message_index] = character;

    // Increment the indices for both the message and the key
    message_index++;
    key_index = (key_index + 1) % strlen(key);
  }

  // Terminate the encrypted message with a null character
  encrypted_message[message_length] = '\0';

  // Return the encrypted message
  return encrypted_message;
}

// Function to decrypt a given encrypted message using a key
char *decrypt(char *encrypted_message) {
  // Calculate the length of the encrypted message and create a new buffer for the decrypted message
  size_t encrypted_message_length = strlen(encrypted_message);
  char *decrypted_message = malloc(encrypted_message_length + 1);

  // Initialize the index for both the encrypted message and the key
  int encrypted_message_index = 0, key_index = 0;

  // Loop through the encrypted message, character by character
  while (encrypted_message_index < encrypted_message_length) {
    // Get the current character from the encrypted message
    char character = encrypted_message[encrypted_message_index];

    // XOR the character with the current character from the key
    character ^= key[key_index];

    // Store the decrypted character in the decrypted message
    decrypted_message[encrypted_message_index] = character;

    // Increment the indices for both the encrypted message and the key
    encrypted_message_index++;
    key_index = (key_index + 1) % strlen(key);
  }

  // Terminate the decrypted message with a null character
  decrypted_message[encrypted_message_length] = '\0';

  // Return the decrypted message
  return decrypted_message;
}

// Let's sing a happy tune and play with our encryption!
int main() {
  // Our playful little message that we want to keep secret
  char *message = "Let's encrypt the world with a smile!";

  // Encrypting our message with our magical key
  char *encrypted_message = encrypt(message);

  // Printing our encrypted message - now it's a riddle wrapped in an enigma!
  printf("Encrypted Message:\n%s\n\n", encrypted_message);

  // Decrypting the encrypted message to reveal our original message
  char *decrypted_message = decrypt(encrypted_message);

  // Printing the decrypted message - ta-da, our message is back!
  printf("Decrypted Message:\n%s\n", decrypted_message);

  // Ah, the joy of encryption! We encrypted and decrypted our message with ease.
  printf("\nEncryption and decryption - a piece of cake, or should we say, a piece of encrypted cake?");

  // Freeing the dynamically allocated memory
  free(encrypted_message);
  free(decrypted_message);

  return 0;
}