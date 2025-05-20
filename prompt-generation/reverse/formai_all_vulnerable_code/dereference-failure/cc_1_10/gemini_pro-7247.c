//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024

typedef struct {
  char name[32];
  time_t timestamp;
  int size;
  char data[MAX_FILE_SIZE];
} File;

File files[MAX_FILES];
int num_files = 0;

void add_file(char *name, time_t timestamp, int size, char *data) {
  strcpy(files[num_files].name, name);
  files[num_files].timestamp = timestamp;
  files[num_files].size = size;
  memcpy(files[num_files].data, data, size);
  num_files++;
}

void remove_file(char *name) {
  int i;
  for (i = 0; i < num_files; i++) {
    if (strcmp(files[i].name, name) == 0) {
      break;
    }
  }
  if (i < num_files) {
    for (; i < num_files - 1; i++) {
      files[i] = files[i + 1];
    }
    num_files--;
  }
}

void update_file(char *name, time_t timestamp, int size, char *data) {
  int i;
  for (i = 0; i < num_files; i++) {
    if (strcmp(files[i].name, name) == 0) {
      break;
    }
  }
  if (i < num_files) {
    files[i].timestamp = timestamp;
    files[i].size = size;
    memcpy(files[i].data, data, size);
  }
}

void print_files() {
  int i;
  for (i = 0; i < num_files; i++) {
    printf("%s %ld %d\n", files[i].name, files[i].timestamp, files[i].size);
  }
}

int main() {
  add_file("file1.txt", time(NULL), 100, "Hello, world!");
  add_file("file2.txt", time(NULL), 200, "This is a test.");
  add_file("file3.txt", time(NULL), 300, "This is a longer test.");

  print_files();

  remove_file("file2.txt");

  print_files();

  update_file("file1.txt", time(NULL), 200, "Hello, world! This is a longer test.");

  print_files();

  return 0;
}