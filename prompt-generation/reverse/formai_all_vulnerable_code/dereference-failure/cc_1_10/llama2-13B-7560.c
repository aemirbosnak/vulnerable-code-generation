//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 10
#define MESSAGE_SIZE 256

// Function to generate a random key
void generate_key() {
  int i, j;
  char key[KEY_SIZE];

  for (i = 0; i < KEY_SIZE; i++) {
    key[i] = 'a' + (rand() % 26);
  }

  printf("Generated key: %s\n", key);
}

// Function to encrypt a message
void encrypt_message(char *message, char *key) {
  int i, j, k;
  char encrypted[MESSAGE_SIZE];

  // Loop through each character of the message
  for (i = 0; i < strlen(message); i++) {
    // Calculate the corresponding position in the key
    j = (i + rand() % strlen(key)) % strlen(key);

    // XOR the message character with the key character at position j
    encrypted[i] = message[i] ^ key[j];
  }

  // Print the encrypted message
  printf("Encrypted message: %s\n", encrypted);
}

int main() {
  char message[] = "Hello, world!";
  char key[KEY_SIZE];

  // Generate a random key
  generate_key();

  // Encrypt the message
  encrypt_message(message, key);

  return 0;
}