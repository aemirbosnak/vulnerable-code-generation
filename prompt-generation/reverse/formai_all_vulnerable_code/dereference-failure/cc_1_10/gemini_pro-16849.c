//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 0

int main(int argc, char *argv[]) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <encrypt/decrypt> <input_file> <output_file> <key>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int mode = strcmp(argv[1], "encrypt") == 0 ? ENCRYPT : DECRYPT;
  char *input_file = argv[2];
  char *output_file = argv[3];
  char *key = argv[4];

  FILE *fin = fopen(input_file, "rb");
  if (fin == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  FILE *fout = fopen(output_file, "wb");
  if (fout == NULL) {
    perror("fopen");
    fclose(fin);
    return EXIT_FAILURE;
  }

  int key_len = strlen(key);
  int i = 0;

  while (!feof(fin)) {
    int c = fgetc(fin);
    if (c == EOF) break;

    if (mode == ENCRYPT) {
      c ^= key[i % key_len];
    } else {
      c ^= key[i % key_len];
    }

    fputc(c, fout);
    i++;
  }

  fclose(fin);
  fclose(fout);

  return EXIT_SUCCESS;
}