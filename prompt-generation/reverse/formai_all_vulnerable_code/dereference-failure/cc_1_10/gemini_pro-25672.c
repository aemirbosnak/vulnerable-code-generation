//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message using a key
char *encrypt(char *message, char *key) {
  int message_length = strlen(message);
  int key_length = strlen(key);
  char *encrypted_message = malloc(message_length + 1);

  for (int i = 0; i < message_length; i++) {
    encrypted_message[i] = message[i] ^ key[i % key_length];
  }

  encrypted_message[message_length] = '\0';

  return encrypted_message;
}

// Function to decrypt a message using a key
char *decrypt(char *encrypted_message, char *key) {
  int encrypted_message_length = strlen(encrypted_message);
  int key_length = strlen(key);
  char *decrypted_message = malloc(encrypted_message_length + 1);

  for (int i = 0; i < encrypted_message_length; i++) {
    decrypted_message[i] = encrypted_message[i] ^ key[i % key_length];
  }

  decrypted_message[encrypted_message_length] = '\0';

  return decrypted_message;
}

int main() {
  char *message = "This is a secret message.";
  char *key = "supersecretkey";
  char *encrypted_message;
  char *decrypted_message;

  // Encrypt the message
  encrypted_message = encrypt(message, key);

  // Print the encrypted message
  printf("Encrypted message: %s\n", encrypted_message);

  // Decrypt the message
  decrypted_message = decrypt(encrypted_message, key);

  // Print the decrypted message
  printf("Decrypted message: %s\n", decrypted_message);

  free(encrypted_message);
  free(decrypted_message);

  return 0;
}