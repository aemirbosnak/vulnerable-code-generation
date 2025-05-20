//FormAI DATASET v1.0 Category: Compression algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *input_file, char *output_file) {
  FILE *in = fopen(input_file, "rb");
  FILE *out = fopen(output_file, "wb");

  if (!in) {
    printf("Error opening input file.");
    return;
  }

  if (!out) {
    printf("Error opening output file.");
    return;
  }

  fseek(in, 0, SEEK_END);
  long length = ftell(in);
  fseek(in, 0, SEEK_SET);

  char *buffer = (char *)malloc(length);
  fread(buffer, 1, length, in);
  fclose(in);

  char previous = buffer[0];
  int count = 1;
  for (int i = 1; i < length; i++) {
    if (buffer[i] == previous) {
      count++;
    } else {
      fwrite(&count, sizeof(int), 1, out);
      fwrite(&previous, sizeof(char), 1, out);
      previous = buffer[i];
      count = 1;
    }
  }
  fwrite(&count, sizeof(int), 1, out);
  fwrite(&previous, sizeof(char), 1, out);

  fclose(out);
  free(buffer);

  printf("File compressed successfully.");
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <input_file> <output_file>", argv[0]);
    return 1;
  }

  char *input_file = argv[1];
  char *output_file = argv[2];

  compress(input_file, output_file);

  return 0;
}