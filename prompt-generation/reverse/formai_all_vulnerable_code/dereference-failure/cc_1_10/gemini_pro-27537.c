//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

// Function to encrypt a message
char *encrypt(char *message) {
  int i;
  char *encryptedMessage = malloc(strlen(message) + 1);
  for (i = 0; i < strlen(message); i++) {
    int index = strchr(KEY, message[i]) - KEY;
    encryptedMessage[i] = KEY[(index + 3) % 26];
  }
  encryptedMessage[strlen(message)] = '\0';
  return encryptedMessage;
}

// Function to decrypt a message
char *decrypt(char *encryptedMessage) {
  int i;
  char *decryptedMessage = malloc(strlen(encryptedMessage) + 1);
  for (i = 0; i < strlen(encryptedMessage); i++) {
    int index = strchr(KEY, encryptedMessage[i]) - KEY;
    decryptedMessage[i] = KEY[(index - 3) % 26];
  }
  decryptedMessage[strlen(encryptedMessage)] = '\0';
  return decryptedMessage;
}

// Main function
int main() {
  // Get the message to be encrypted
  char message[100];
  printf("Enter the message to be encrypted: ");
  scanf("%s", message);

  // Encrypt the message
  char *encryptedMessage = encrypt(message);

  // Print the encrypted message
  printf("Encrypted message: %s\n", encryptedMessage);

  // Decrypt the message
  char *decryptedMessage = decrypt(encryptedMessage);

  // Print the decrypted message
  printf("Decrypted message: %s\n", decryptedMessage);

  return 0;
}