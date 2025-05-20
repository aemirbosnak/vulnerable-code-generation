//FormAI DATASET v1.0 Category: Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 16
#define KEY_SIZE 32
#define BLOCK_SIZE 128

typedef unsigned char byte;

void xor_key(byte *block, byte *key) {
  int i;
  for (i = 0; i < CHUNK_SIZE; i++) {
    block[i] ^= key[i];
  }
}

void encrypt(byte *input, byte *output, byte *key) {
  byte block[CHUNK_SIZE];
  int i, j;
  for (i = 0; i < BLOCK_SIZE; i += CHUNK_SIZE) {
    memcpy(block, input + i, CHUNK_SIZE);
    xor_key(block, key);
    for (j = 0; j < CHUNK_SIZE; j++) {
      output[i + j] = block[j] ^ key[j];
    }
    memcpy(key, block, CHUNK_SIZE);
  }
}

void decrypt(byte *input, byte *output, byte *key) {
  byte block[CHUNK_SIZE];
  int i, j;
  for (i = 0; i < BLOCK_SIZE; i += CHUNK_SIZE) {
    memcpy(block, input + i, CHUNK_SIZE);
    for (j = 0; j < CHUNK_SIZE; j++) {
      block[j] ^= key[j];
    }
    memcpy(output + i, block, CHUNK_SIZE);
    memcpy(key, input + i, CHUNK_SIZE);
  }
}

int main(int argc, char **argv) {
  byte input[BLOCK_SIZE] = "Hello, world!!!"; // Input message
  byte output[BLOCK_SIZE] = {0}; // Output buffer
  byte key[KEY_SIZE] = {0}; // Encryption key
  int i;

  if (argc != 2) {
    printf("Usage: %s [key]\n", argv[0]);
    return 1;
  }

  strncpy((char *)key, argv[1], KEY_SIZE);

  // Print input message
  printf("Input:\n");
  for (i = 0; i < BLOCK_SIZE; i++) {
    printf("%02x ", input[i]);
    if ((i + 1) % CHUNK_SIZE == 0) {
      printf("\n");
    }
  }
  printf("\n");

  // Encrypt message
  encrypt(input, output, key);

  // Print encrypted message
  printf("Encrypted:\n");
  for (i = 0; i < BLOCK_SIZE; i++) {
    printf("%02x ", output[i]);
    if ((i + 1) % CHUNK_SIZE == 0) {
      printf("\n");
    }
  }
  printf("\n");

  // Decrypt message
  decrypt(output, input, key);

  // Print decrypted message
  printf("Decrypted:\n");
  for (i = 0; i < BLOCK_SIZE; i++) {
    printf("%02x ", input[i]);
    if ((i + 1) % CHUNK_SIZE == 0) {
      printf("\n");
    }
  }
  printf("\n");

  return 0;
}