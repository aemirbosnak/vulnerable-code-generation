//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 16

typedef struct {
  char key[KEY_LENGTH];
  int shift;
} CaesarCipher;

void generate_key(char* key) {
  int i;
  for (i = 0; i < KEY_LENGTH; i++) {
    key[i] = rand() % 26 + 'a';
  }
  key[KEY_LENGTH] = '\0';
}

int main(int argc, char* argv[]) {
  if (argc!= 3) {
    printf("Usage: %s <encrypt/decrypt> <file_path>\n", argv[0]);
    return 1;
  }

  char mode = argv[1][0];
  char* file_path = argv[2];

  FILE* file = fopen(file_path, "rb+");
  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  fseek(file, 0, SEEK_END);
  int file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char* file_buffer = malloc(file_size + 1);
  if (file_buffer == NULL) {
    printf("Error allocating memory.\n");
    fclose(file);
    return 1;
  }

  fread(file_buffer, 1, file_size, file);
  fclose(file);

  int block_count = file_size / BLOCK_SIZE;
  int remainder = file_size % BLOCK_SIZE;
  CaesarCipher cipher;
  generate_key(cipher.key);
  cipher.shift = (int)mode - 'a';

  int i;
  for (i = 0; i < block_count; i++) {
    int block_start = i * BLOCK_SIZE;
    int block_end = (i + 1) * BLOCK_SIZE - 1;
    if (block_end >= file_size) {
      block_end = file_size - 1;
    }

    int j;
    for (j = block_start; j <= block_end; j++) {
      if (isalpha(file_buffer[j])) {
        int offset = tolower(file_buffer[j]) - 'a';
        int new_offset = (offset + cipher.shift) % 26;
        file_buffer[j] = (char)(((int)file_buffer[j] - 'a' + new_offset) % 26 + 'a');
      }
    }
  }

  if (remainder > 0) {
    int block_start = block_count * BLOCK_SIZE;
    int j;
    for (j = block_start; j < file_size; j++) {
      if (isalpha(file_buffer[j])) {
        int offset = tolower(file_buffer[j]) - 'a';
        int new_offset = (offset + cipher.shift) % 26;
        file_buffer[j] = (char)(((int)file_buffer[j] - 'a' + new_offset) % 26 + 'a');
      }
    }
  }

  file = fopen(file_path, "wb");
  if (file == NULL) {
    printf("Error opening file.\n");
    free(file_buffer);
    return 1;
  }

  fwrite(file_buffer, 1, file_size, file);
  fclose(file);

  free(file_buffer);
  return 0;
}