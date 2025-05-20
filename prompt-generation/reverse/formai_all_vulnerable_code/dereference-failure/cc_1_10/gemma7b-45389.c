//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 10

typedef struct FileEntry {
  char filename[256];
  time_t timestamp;
  struct FileEntry* next;
} FileEntry;

FileEntry* addFileEntry(FileEntry* head, char* filename) {
  FileEntry* newEntry = malloc(sizeof(FileEntry));
  strcpy(newEntry->filename, filename);
  newEntry->timestamp = time(NULL);
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    head->next = newEntry;
  }

  return head;
}

void backupFiles(FileEntry* head) {
  FILE* backupFile = fopen("backup.txt", "w");

  for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
    fprintf(backupFile, "%s\n", currentEntry->filename);
  }

  fclose(backupFile);
}

int main() {
  FileEntry* head = NULL;

  // Add some file entries
  head = addFileEntry(head, "file1.txt");
  head = addFileEntry(head, "file2.txt");
  head = addFileEntry(head, "file3.txt");

  // Backup the files
  backupFiles(head);

  return 0;
}