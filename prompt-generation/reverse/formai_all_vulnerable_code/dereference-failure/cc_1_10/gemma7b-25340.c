//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_FILE_NAME_SIZE 256

typedef struct FileMeta {
  char filename[MAX_FILE_NAME_SIZE];
  char content[MAX_BUFFER_SIZE];
  int size;
  struct FileMeta* next;
} FileMeta;

FileMeta* extractMeta(char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  struct stat stat_buf;
  stat(filename, &stat_buf);

  FileMeta* meta = malloc(sizeof(FileMeta));
  meta->size = stat_buf.st_size;
  snprintf(meta->filename, MAX_FILE_NAME_SIZE, "%s", filename);

  size_t read_size = 0;
  char buffer[MAX_BUFFER_SIZE];
  while ((read_size = fread(buffer, 1, MAX_BUFFER_SIZE, file)) > 0) {
    memcpy(meta->content + read_size, buffer, read_size);
  }

  fclose(file);
  return meta;
}

int main() {
  char* filename = "my_file.txt";
  FileMeta* meta = extractMeta(filename);

  if (meta) {
    printf("Filename: %s\n", meta->filename);
    printf("Size: %d\n", meta->size);
    printf("Content: %s\n", meta->content);
  } else {
    printf("Error extracting metadata.\n");
  }

  return 0;
}