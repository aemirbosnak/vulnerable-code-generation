//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

unsigned char key[] = {
  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
  0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
};

void print_hex(unsigned char *data, size_t size) {
  for (size_t i = 0; i < size; i++) {
    printf("%02x", data[i]);
  }
  printf("\n");
}

void xor(unsigned char *a, unsigned char *b, size_t size) {
  for (size_t i = 0; i < size; i++) {
    a[i] ^= b[i];
  }
}

void encrypt_block(unsigned char *block) {
  // First round
  xor(block, key, BLOCK_SIZE);

  // Subsequent rounds
  for (int i = 1; i < 10; i++) {
    // Shift the key to the left by one bit
    for (int j = 0; j < BLOCK_SIZE - 1; j++) {
      key[j] = (key[j] << 1) | (key[j + 1] >> 7);
    }
    key[BLOCK_SIZE - 1] = (key[BLOCK_SIZE - 1] << 1);

    // XOR the block with the shifted key
    xor(block, key, BLOCK_SIZE);
  }
}

void decrypt_block(unsigned char *block) {
  // Reverse the order of the rounds
  for (int i = 9; i >= 1; i--) {
    // Shift the key to the right by one bit
    for (int j = BLOCK_SIZE - 1; j > 0; j--) {
      key[j] = (key[j] >> 1) | (key[j - 1] << 7);
    }
    key[0] = (key[0] >> 1);

    // XOR the block with the shifted key
    xor(block, key, BLOCK_SIZE);
  }

  // First round
  xor(block, key, BLOCK_SIZE);
}

int main() {
  unsigned char plaintext[] = "Hello, world!";
  size_t plaintext_size = strlen(plaintext);

  // Pad the plaintext to a multiple of the block size
  size_t padded_plaintext_size = plaintext_size + (BLOCK_SIZE - (plaintext_size % BLOCK_SIZE));
  unsigned char *padded_plaintext = malloc(padded_plaintext_size);
  memcpy(padded_plaintext, plaintext, plaintext_size);
  memset(padded_plaintext + plaintext_size, ' ', padded_plaintext_size - plaintext_size);

  // Create an output buffer
  unsigned char *ciphertext = malloc(padded_plaintext_size);

  // Encrypt the plaintext
  for (size_t i = 0; i < padded_plaintext_size; i += BLOCK_SIZE) {
    encrypt_block(padded_plaintext + i);
  }

  // Print the ciphertext
  printf("Ciphertext: ");
  print_hex(ciphertext, padded_plaintext_size);

  // Decrypt the ciphertext
  for (size_t i = 0; i < padded_plaintext_size; i += BLOCK_SIZE) {
    decrypt_block(ciphertext + i);
  }

  // Remove the padding
  ciphertext[plaintext_size] = '\0';

  // Print the plaintext
  printf("Plaintext: %s\n", ciphertext);

  // Free the buffers
  free(padded_plaintext);
  free(ciphertext);

  return 0;
}