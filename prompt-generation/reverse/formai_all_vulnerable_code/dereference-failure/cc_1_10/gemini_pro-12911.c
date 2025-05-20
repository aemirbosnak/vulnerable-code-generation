//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define ENCRYPT 1
#define DECRYPT 0

#define BUF_SIZE 1024

int main(int argc, char* argv[]) {
  // Check arguments
  if (argc < 4) {
    fprintf(stderr, "Usage: %s {encrypt|decrypt} key infile outfile\n", argv[0]);
    return 1;
  }

  // Get operation mode
  int mode = strcmp(argv[1], "encrypt") == 0 ? ENCRYPT : DECRYPT;

  // Get key
  char* key = argv[2];
  int key_len = strlen(key);

  // Open input and output files
  FILE* infile = fopen(argv[3], "rb");
  if (!infile) {
    perror("Error opening input file");
    return 1;
  }

  FILE* outfile = fopen(argv[4], "wb");
  if (!outfile) {
    perror("Error opening output file");
    return 1;
  }

  // Create buffer
  char buf[BUF_SIZE];
  size_t bytes_read;

  // Encrypt or decrypt data
  while ((bytes_read = fread(buf, 1, BUF_SIZE, infile)) > 0) {
    for (size_t i = 0; i < bytes_read; i++) {
      if (mode == ENCRYPT) {
        buf[i] ^= key[i % key_len];
      } else {
        buf[i] ^= key[i % key_len];
      }
    }
    fwrite(buf, 1, bytes_read, outfile);
  }

  // Close files
  fclose(infile);
  fclose(outfile);

  return 0;
}