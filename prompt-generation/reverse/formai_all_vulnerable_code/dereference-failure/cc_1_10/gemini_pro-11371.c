//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint8_t *scan_buffer;
uint64_t scan_size;

// Scan function that takes a buffer and size as input and returns the number of matches found
uint64_t scan(const uint8_t *buffer, uint64_t size, const char *signature, uint64_t signature_size) {
  uint64_t i, j, matches = 0;

  for (i = 0; i < size - signature_size; i++) {
    for (j = 0; j < signature_size; j++) {
      if (buffer[i + j] != signature[j]) {
        break;
      }
    }
    if (j == signature_size) {
      matches++;
    }
  }

  return matches;
}

// Main function that takes a file name as input and scans it for a given signature
int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <file> <signature> <signature_size>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Read the file into a buffer
  FILE *fp = fopen(argv[1], "rb");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }
  fseek(fp, 0, SEEK_END);
  scan_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  scan_buffer = malloc(scan_size);
  if (scan_buffer == NULL) {
    perror("malloc");
    fclose(fp);
    return EXIT_FAILURE;
  }
  if (fread(scan_buffer, 1, scan_size, fp) != scan_size) {
    perror("fread");
    fclose(fp);
    free(scan_buffer);
    return EXIT_FAILURE;
  }
  fclose(fp);

  // Scan the file for the given signature
  uint64_t signature_size = strtoull(argv[3], NULL, 0);
  uint64_t matches = scan(scan_buffer, scan_size, argv[2], signature_size);

  // Print the number of matches found
  printf("Found %llu matches for signature '%s'\n", matches, argv[2]);

  // Free the buffer
  free(scan_buffer);

  return EXIT_SUCCESS;
}