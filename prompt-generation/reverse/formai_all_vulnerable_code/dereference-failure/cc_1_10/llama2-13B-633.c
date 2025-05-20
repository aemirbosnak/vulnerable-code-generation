//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 128

// Global variables
char *key;
char *message;
int message_len;
int key_len;

// Function to generate a random key
void generate_key() {
  key_len = (int) rand() % 100 + 1;
  key = malloc(key_len);
  for (int i = 0; i < key_len; i++) {
    key[i] = (char) rand() % 256;
  }
}

// Function to encrypt the message
void encrypt(char *message) {
  int i, j, k;
  for (i = 0; i < message_len; i++) {
    j = (int) message[i] + (int) key[i % key_len];
    k = j % 256;
    message[i] = (char) k;
  }
}

// Function to decrypt the message
void decrypt(char *message) {
  int i, j, k;
  for (i = 0; i < message_len; i++) {
    j = (int) message[i] - (int) key[i % key_len];
    k = j % 256;
    message[i] = (char) k;
  }
}

int main() {
  // Generate a random key
  generate_key();

  // Get the message from the user
  printf("Enter a message: ");
  gets(message);
  message_len = strlen(message);

  // Encrypt the message
  encrypt(message);

  // Print the encrypted message
  printf("Encrypted message: ");
  for (int i = 0; i < message_len; i++) {
    printf("%c", message[i]);
  }
  printf("\n");

  // Decrypt the message
  decrypt(message);

  // Print the decrypted message
  printf("Decrypted message: ");
  for (int i = 0; i < message_len; i++) {
    printf("%c", message[i]);
  }
  printf("\n");

  return 0;
}