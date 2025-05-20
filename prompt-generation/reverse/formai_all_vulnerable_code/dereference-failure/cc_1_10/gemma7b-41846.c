//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 255
#define MAX_BUFFER_SIZE 4096

typedef struct FileEntry {
  char filename[MAX_FILE_NAME_LENGTH];
  struct FileEntry* next;
  time_t timestamp;
} FileEntry;

void insertFileEntry(FileEntry** head, char* filename, time_t timestamp) {
  FileEntry* newEntry = malloc(sizeof(FileEntry));
  strcpy(newEntry->filename, filename);
  newEntry->timestamp = timestamp;
  newEntry->next = NULL;

  if (*head == NULL) {
    *head = newEntry;
  } else {
    (*head)->next = newEntry;
  }
}

void backupFiles(FileEntry* head) {
  FILE* fileStream;
  char backupDirectory[MAX_FILE_NAME_LENGTH];
  sprintf(backupDirectory, "backup/%s", time(NULL));
  mkdir(backupDirectory, 0755);

  for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
    fprintf(stderr, "Backing up file: %s\n", currentEntry->filename);
    fileStream = fopen(currentEntry->filename, "rb");
    if (fileStream) {
      char buffer[MAX_BUFFER_SIZE];
      int readBytes;
      sprintf(backupDirectory, "backup/%s/%s", time(NULL), currentEntry->filename);
      fileStream = fopen(backupDirectory, "wb");
      while ((readBytes = fread(buffer, 1, MAX_BUFFER_SIZE, fileStream)) > 0) {
        fwrite(buffer, 1, readBytes, fileStream);
      }
      fclose(fileStream);
    }
  }
}

int main() {
  FileEntry* head = NULL;
  insertFileEntry(&head, "test.txt", time(NULL));
  insertFileEntry(&head, "image.jpg", time(NULL));
  backupFiles(head);

  return 0;
}