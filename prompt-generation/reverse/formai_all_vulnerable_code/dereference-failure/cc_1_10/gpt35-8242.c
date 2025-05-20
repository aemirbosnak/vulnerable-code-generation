//FormAI DATASET v1.0 Category: Data recovery tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef unsigned char byte;

// Struct to represent a file
typedef struct file {
  byte *data;
  int size;
  char *filename;
} File;

// Function to find the size of a file
int file_size(FILE* fp) {
  fseek(fp, 0, SEEK_END);
  int size = ftell(fp);
  rewind(fp);
  return size;
}

// Function to read a block of bytes from file
byte* read_block(FILE *fp) {
  byte *block = (byte*)malloc(BLOCK_SIZE * sizeof(byte));
  fread(block, BLOCK_SIZE, 1, fp);
  return block;
}

// Function to recover deleted files given a disk image file
File* recover_files(char *filename) {
  FILE *disk_image = fopen(filename, "rb");
  if (disk_image == NULL) {
    printf("Error: Could not open disk image!\n");
    exit(1);
  }

  // Skip first few blocks to avoid boot sector and FAT tables
  fseek(disk_image, BLOCK_SIZE * 33, SEEK_SET);

  // Read each block until the end of file
  File *files = NULL;
  int num_files = 0;
  byte *block = read_block(disk_image);
  while (!feof(disk_image)) {
    // If block starts with deleted file signature
    if (strncmp((char*)block, "DELETED FILE", 12) == 0) {
      // Find the size of the file
      int size = block[28] | (block[29] << 8) | (block[30] << 16) | (block[31] << 24);

      // Get filename
      char *filename = (char*)malloc(sizeof(char) * 13);
      strncpy(filename, (char*)block + 1, 8);
      strcat(filename, ".");
      strncat(filename, (char*)block + 9, 3);

      // Allocate memory for file data and read it
      byte *data = (byte*)malloc(size * sizeof(byte));
      memcpy(data, block + 32, size);

      // Add file to the list
      num_files++;
      files = (File*)realloc(files, num_files * sizeof(File));
      files[num_files - 1].filename = filename;
      files[num_files - 1].data = data;
      files[num_files - 1].size = size;
    }

    // Read next block
    block = read_block(disk_image);
  }

  // Close disk image file
  fclose(disk_image);

  return files;
}

int main() {
  char *filename = "disk_image.img";
  File *files = recover_files(filename);
  printf("Recovered %d files:\n", sizeof(files) / sizeof(File));
  for (int i = 0; i < sizeof(files) / sizeof(File); i++) {
    printf("%s (%d bytes)\n", files[i].filename, files[i].size);
  }
  return 0;
}