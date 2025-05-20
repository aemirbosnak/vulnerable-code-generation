//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the substitution cipher alphabet
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char cipher[] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

// Function to encrypt a message using the substitution cipher
char *encrypt(char *message) {
  char *encryptedMessage = malloc(strlen(message) + 1);
  for (int i = 0; i < strlen(message); i++) {
    char c = message[i];
    int index = strcspn(alphabet, &c);
    if (index < 0) {
      encryptedMessage[i] = c;
    } else {
      encryptedMessage[i] = cipher[index];
    }
  }
  encryptedMessage[strlen(message)] = '\0';
  return encryptedMessage;
}

// Function to decrypt a message using the substitution cipher
char *decrypt(char *message) {
  char *decryptedMessage = malloc(strlen(message) + 1);
  for (int i = 0; i < strlen(message); i++) {
    char c = message[i];
    int index = strcspn(cipher, &c);
    if (index < 0) {
      decryptedMessage[i] = c;
    } else {
      decryptedMessage[i] = alphabet[index];
    }
  }
  decryptedMessage[strlen(message)] = '\0';
  return decryptedMessage;
}

// Main function
int main() {
  char *message = "Hello, world!";

  // Encrypt the message
  char *encryptedMessage = encrypt(message);

  // Print the encrypted message
  printf("Encrypted message: %s\n", encryptedMessage);

  // Decrypt the message
  char *decryptedMessage = decrypt(encryptedMessage);

  // Print the decrypted message
  printf("Decrypted message: %s\n", decryptedMessage);

  // Free the allocated memory
  free(encryptedMessage);
  free(decryptedMessage);

  return 0;
}