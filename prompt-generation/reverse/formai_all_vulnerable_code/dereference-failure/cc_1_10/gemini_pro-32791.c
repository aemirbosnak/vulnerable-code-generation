//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "mysecretkey"

// Define the block size
#define BLOCK_SIZE 16

// Function to encrypt a block of data
void encrypt_block(unsigned char *block) {
  // XOR the block with the key
  for (int i = 0; i < BLOCK_SIZE; i++) {
    block[i] ^= KEY[i % strlen(KEY)];
  }
}

// Function to decrypt a block of data
void decrypt_block(unsigned char *block) {
  // XOR the block with the key
  for (int i = 0; i < BLOCK_SIZE; i++) {
    block[i] ^= KEY[i % strlen(KEY)];
  }
}

// Function to encrypt a string
char *encrypt(char *plaintext) {
  // Get the length of the plaintext
  int len = strlen(plaintext);

  // Allocate memory for the ciphertext
  char *ciphertext = malloc(len + 1);

  // Copy the plaintext into the ciphertext
  strcpy(ciphertext, plaintext);

  // Encrypt the ciphertext in blocks
  for (int i = 0; i < len; i += BLOCK_SIZE) {
    encrypt_block((unsigned char *)&ciphertext[i]);
  }

  // Return the ciphertext
  return ciphertext;
}

// Function to decrypt a string
char *decrypt(char *ciphertext) {
  // Get the length of the ciphertext
  int len = strlen(ciphertext);

  // Allocate memory for the plaintext
  char *plaintext = malloc(len + 1);

  // Copy the ciphertext into the plaintext
  strcpy(plaintext, ciphertext);

  // Decrypt the plaintext in blocks
  for (int i = 0; i < len; i += BLOCK_SIZE) {
    decrypt_block((unsigned char *)&plaintext[i]);
  }

  // Return the plaintext
  return plaintext;
}

int main() {
  // Get the plaintext from the user
  char *plaintext = "Hello, world!";

  // Encrypt the plaintext
  char *ciphertext = encrypt(plaintext);

  // Print the ciphertext
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  char *decryptedtext = decrypt(ciphertext);

  // Print the decrypted text
  printf("Decrypted text: %s\n", decryptedtext);

  // Free the memory allocated for the ciphertext and decrypted text
  free(ciphertext);
  free(decryptedtext);

  return 0;
}