//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WATERMARK 0x94CE554B // example watermark value

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Usage: %s [filename]\n", argv[0]);
    return 1;
  }

  char *filename = argv[1];

  FILE *file = fopen(filename, "r+b");

  if (!file)
  {
    printf("Unable to open file %s\n", filename);
    return 1;
  }

  // Get file size
  fseek(file, 0L, SEEK_END);
  int file_size = ftell(file);
  rewind(file);

  // Read file into memory
  char *buffer = (char *)malloc(file_size);
  fread(buffer, file_size, 1, file);

  // Calculate checksum
  unsigned int checksum = 0;
  for (int i = 0; i < file_size; i++)
  {
    checksum = (checksum + (unsigned int)buffer[i]) % 0xFFFFFFFF;
  }

  // Calculate watermark
  unsigned int watermark = (checksum ^ WATERMARK);

  // Write watermark to file
  fwrite(&watermark, sizeof(unsigned int), 1, file);

  // Close file and free memory
  fclose(file);
  free(buffer);

  return 0;
}