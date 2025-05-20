//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FileSynchronizer {
  char* filename;
  int file_size;
  FILE* file_pointer;
  char buffer[MAX_BUFFER_SIZE];
  struct FileSynchronizer* next;
} FileSynchronizer;

void file_synchronizer_init(FileSynchronizer** head) {
  *head = malloc(sizeof(FileSynchronizer));
  (*head)->filename = NULL;
  (*head)->file_size = 0;
  (*head)->file_pointer = NULL;
  (*head)->next = NULL;
}

void file_synchronizer_add(FileSynchronizer** head, char* filename, int file_size) {
  FileSynchronizer* new_node = malloc(sizeof(FileSynchronizer));
  new_node->filename = strdup(filename);
  new_node->file_size = file_size;
  new_node->file_pointer = fopen(filename, "r");
  new_node->next = NULL;

  if (*head) {
    ((*head)->next = new_node);
  } else {
    *head = new_node;
  }
}

void file_synchronizer_sync(FileSynchronizer* head) {
  FILE* file_pointer = NULL;
  for (FileSynchronizer* current = head; current; current = current->next) {
    if (file_pointer) {
      fclose(file_pointer);
    }

    file_pointer = current->file_pointer;
    fread(current->buffer, current->file_size, 1, file_pointer);
  }

  if (file_pointer) {
    fclose(file_pointer);
  }
}

int main() {
  FileSynchronizer* head = NULL;
  file_synchronizer_init(&head);

  file_synchronizer_add(&head, "file1.txt", 10);
  file_synchronizer_add(&head, "file2.txt", 20);
  file_synchronizer_add(&head, "file3.txt", 30);

  file_synchronizer_sync(head);

  for (FileSynchronizer* current = head; current; current = current->next) {
    printf("Filename: %s, File Size: %d, Buffer: %s\n", current->filename, current->file_size, current->buffer);
  }

  return 0;
}