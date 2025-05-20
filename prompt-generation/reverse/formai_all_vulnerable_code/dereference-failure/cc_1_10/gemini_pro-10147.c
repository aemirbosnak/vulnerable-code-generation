//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The key is a number that is used to encrypt the message.
// The higher the key, the more secure the encryption.
int key = 3;

// The function encrypt takes a message and a key and returns the encrypted message.
char *encrypt(char *message) {

  // Create a new string to hold the encrypted message.
  char *encryptedMessage = malloc(strlen(message) + 1);

  // Loop through each character in the message.
  for (int i = 0; i < strlen(message); i++) {
    // Get the ASCII value of the character.
    int asciiValue = message[i];

    // Add the key to the ASCII value.
    asciiValue += key;

    // Convert the ASCII value back to a character.
    char encryptedCharacter = asciiValue;

    // Add the encrypted character to the encrypted message.
    encryptedMessage[i] = encryptedCharacter;
  }

  // Return the encrypted message.
  return encryptedMessage;
}

// The function decrypt takes an encrypted message and a key and returns the decrypted message.
char *decrypt(char *encryptedMessage) {

  // Create a new string to hold the decrypted message.
  char *decryptedMessage = malloc(strlen(encryptedMessage) + 1);

  // Loop through each character in the encrypted message.
  for (int i = 0; i < strlen(encryptedMessage); i++) {
    // Get the ASCII value of the character.
    int asciiValue = encryptedMessage[i];

    // Subtract the key from the ASCII value.
    asciiValue -= key;

    // Convert the ASCII value back to a character.
    char decryptedCharacter = asciiValue;

    // Add the decrypted character to the decrypted message.
    decryptedMessage[i] = decryptedCharacter;
  }

  // Return the decrypted message.
  return decryptedMessage;
}

// The main function is the entry point of the program.
int main() {

  // Get the message from the user.
  char *message = "Hello, world!";

  // Encrypt the message.
  char *encryptedMessage = encrypt(message);

  // Print the encrypted message.
  printf("Encrypted message: %s\n", encryptedMessage);

  // Decrypt the encrypted message.
  char *decryptedMessage = decrypt(encryptedMessage);

  // Print the decrypted message.
  printf("Decrypted message: %s\n", decryptedMessage);

  return 0;
}