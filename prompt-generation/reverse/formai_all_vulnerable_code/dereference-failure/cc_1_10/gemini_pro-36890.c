//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

// A structure to store the metadata of a file
typedef struct {
  char *name;
  char *path;
  char *type;
  long size;
  time_t mtime;
} FileMetadata;

// A function to extract the metadata of a file
FileMetadata *extract_metadata(const char *file_path) {
  struct stat file_stat;
  if (stat(file_path, &file_stat) != 0) {
    return NULL;
  }

  FileMetadata *metadata = malloc(sizeof(FileMetadata));
  if (metadata == NULL) {
    return NULL;
  }

  metadata->name = strdup(file_path);
  metadata->path = strdup(file_path);
  metadata->type = S_ISDIR(file_stat.st_mode) ? "directory" : "file";
  metadata->size = file_stat.st_size;
  metadata->mtime = file_stat.st_mtime;

  return metadata;
}

// A function to print the metadata of a file
void print_metadata(FileMetadata *metadata) {
  printf("Name: %s\n", metadata->name);
  printf("Path: %s\n", metadata->path);
  printf("Type: %s\n", metadata->type);
  printf("Size: %ld bytes\n", metadata->size);
  printf("Last modified: %s", ctime(&metadata->mtime));
}

// A function to free the memory allocated for the metadata of a file
void free_metadata(FileMetadata *metadata) {
  free(metadata->name);
  free(metadata->path);
  free(metadata);
}

// The main function
int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s file_path\n", argv[0]);
    return 1;
  }

  FileMetadata *metadata = extract_metadata(argv[1]);
  if (metadata == NULL) {
    printf("Error: Could not extract metadata for file %s\n", argv[1]);
    return 1;
  }

  print_metadata(metadata);
  free_metadata(metadata);

  return 0;
}