//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned char byte;

#define BLOCK_SIZE 16

void print_hex(byte* data, size_t size) {
  for (size_t i = 0; i < size; i++) {
    printf("%02x", data[i]);
  }
}

void print_block(byte* data) {
  for (size_t i = 0; i < BLOCK_SIZE; i++) {
    printf("%02x ", data[i]);
  }
}

void xor_block(byte* block1, byte* block2, byte* result) {
  for (size_t i = 0; i < BLOCK_SIZE; i++) {
    result[i] = block1[i] ^ block2[i];
  }
}

bool equal_blocks(byte* block1, byte* block2) {
  for (size_t i = 0; i < BLOCK_SIZE; i++) {
    if (block1[i] != block2[i]) {
      return false;
    }
  }
  return true;
}

void generate_key(byte* key, size_t key_size) {
  byte* buffer = malloc(key_size);
  FILE* urandom = fopen("/dev/urandom", "r");
  fread(buffer, 1, key_size, urandom);
  fclose(urandom);

  memcpy(key, buffer, key_size);
  free(buffer);
}

void aes_encrypt_block(byte* block, byte* key) {
  // AES encryption implementation
  printf("AES encrypting block: ");
  print_block(block);
  printf("\nUsing key: ");
  print_hex(key, BLOCK_SIZE);
  printf("\n");
}

void aes_decrypt_block(byte* block, byte* key) {
  // AES decryption implementation
  printf("AES decrypting block: ");
  print_block(block);
  printf("\nUsing key: ");
  print_hex(key, BLOCK_SIZE);
  printf("\n");
}

void aes_cbc_encrypt(byte* data, size_t size, byte* key, byte* iv, byte* result) {
  byte* prev_block = iv;
  for (size_t i = 0; i < size; i += BLOCK_SIZE) {
    byte* block = &data[i];
    byte xored[BLOCK_SIZE];
    xor_block(block, prev_block, xored);
    aes_encrypt_block(xored, key);
    memcpy(&result[i], xored, BLOCK_SIZE);
    prev_block = &result[i];
  }
}

void aes_cbc_decrypt(byte* data, size_t size, byte* key, byte* iv, byte* result) {
  byte* prev_block = iv;
  for (size_t i = 0; i < size; i += BLOCK_SIZE) {
    byte* block = &data[i];
    byte decrypted[BLOCK_SIZE];
    aes_decrypt_block(block, key);
    xor_block(block, prev_block, decrypted);
    memcpy(&result[i], decrypted, BLOCK_SIZE);
    prev_block = block;
  }
}

int main() {
  size_t data_size = 32;
  byte data[] = "Hello world! This is a test message for encryption.";
  printf("Original message: %s\n", data);

  byte key[BLOCK_SIZE];
  generate_key(key, BLOCK_SIZE);
  printf("Key generated: ");
  print_hex(key, BLOCK_SIZE);
  printf("\n");

  byte iv[BLOCK_SIZE];
  generate_key(iv, BLOCK_SIZE);
  printf("Initialization vector generated: ");
  print_hex(iv, BLOCK_SIZE);
  printf("\n");

  byte encrypted[data_size];
  aes_cbc_encrypt(data, data_size, key, iv, encrypted);
  printf("Encrypted message: ");
  print_hex(encrypted, data_size);
  printf("\n");

  byte decrypted[data_size];
  aes_cbc_decrypt(encrypted, data_size, key, iv, decrypted);
  printf("Decrypted message: %s\n", decrypted);

  if (equal_blocks(data, decrypted)) {
    printf("Decryption successful!\n");
  } else {
    printf("Decryption failed!\n");
  }

  return 0;
}