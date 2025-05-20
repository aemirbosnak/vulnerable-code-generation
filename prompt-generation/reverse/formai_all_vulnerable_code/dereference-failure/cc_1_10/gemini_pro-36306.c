//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the checksum of a string
unsigned int checksum(const char *str) {
  unsigned int sum = 0;
  while (*str) {
    sum += *str++;
  }
  return sum;
}

// Read a string from a file
char *read_file(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  rewind(fp);

  char *buffer = malloc(size + 1);
  if (buffer == NULL) {
    perror("Error allocating memory");
    fclose(fp);
    return NULL;
  }

  fread(buffer, 1, size, fp);
  buffer[size] = '\0';

  fclose(fp);

  return buffer;
}

// Print the checksum of a string
void print_checksum(const char *str) {
  printf("Checksum: %u\n", checksum(str));
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *str = read_file(argv[1]);
  if (str == NULL) {
    return EXIT_FAILURE;
  }

  print_checksum(str);

  free(str);

  return EXIT_SUCCESS;
}