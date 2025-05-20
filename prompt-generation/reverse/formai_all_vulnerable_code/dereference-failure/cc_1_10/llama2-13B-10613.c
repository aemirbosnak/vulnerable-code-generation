//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16

// Custom encryption function
void encrypt(const uint8_t *plaintext, uint8_t *ciphertext, size_t length, const uint8_t *key) {
  size_t i, j;
  uint8_t temp;

  for (i = 0; i < length; i += BLOCK_SIZE) {
    // Encrypt block of plaintext
    for (j = 0; j < BLOCK_SIZE; j++) {
      temp = plaintext[i + j];
      if (temp >= 'A' && temp <= 'Z') {
        temp += 'a' - 'A'; // Convert to lowercase
      }
      ciphertext[i + j] = (temp + key[j]) % 26; // Encrypt using key
    }
  }
}

int main(int argc, char **argv) {
  // Check command line arguments
  if (argc != 3) {
    printf("Usage: %s <plaintext_file> <key_file>\n", argv[0]);
    return 1;
  }

  // Open plaintext file
  FILE *plaintext_file = fopen(argv[1], "rb");
  if (!plaintext_file) {
    perror("Error opening plaintext file");
    return 2;
  }

  // Open key file
  FILE *key_file = fopen(argv[2], "rb");
  if (!key_file) {
    perror("Error opening key file");
    fclose(plaintext_file);
    return 2;
  }

  // Read plaintext file
  size_t plaintext_length = ftell(plaintext_file);
  uint8_t *plaintext = malloc(plaintext_length);
  if (!plaintext) {
    perror("Error allocating memory for plaintext");
    fclose(plaintext_file);
    fclose(key_file);
    return 3;
  }
  rewind(plaintext_file);
  read(plaintext_file, plaintext, plaintext_length);

  // Read key file
  size_t key_length = ftell(key_file);
  uint8_t *key = malloc(key_length);
  if (!key) {
    perror("Error allocating memory for key");
    free(plaintext);
    fclose(plaintext_file);
    fclose(key_file);
    return 3;
  }
  rewind(key_file);
  read(key_file, key, key_length);

  // Encrypt plaintext
  uint8_t *ciphertext = malloc(plaintext_length);
  if (!ciphertext) {
    perror("Error allocating memory for ciphertext");
    free(plaintext);
    free(key);
    fclose(plaintext_file);
    fclose(key_file);
    return 3;
  }
  encrypt(plaintext, ciphertext, plaintext_length, key);

  // Save encrypted file
  FILE *encrypted_file = fopen(argv[1] + 5, "wb"); // Append "encrypted" to plaintext file name
  if (!encrypted_file) {
    perror("Error opening encrypted file");
    free(ciphertext);
    free(plaintext);
    free(key);
    fclose(plaintext_file);
    fclose(key_file);
    return 4;
  }
  write(encrypted_file, ciphertext, plaintext_length);

  free(ciphertext);
  free(plaintext);
  free(key);

  return 0;
}