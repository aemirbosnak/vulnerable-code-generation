//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random key
char *generateKey(int length) {
  char *key = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    key[i] = rand() % 26 + 'a';
  }
  key[length] = '\0';
  return key;
}

// Function to encrypt a message
char *encryptMessage(char *message, char *key) {
  int messageLength = strlen(message);
  char *encryptedMessage = malloc(messageLength + 1);
  for (int i = 0; i < messageLength; i++) {
    encryptedMessage[i] = (message[i] + key[i]) % 26 + 'a';
  }
  encryptedMessage[messageLength] = '\0';
  return encryptedMessage;
}

// Function to decrypt a message
char *decryptMessage(char *encryptedMessage, char *key) {
  int messageLength = strlen(encryptedMessage);
  char *decryptedMessage = malloc(messageLength + 1);
  for (int i = 0; i < messageLength; i++) {
    decryptedMessage[i] = (encryptedMessage[i] - key[i] + 26) % 26 + 'a';
  }
  decryptedMessage[messageLength] = '\0';
  return decryptedMessage;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random key
  int keyLength = 10;
  char *key = generateKey(keyLength);

  // Get the message from the user
  char message[100];
  printf("Enter a message to encrypt: ");
  scanf("%s", message);

  // Encrypt the message
  char *encryptedMessage = encryptMessage(message, key);

  // Print the encrypted message
  printf("Encrypted message: %s\n", encryptedMessage);

  // Decrypt the message
  char *decryptedMessage = decryptMessage(encryptedMessage, key);

  // Print the decrypted message
  printf("Decrypted message: %s\n", decryptedMessage);

  // Free the allocated memory
  free(key);
  free(encryptedMessage);
  free(decryptedMessage);

  return 0;
}