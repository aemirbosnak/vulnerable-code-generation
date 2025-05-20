//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16

// Function to generate a random key
void generate_key(char* key) {
  int i;
  for (i = 0; i < KEY_SIZE; i++) {
    key[i] = rand() % 26 + 'A';
  }
}

// Function to encrypt a message using the key
void encrypt(char* message, char* key) {
  int i;
  for (i = 0; message[i]!= '\0'; i++) {
    if (isupper(message[i])) {
      message[i] = 'A' + (message[i] - 'A' + key[i % KEY_SIZE]) % 26;
    } else if (islower(message[i])) {
      message[i] = 'a' + (message[i] - 'a' + key[i % KEY_SIZE]) % 26;
    }
  }
}

// Function to decrypt an encrypted message using the key
void decrypt(char* encrypted_message, char* key) {
  int i;
  for (i = 0; encrypted_message[i]!= '\0'; i++) {
    if (isupper(encrypted_message[i])) {
      encrypted_message[i] = 'A' + (encrypted_message[i] - 'A' - key[i % KEY_SIZE] + 26) % 26;
    } else if (islower(encrypted_message[i])) {
      encrypted_message[i] = 'a' + (encrypted_message[i] - 'a' - key[i % KEY_SIZE] + 26) % 26;
    }
  }
}

int main() {
  char message[100];
  char key[KEY_SIZE];

  // Get message from user
  printf("Enter a message to encrypt: ");
  fgets(message, 100, stdin);

  // Generate a random key
  generate_key(key);

  // Encrypt the message using the key
  encrypt(message, key);

  // Encrypt the key itself
  encrypt(key, key);

  // Print the encrypted message and key
  printf("Encrypted message: %s\n", message);
  printf("Encrypted key: %s\n", key);

  // Decrypt the message using the key
  decrypt(message, key);

  // Decrypt the key itself
  decrypt(key, key);

  // Print the decrypted message and key
  printf("Decrypted message: %s\n", message);
  printf("Decrypted key: %s\n", key);

  return 0;
}