//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct FileEntry {
  char filename[256];
  int size;
  struct FileEntry* next;
} FileEntry;

FileEntry* InsertFile(FileEntry* head, char* filename, int size) {
  FileEntry* newEntry = malloc(sizeof(FileEntry));
  strcpy(newEntry->filename, filename);
  newEntry->size = size;
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    head->next = newEntry;
  }

  return head;
}

void BackupFiles(FileEntry* head) {
  FILE* filePtr;
  for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
    filePtr = fopen(currentEntry->filename, "r");
    if (filePtr) {
      char* data = malloc(currentEntry->size);
      fread(data, currentEntry->size, 1, filePtr);
      fclose(filePtr);

      printf("Backing up file: %s\n", currentEntry->filename);
      printf("File size: %d bytes\n", currentEntry->size);
      printf("Data: %s\n", data);
    }
  }
}

int main() {
  FileEntry* head = NULL;
  InsertFile(head, "a.txt", 10);
  InsertFile(head, "b.txt", 20);
  InsertFile(head, "c.txt", 30);

  BackupFiles(head);

  return 0;
}