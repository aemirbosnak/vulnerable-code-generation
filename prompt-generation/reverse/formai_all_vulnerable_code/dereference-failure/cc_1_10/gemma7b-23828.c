//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File {
  char name[256];
  struct File* next;
  FILE* file_ptr;
} File;

File* file_system = NULL;

void create_file(char* name) {
  File* new_file = (File*)malloc(sizeof(File));
  strcpy(new_file->name, name);
  new_file->next = file_system;
  file_system = new_file;
  new_file->file_ptr = fopen(name, "w");
}

void read_file(char* name) {
  File* file = file_system;
  while (file) {
    if (strcmp(file->name, name) == 0) {
      FILE* file_ptr = file->file_ptr;
      char data[1024];
      int read_size = fread(data, 1, 1024, file_ptr);
      printf("%s", data);
      break;
    }
    file = file->next;
  }
}

void write_file(char* name, char* data) {
  File* file = file_system;
  while (file) {
    if (strcmp(file->name, name) == 0) {
      FILE* file_ptr = file->file_ptr;
      fprintf(file_ptr, "%s", data);
      break;
    }
    file = file->next;
  }
}

int main() {
  create_file("test.txt");
  write_file("test.txt", "This is a test file.");
  read_file("test.txt");
  return 0;
}