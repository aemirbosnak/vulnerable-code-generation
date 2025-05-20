//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0x1234

void encrypt(char* plaintext, char* ciphertext, int len) {
  for (int i = 0; i < len; i++) {
    ciphertext[i] = plaintext[i] ^ KEY;
  }
}

void decrypt(char* ciphertext, char* plaintext, int len) {
  for (int i = 0; i < len; i++) {
    plaintext[i] = ciphertext[i] ^ KEY;
  }
}

int main(int argc, char** argv) {
  if (argc != 4) {
    printf("Usage: %s <input file> <output file> <mode>", argv[0]);
    return 1;
  }

  char* input_file = argv[1];
  char* output_file = argv[2];
  char* mode = argv[3];

  FILE* input = fopen(input_file, "rb");
  if (input == NULL) {
    perror("Could not open input file");
    return 1;
  }

  fseek(input, 0, SEEK_END);
  long size = ftell(input);
  rewind(input);

  char* plaintext = malloc(size);
  if (plaintext == NULL) {
    perror("Could not allocate memory for plaintext");
    return 1;
  }

  fread(plaintext, 1, size, input);
  fclose(input);

  char* ciphertext = malloc(size);
  if (ciphertext == NULL) {
    perror("Could not allocate memory for ciphertext");
    return 1;
  }

  if (strcmp(mode, "encrypt") == 0) {
    encrypt(plaintext, ciphertext, size);
  } else if (strcmp(mode, "decrypt") == 0) {
    decrypt(ciphertext, plaintext, size);
  } else {
    printf("Invalid mode: %s", mode);
    return 1;
  }

  FILE* output = fopen(output_file, "wb");
  if (output == NULL) {
    perror("Could not open output file");
    return 1;
  }

  fwrite(ciphertext, 1, size, output);
  fclose(output);

  free(plaintext);
  free(ciphertext);

  return 0;
}