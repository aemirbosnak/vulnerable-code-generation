//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef struct {
  char filename[256];
  unsigned int size;
  unsigned int start_block;
} FileEntry;

typedef struct {
  FileEntry* files;
  unsigned int num_files;
} Directory;

Directory* read_directory(FILE* disk) {
  Directory* directory = malloc(sizeof(Directory));
  directory->files = NULL;
  directory->num_files = 0;

  char buffer[BLOCK_SIZE];
  while (fread(buffer, BLOCK_SIZE, 1, disk)) {
    if (strncmp(buffer, "FILE", 4) == 0) {
      FileEntry* file = malloc(sizeof(FileEntry));
      strncpy(file->filename, buffer + 4, 256);
      file->size = atoi(buffer + 260);
      file->start_block = atoi(buffer + 264);

      directory->files = realloc(directory->files, (directory->num_files + 1) * sizeof(FileEntry));
      directory->files[directory->num_files++] = *file;
    }
  }

  return directory;
}

void write_file(FILE* disk, FileEntry* file) {
  char buffer[BLOCK_SIZE];
  fseek(disk, file->start_block * BLOCK_SIZE, SEEK_SET);

  for (unsigned int i = 0; i < file->size; i += BLOCK_SIZE) {
    fread(buffer, BLOCK_SIZE, 1, disk);
    fwrite(buffer, BLOCK_SIZE, 1, stdout);
  }
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s <disk image>\n", argv[0]);
    return 1;
  }

  FILE* disk = fopen(argv[1], "rb");
  if (disk == NULL) {
    printf("Error: Could not open disk image.\n");
    return 1;
  }

  Directory* directory = read_directory(disk);

  printf("Found %d files:\n", directory->num_files);
  for (unsigned int i = 0; i < directory->num_files; i++) {
    printf("  %s (%d bytes)\n", directory->files[i].filename, directory->files[i].size);
  }

  char filename[256];
  printf("\nEnter the name of the file you want to recover: ");
  scanf("%s", filename);

  FileEntry* file = NULL;
  for (unsigned int i = 0; i < directory->num_files; i++) {
    if (strcmp(directory->files[i].filename, filename) == 0) {
      file = &directory->files[i];
      break;
    }
  }

  if (file == NULL) {
    printf("Error: File not found.\n");
    return 1;
  }

  printf("Recovering file %s...\n", file->filename);
  write_file(disk, file);

  printf("File recovered successfully.\n");

  fclose(disk);
  free(directory->files);
  free(directory);

  return 0;
}