//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_NAME_MAX 255
#define BUFFER_SIZE 1024

typedef struct FileEntry {
  char filename[FILE_NAME_MAX];
  time_t timestamp;
  struct FileEntry* next;
} FileEntry;

void insertFileEntry(FileEntry** head, char* filename) {
  time_t timestamp = time(NULL);
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

void backupFiles(FileEntry** head) {
  FILE* file = fopen("backup.dat", "w");
  fprintf(file, "Filename: %s, Timestamp: %ld\n", (*head)->filename, (*head)->timestamp);

  FileEntry* currentEntry = *head;
  while (currentEntry) {
    fprintf(file, "Filename: %s, Timestamp: %ld\n", currentEntry->filename, currentEntry->timestamp);
    currentEntry = currentEntry->next;
  }

  fclose(file);
}

int main() {
  FileEntry* head = NULL;
  insertFileEntry(&head, "cyberpunk.txt");
  insertFileEntry(&head, "matrix.jpg");
  insertFileEntry(&head, "future.doc");

  backupFiles(&head);

  return 0;
}