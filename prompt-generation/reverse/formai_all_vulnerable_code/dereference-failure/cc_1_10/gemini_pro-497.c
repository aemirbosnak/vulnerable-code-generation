//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo and Juliet style encryption key
char key[] = "A rose by any other word would smell as sweet";

// Encrypt a message using the Romeo and Juliet style encryption key
char *encrypt(char *message) {
  int message_length = strlen(message);
  char *encrypted_message = malloc(message_length + 1);
  int key_length = strlen(key);
  int key_index = 0;

  for (int i = 0; i < message_length; i++) {
    encrypted_message[i] = message[i] ^ key[key_index];
    key_index = (key_index + 1) % key_length;
  }

  encrypted_message[message_length] = '\0';
  return encrypted_message;
}

// Decrypt a message using the Romeo and Juliet style encryption key
char *decrypt(char *encrypted_message) {
  int encrypted_message_length = strlen(encrypted_message);
  char *decrypted_message = malloc(encrypted_message_length + 1);
  int key_length = strlen(key);
  int key_index = 0;

  for (int i = 0; i < encrypted_message_length; i++) {
    decrypted_message[i] = encrypted_message[i] ^ key[key_index];
    key_index = (key_index + 1) % key_length;
  }

  decrypted_message[encrypted_message_length] = '\0';
  return decrypted_message;
}

int main() {
  // Message to be encrypted
  char *message = "But soft, what light through yonder window breaks?";

  // Encrypt the message
  char *encrypted_message = encrypt(message);

  // Print the encrypted message
  printf("Encrypted message: %s\n", encrypted_message);

  // Decrypt the encrypted message
  char *decrypted_message = decrypt(encrypted_message);

  // Print the decrypted message
  printf("Decrypted message: %s\n", decrypted_message);

  return 0;
}