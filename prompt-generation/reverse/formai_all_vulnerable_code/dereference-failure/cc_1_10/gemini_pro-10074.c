//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo and Juliet style cryptography

// The key is a string of characters that is used to encrypt and decrypt the message.
// The key should be kept secret and should not be shared with anyone else.
char key[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

// The encrypt function takes a message and a key and encrypts the message using the key.
// The encrypted message is returned as a string.
char *encrypt(char *message, char *key) {
  int message_length = strlen(message);
  int key_length = strlen(key);
  char *encrypted_message = malloc(message_length + 1);

  for (int i = 0; i < message_length; i++) {
    int message_char_index = message[i] - 'a';
    int key_char_index = key[i % key_length] - 'a';
    int encrypted_char_index = (message_char_index + key_char_index) % 52;
    encrypted_message[i] = 'a' + encrypted_char_index;
  }

  encrypted_message[message_length] = '\0';
  return encrypted_message;
}

// The decrypt function takes an encrypted message and a key and decrypts the message using the key.
// The decrypted message is returned as a string.
char *decrypt(char *encrypted_message, char *key) {
  int encrypted_message_length = strlen(encrypted_message);
  int key_length = strlen(key);
  char *decrypted_message = malloc(encrypted_message_length + 1);

  for (int i = 0; i < encrypted_message_length; i++) {
    int encrypted_char_index = encrypted_message[i] - 'a';
    int key_char_index = key[i % key_length] - 'a';
    int decrypted_char_index = (encrypted_char_index - key_char_index + 52) % 52;
    decrypted_message[i] = 'a' + decrypted_char_index;
  }

  decrypted_message[encrypted_message_length] = '\0';
  return decrypted_message;
}

int main() {
  // The message to be encrypted.
  char *message = "Romeo, Romeo! wherefore art thou Romeo?";

  // Encrypt the message using the key.
  char *encrypted_message = encrypt(message, key);

  // Print the encrypted message.
  printf("Encrypted message: %s\n", encrypted_message);

  // Decrypt the encrypted message using the key.
  char *decrypted_message = decrypt(encrypted_message, key);

  // Print the decrypted message.
  printf("Decrypted message: %s\n", decrypted_message);

  return 0;
}