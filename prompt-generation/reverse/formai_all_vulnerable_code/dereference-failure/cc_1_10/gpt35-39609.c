//FormAI DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void compress(const char* input, const char* output) {
  unsigned char buffer[MAX_BUFFER_SIZE];
  unsigned char count = 0;
  unsigned int i, j;
  FILE* in = fopen(input, "rb");
  FILE* out = fopen(output, "wb");

  if (in == NULL || out == NULL) {
    return;
  }

  while (1) {
    unsigned char byte = fgetc(in);

    if (byte != buffer[count] || count == MAX_BUFFER_SIZE) {
      if (feof(in)) {
        count++;
      }

      fwrite(&count, sizeof(unsigned char), 1, out);
      fwrite(buffer, sizeof(unsigned char), count, out);

      if (feof(in)) {
        break;
      }

      count = 0;
      buffer[count++] = byte;
    } else {
      count++;
    }
  }

  fclose(in);
  fclose(out);
}

void decompress(const char* input, const char* output) {
  unsigned char byte;
  unsigned int count, i, j;
  FILE* in = fopen(input, "rb");
  FILE* out = fopen(output, "wb");

  if (in == NULL || out == NULL) {
    return;
  }

  while (fread(&count, sizeof(count), 1, in) == 1) {
    fread(&byte, sizeof(byte), 1, in);

    for (i = 0; i < count; ++i) {
      fwrite(&byte, sizeof(byte), 1, out);
    }
  }

  fclose(in);
  fclose(out);
}

int main() {
  compress("input.txt", "output.dat");
  decompress("output.dat", "output.txt");

  return 0;
}