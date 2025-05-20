//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_FILES 10
#define BUFFER_SIZE 256

typedef struct file_info {
  char filename[256];
  struct file_info* next;
  int file_size;
  int locked;
} file_info;

file_info* head = NULL;

void lock_file(char* filename) {
  file_info* current = head;
  while (current) {
    if (strcmp(current->filename, filename) == 0) {
      current->locked = 1;
      return;
    }
    current = current->next;
  }

  current = malloc(sizeof(file_info));
  current->filename[0] = '\0';
  strcpy(current->filename, filename);
  current->file_size = 0;
  current->locked = 1;
  current->next = head;
  head = current;
}

void unlock_file(char* filename) {
  file_info* current = head;
  while (current) {
    if (strcmp(current->filename, filename) == 0) {
      current->locked = 0;
      return;
    }
    current = current->next;
  }
}

int main() {
  lock_file("foo.txt");
  unlock_file("foo.txt");
  return 0;
}