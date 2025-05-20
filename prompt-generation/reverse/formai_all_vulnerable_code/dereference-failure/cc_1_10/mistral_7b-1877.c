//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FILE_SIZE (1024 * 1024)
#define BUFFER_SIZE (128)
#define SEED 12345

bool is_file(const char *path) {
  FILE *fp = fopen(path, "r");
  if (fp == NULL) {
    return false;
  }
  fclose(fp);
  return true;
}

void encrypt_byte(unsigned char *byte, int key) {
  *byte = (*byte + key) & 0xFF;
}

void encrypt_buffer(unsigned char *buffer, size_t size, int key) {
  for (size_t i = 0; i < size; i++) {
    encrypt_byte(&buffer[i], key);
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
    return 1;
  }

  const char *input_file = argv[1];
  const char *output_file = argv[2];
  int key = atoi(argv[3]);

  if (!is_file(input_file)) {
    printf("Input file does not exist.\n");
    return 1;
  }

  FILE *input_fp = fopen(input_file, "rb");
  FILE *output_fp = fopen(output_file, "wb");

  if (input_fp == NULL || output_fp == NULL) {
    printf("Error opening files.\n");
    fclose(input_fp);
    fclose(output_fp);
    return 1;
  }

  srand(SEED);

  char buffer[BUFFER_SIZE];
  size_t bytes_read;

  while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_fp)) > 0) {
    encrypt_buffer((unsigned char *)buffer, bytes_read, key);
    fwrite(buffer, 1, bytes_read, output_fp);
  }

  fclose(input_fp);
  fclose(output_fp);

  printf("File encrypted successfully.\n");

  return 0;
}