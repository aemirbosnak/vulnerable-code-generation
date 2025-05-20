//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define the encryption key.
#define KEY 0x12345678

// Define the block size.
#define BLOCK_SIZE 8

// Define the number of rounds.
#define ROUNDS 10

// Function to encrypt a block of data.
void encrypt_block(uint8_t *block) {
  for (int i = 0; i < ROUNDS; i++) {
    // XOR the block with the key.
    for (int j = 0; j < BLOCK_SIZE; j++) {
      block[j] ^= KEY;
    }

    // Rotate the block left by one bit.
    uint8_t temp = block[0];
    for (int j = 0; j < BLOCK_SIZE - 1; j++) {
      block[j] = block[j + 1];
    }
    block[BLOCK_SIZE - 1] = temp;
  }
}

// Function to decrypt a block of data.
void decrypt_block(uint8_t *block) {
  for (int i = 0; i < ROUNDS; i++) {
    // Rotate the block right by one bit.
    uint8_t temp = block[BLOCK_SIZE - 1];
    for (int j = BLOCK_SIZE - 1; j > 0; j--) {
      block[j] = block[j - 1];
    }
    block[0] = temp;

    // XOR the block with the key.
    for (int j = 0; j < BLOCK_SIZE; j++) {
      block[j] ^= KEY;
    }
  }
}

// Function to encrypt a file.
int encrypt_file(const char *input_file, const char *output_file) {
  // Open the input file.
  FILE *input = fopen(input_file, "rb");
  if (input == NULL) {
    return -1;
  }

  // Open the output file.
  FILE *output = fopen(output_file, "wb");
  if (output == NULL) {
    fclose(input);
    return -1;
  }

  // Read the input file in blocks.
  uint8_t block[BLOCK_SIZE];
  size_t bytes_read;
  while ((bytes_read = fread(block, 1, BLOCK_SIZE, input)) > 0) {
    // Encrypt the block.
    encrypt_block(block);

    // Write the encrypted block to the output file.
    fwrite(block, 1, BLOCK_SIZE, output);
  }

  // Close the input and output files.
  fclose(input);
  fclose(output);

  return 0;
}

// Function to decrypt a file.
int decrypt_file(const char *input_file, const char *output_file) {
  // Open the input file.
  FILE *input = fopen(input_file, "rb");
  if (input == NULL) {
    return -1;
  }

  // Open the output file.
  FILE *output = fopen(output_file, "wb");
  if (output == NULL) {
    fclose(input);
    return -1;
  }

  // Read the input file in blocks.
  uint8_t block[BLOCK_SIZE];
  size_t bytes_read;
  while ((bytes_read = fread(block, 1, BLOCK_SIZE, input)) > 0) {
    // Decrypt the block.
    decrypt_block(block);

    // Write the decrypted block to the output file.
    fwrite(block, 1, BLOCK_SIZE, output);
  }

  // Close the input and output files.
  fclose(input);
  fclose(output);

  return 0;
}

// Function to print the usage information.
void usage() {
  printf("Usage: file_encryptor encrypt <input_file> <output_file>\n");
  printf("       file_encryptor decrypt <input_file> <output_file>\n");
}

// Main function.
int main(int argc, char **argv) {
  if (argc < 4) {
    usage();
    return -1;
  }

  if (strcmp(argv[1], "encrypt") == 0) {
    return encrypt_file(argv[2], argv[3]);
  } else if (strcmp(argv[1], "decrypt") == 0) {
    return decrypt_file(argv[2], argv[3]);
  } else {
    usage();
    return -1;
  }
}