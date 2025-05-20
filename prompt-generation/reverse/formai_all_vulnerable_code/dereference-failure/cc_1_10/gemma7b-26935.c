//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

typedef struct FileEntry {
  char filename[256];
  long size;
  struct FileEntry* next;
} FileEntry;

void insertFile(FileEntry** head, char* filename, long size) {
  FileEntry* newEntry = malloc(sizeof(FileEntry));
  strcpy(newEntry->filename, filename);
  newEntry->size = size;
  newEntry->next = NULL;

  if (*head == NULL) {
    *head = newEntry;
  } else {
    (*head)->next = newEntry;
  }
}

void backupFiles(FileEntry* head) {
  FILE* filePointer;
  for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
    filePointer = fopen(currentEntry->filename, "r");
    if (filePointer) {
      long fileSize = currentEntry->size;
      char* buffer = malloc(BUFFER_SIZE);
      int readBytes = 0;
      while (readBytes < fileSize) {
        readBytes += fread(buffer, 1, BUFFER_SIZE, filePointer);
        fwrite(buffer, 1, readBytes, stdout);
      }
      fclose(filePointer);
      free(buffer);
    }
  }
}

int main() {
  FileEntry* head = NULL;
  insertFile(&head, "file1.txt", 1024);
  insertFile(&head, "file2.txt", 2048);
  insertFile(&head, "file3.txt", 3072);

  backupFiles(head);

  return 0;
}