//FormAI DATASET v1.0 Category: Data recovery tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[256];
  int size;
  int start;
} File;

void recover_data(char *image_data, int image_size, int block_size, int num_blocks, File *files, int num_files, char *dir) {
  int i, j, k;
  char *block_data;

  for (i = 0; i < num_files; i++) {
    if (strstr(files[i].name, dir) != files[i].name) {
      continue; // skip files not in directory
    }

    printf("Recovering file '%s'\n", files[i].name);

    FILE *fp = fopen(files[i].name, "w");
    if (!fp) {
      printf("Error opening file for writing: %s\n", files[i].name);
      continue;
    }

    for (j = 0; j < files[i].size; j += block_size) {
      block_data = image_data + (files[i].start + (j / block_size)) * block_size;

      if (block_data[0] == 0xE5) {
        // deleted file block
        continue;
      }

      // write data to file
      for (k = 0; k < block_size && (j + k) < files[i].size; k++) {
        fprintf(fp, "%c", block_data[k]);
      }
    }

    fclose(fp);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: recover_data <image_file> <directory>\n");
    return 1;
  }

  char *image_file = argv[1];
  char *dir = argv[2];

  // load file system image into memory
  FILE *fp = fopen(image_file, "rb");
  if (!fp) {
    printf("Error opening file: %s\n", image_file);
    return 1;
  }

  int image_size;
  char *image_data;

  fseek(fp, 0, SEEK_END);
  image_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  image_data = (char*) malloc(image_size);
  fread(image_data, 1, image_size, fp);
  fclose(fp);

  // read file system metadata (file list)
  int num_files;
  fread(&num_files, sizeof(int), 1, fp);

  File *files = (File*) malloc(num_files * sizeof(File));

  for (int i = 0; i < num_files; i++) {
    fread(&files[i].name, sizeof(char), 256, fp);
    fread(&files[i].size, sizeof(int), 1, fp);
    fread(&files[i].start, sizeof(int), 1, fp);
  }

  // recover deleted files
  recover_data(image_data, image_size, 512, image_size / 512, files, num_files, dir);

  free(image_data);
  free(files);

  return 0;
}