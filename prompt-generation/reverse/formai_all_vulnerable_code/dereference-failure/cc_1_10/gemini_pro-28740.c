//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

unsigned char *dictionary[65536];
char dictionary_size = 0;

void compress() {
  char *input = malloc(MAX_STR_LEN);
  if (input == NULL) {
    fprintf(stderr, "Cannot allocate input buffer!\n");
    exit(1);
  }
  char *output = malloc(MAX_STR_LEN);
  if (output == NULL) {
    fprintf(stderr, "Cannot allocate output buffer!\n");
    free(input);
    exit(1);
  }
  char *output_ptr = output;

  printf("Enter string to compress: ");
  if (scanf("%s", input) != 1) {
    fprintf(stderr, "Invalid input!\n");
    free(input);
    free(output);
    exit(1);
  }

  int i = 0;
  while (input[i] != '\0') {
    char *str_ptr = input + i;
    int index = -1;

    while (index < 0 && str_ptr >= input) {
      if (dictionary[index = (int)((unsigned long)str_ptr % 65536)] == str_ptr) {
        break;
      }
      str_ptr--;
    }

    if (index >= 0) {
      int len = str_ptr - input - index;
      *output_ptr++ = len | 0x80;
      *output_ptr++ = index;
      i += len;
    } else {
      *output_ptr++ = input[i++];
      dictionary[dictionary_size++] = input + i - 1;
    }
  }

  *output_ptr = '\0';

  printf("Compressed string: %s\n", output);

  free(input);
  free(output);
}

void decompress() {
  unsigned char *input = malloc(MAX_STR_LEN);
  if (input == NULL) {
    fprintf(stderr, "Cannot allocate input buffer!\n");
    exit(1);
  }
  char *output = malloc(MAX_STR_LEN);
  if (output == NULL) {
    fprintf(stderr, "Cannot allocate output buffer!\n");
    free(input);
    exit(1);
  }
  char *output_ptr = output;

  printf("Enter compressed string: ");
  if (scanf("%s", input) != 1) {
    fprintf(stderr, "Invalid input!\n");
    free(input);
    free(output);
    exit(1);
  }

  int i = 0;
  while (input[i] != '\0') {
    if (input[i] & 0x80) {
      int len = input[i++] & 0x7f;
      int index = input[i++];
      memcpy(output_ptr, dictionary[index], len);
      output_ptr += len;
    } else {
      *output_ptr++ = input[i++];
    }
  }

  *output_ptr = '\0';

  printf("Decompressed string: %s\n", output);

  free(input);
  free(output);
}

int main() {
  int choice;

  while (1) {
    printf("1. Compress\n2. Decompress\n3. Exit\nChoice: ");
    if (scanf("%d", &choice) != 1) {
      fprintf(stderr, "Invalid input!\n");
      exit(1);
    }

    switch (choice) {
      case 1:
        compress();
        break;
      case 2:
        decompress();
        break;
      case 3:
        exit(0);
      default:
        fprintf(stderr, "Invalid choice!\n");
    }
  }

  return 0;
}