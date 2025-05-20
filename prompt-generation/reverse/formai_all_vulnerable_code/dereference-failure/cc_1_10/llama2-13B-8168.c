//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: surprised
// Oh my gosh, I can't believe I'm actually writing an encryption program! 😱

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define MESSAGE_SIZE 256

// Function to encrypt a message
void encrypt(char *message, char *key) {
  int i, j, k;
  char encrypted[MESSAGE_SIZE];

  // Loop through each character in the message
  for (i = 0; i < MESSAGE_SIZE; i++) {
    // XOR the character with the corresponding key character
    encrypted[i] = message[i] ^ key[i % KEY_SIZE];
  }

  // Print the encrypted message
  printf("Encrypted message: ");
  for (i = 0; i < MESSAGE_SIZE; i++) {
    printf("%c", encrypted[i]);
  }
  printf("\n");
}

// Function to decrypt an encrypted message
void decrypt(char *encrypted, char *key) {
  int i, j, k;
  char message[MESSAGE_SIZE];

  // Loop through each character in the encrypted message
  for (i = 0; i < MESSAGE_SIZE; i++) {
    // XOR the character with the corresponding key character
    message[i] = encrypted[i] ^ key[i % KEY_SIZE];
  }

  // Print the decrypted message
  printf("Decrypted message: ");
  for (i = 0; i < MESSAGE_SIZE; i++) {
    printf("%c", message[i]);
  }
  printf("\n");
}

int main() {
  char message[] = "Hello, world!";
  char key[] = "This is a secret key";

  // Encrypt the message
  encrypt(message, key);

  // Decrypt the message
  decrypt(message, key);

  return 0;
}