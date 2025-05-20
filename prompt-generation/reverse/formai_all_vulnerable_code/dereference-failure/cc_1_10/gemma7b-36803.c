//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX_BUFFER_SIZE
#define MAX_BUFFER_SIZE 1024
#endif

typedef struct FileSynchronizer {
  char *buffer;
  int size;
  int position;
  FILE *file;
} FileSynchronizer;

FileSynchronizer *fileSynchronizer_create(const char *filename, int size) {
  FileSynchronizer *synchronizer = malloc(sizeof(FileSynchronizer));
  synchronizer->buffer = malloc(size);
  synchronizer->size = size;
  synchronizer->position = 0;
  synchronizer->file = fopen(filename, "r+b");
  return synchronizer;
}

void fileSynchronizer_write(FileSynchronizer *synchronizer, const char *data, int length) {
  int remaining = synchronizer->size - synchronizer->position;
  if (length > remaining) {
    fprintf(stderr, "Error: insufficient buffer space.\n");
    return;
  }

  memcpy(synchronizer->buffer + synchronizer->position, data, length);
  synchronizer->position += length;

  if (synchronizer->position == synchronizer->size) {
    fwrite(synchronizer->buffer, 1, synchronizer->size, synchronizer->file);
    synchronizer->position = 0;
  }
}

void fileSynchronizer_destroy(FileSynchronizer *synchronizer) {
  fclose(synchronizer->file);
  free(synchronizer->buffer);
  free(synchronizer);
}

int main() {
  FileSynchronizer *synchronizer = fileSynchronizer_create("test.txt", MAX_BUFFER_SIZE);
  fileSynchronizer_write(synchronizer, "Hello, world!", 13);
  fileSynchronizer_write(synchronizer, "This is a file synchronizer!", 28);
  fileSynchronizer_destroy(synchronizer);

  return 0;
}