//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT_KEY 0x1234
#define DECRYPT_KEY 0x4321

void encrypt_file(char *input_file, char *output_file) {
  FILE *in = fopen(input_file, "rb");
  FILE *out = fopen(output_file, "wb");
  if (!in || !out) {
    perror("Error opening files");
    exit(1);
  }

  char buffer[1024];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, sizeof(buffer), in)) > 0) {
    for (size_t i = 0; i < bytes_read; i++) {
      buffer[i] ^= ENCRYPT_KEY;
    }
    fwrite(buffer, 1, bytes_read, out);
  }

  fclose(in);
  fclose(out);
}

void decrypt_file(char *input_file, char *output_file) {
  FILE *in = fopen(input_file, "rb");
  FILE *out = fopen(output_file, "wb");
  if (!in || !out) {
    perror("Error opening files");
    exit(1);
  }

  char buffer[1024];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, sizeof(buffer), in)) > 0) {
    for (size_t i = 0; i < bytes_read; i++) {
      buffer[i] ^= DECRYPT_KEY;
    }
    fwrite(buffer, 1, bytes_read, out);
  }

  fclose(in);
  fclose(out);
}

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Usage: %s <action> <input_file> <output_file>\n", argv[0]);
    printf("Action can be encrypt or decrypt\n");
    exit(1);
  }

  char *action = argv[1];
  char *input_file = argv[2];
  char *output_file = argv[3];

  if (strcmp(action, "encrypt") == 0) {
    encrypt_file(input_file, output_file);
  } else if (strcmp(action, "decrypt") == 0) {
    decrypt_file(input_file, output_file);
  } else {
    printf("Invalid action: %s\n", action);
    exit(1);
  }

  return 0;
}