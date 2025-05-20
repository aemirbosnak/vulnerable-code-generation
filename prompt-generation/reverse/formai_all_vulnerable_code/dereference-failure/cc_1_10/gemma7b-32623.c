//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct FileSynchronizer {
  char buffer[BUFFER_SIZE];
  int head;
  int tail;
  int size;
  FILE *fp;
} FileSynchronizer;

FileSynchronizer *createFileSynchronizer(FILE *fp) {
  FileSynchronizer *fs = malloc(sizeof(FileSynchronizer));
  fs->fp = fp;
  fs->head = 0;
  fs->tail = 0;
  fs->size = 0;
  return fs;
}

void addToSynchronizer(FileSynchronizer *fs, char data) {
  if (fs->size == BUFFER_SIZE) {
    fs->head = (fs->head + 1) % BUFFER_SIZE;
  }
  fs->buffer[fs->tail] = data;
  fs->tail = (fs->tail + 1) % BUFFER_SIZE;
  fs->size++;
}

char readFromSynchronizer(FileSynchronizer *fs) {
  if (fs->size == 0) {
    return -1;
  }
  fs->head = (fs->head + 1) % BUFFER_SIZE;
  fs->size--;
  return fs->buffer[fs->tail];
}

int main() {
  FILE *fp = fopen("test.txt", "w");
  FileSynchronizer *fs = createFileSynchronizer(fp);

  // Add data to the synchronizer
  addToSynchronizer(fs, 'a');
  addToSynchronizer(fs, 'b');
  addToSynchronizer(fs, 'c');

  // Read data from the synchronizer
  char data = readFromSynchronizer(fs);
  printf("%c", data);

  fclose(fp);
  return 0;
}