//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *filename;
  long long size;
} File;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  File file;
  file.filename = argv[1];

  FILE *fp = fopen(file.filename, "rb");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  fseek(fp, 0, SEEK_END);
  file.size = ftell(fp);

  fseek(fp, 0, SEEK_SET);

  char *buffer = malloc(file.size);
  if (buffer == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  if (fread(buffer, 1, file.size, fp) != file.size) {
    perror("fread");
    exit(EXIT_FAILURE);
  }

  fclose(fp);

  FILE *fpo = fopen("recovered.file", "wb");
  if (fpo == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  if (fwrite(buffer, 1, file.size, fpo) != file.size) {
    perror("fwrite");
    exit(EXIT_FAILURE);
  }

  fclose(fpo);

  free(buffer);

  return EXIT_SUCCESS;
}