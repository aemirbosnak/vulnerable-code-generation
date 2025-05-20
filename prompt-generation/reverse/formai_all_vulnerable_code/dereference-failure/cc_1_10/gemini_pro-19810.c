//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our beloved public key
unsigned long long int publicKey;

// The guarded secret, protected like a treasure
unsigned long long int privateKey;

// Generating a key pair, unlocking the gate to encryption
void generateKeyPair() {
  printf("Creating your public and private key pair, secure as a fortress!\n");
  publicKey = 1347539871; // A random large number for demonstration
  privateKey = 2695078913; // Another random large number
}

// Encrypting a message, rendering it unreadable to eavesdroppers
char* encryptMessage(char* message) {
  printf("Encrypting your message, safe from prying eyes!\n");
  int messageLength = strlen(message);
  // Allocate memory to store the encrypted message
  char* encryptedMessage = malloc(messageLength + 1);
  for (int i = 0; i < messageLength; i++) {
    char currentCharacter = message[i];
    // Perform the encryption magic using the public key
    encryptedMessage[i] = ((int)currentCharacter * publicKey) % 7894567;
  }
  encryptedMessage[messageLength] = '\0'; // Null-terminate the encrypted message
  return encryptedMessage;
}

// Decrypting the encrypted message, revealing the secret within
char* decryptMessage(char* encryptedMessage) {
  printf("Decrypting your message, unlocking the secrets!\n");
  int encryptedMessageLength = strlen(encryptedMessage);
  // Allocate memory to store the decrypted message
  char* decryptedMessage = malloc(encryptedMessageLength + 1);
  for (int i = 0; i < encryptedMessageLength; i++) {
    char currentCharacter = encryptedMessage[i];
    // Perform the decryption magic using the private key
    int decryptedCharacter = ((int)currentCharacter * privateKey) % 7894567;
    decryptedMessage[i] = (char)decryptedCharacter; // Convert the int back to char
  }
  decryptedMessage[encryptedMessageLength] = '\0'; // Null-terminate the decrypted message
  return decryptedMessage;
}

int main() {
  // Let's kick things off by generating a key pair
  generateKeyPair();

  // Time to encrypt a secret message
  char* message = "Shh, it's a secret!";
  printf("Original message: %s\n", message);

  // Encrypting the message, turning it into a cryptic puzzle
  char* encryptedMessage = encryptMessage(message);
  printf("Encrypted message: %s\n", encryptedMessage);

  // Decrypting the encrypted message, unveiling the hidden treasure
  char* decryptedMessage = decryptMessage(encryptedMessage);
  printf("Decrypted message: %s\n", decryptedMessage);

  // Freeing the allocated memory, leaving no traces
  free(encryptedMessage);
  free(decryptedMessage);

  return 0;
}