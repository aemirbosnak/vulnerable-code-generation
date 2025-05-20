//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FileEntry {
  char filename[256];
  struct FileEntry* next;
} FileEntry;

void InsertFileEntry(FileEntry* head, char* filename) {
  FileEntry* newEntry = malloc(sizeof(FileEntry));
  strcpy(newEntry->filename, filename);
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    head->next = newEntry;
  }
}

int BackupFiles(FileEntry* head) {
  int totalSize = 0;
  FILE* backupFile = fopen("backup.dat", "w");

  for (FileEntry* currentEntry = head; currentEntry != NULL; currentEntry = currentEntry->next) {
    fprintf(backupFile, "%s\n", currentEntry->filename);
    totalSize++;
  }

  fclose(backupFile);
  return totalSize;
}

int main() {
  FileEntry* head = NULL;

  // Insert some file entries
  InsertFileEntry(head, "test.txt");
  InsertFileEntry(head, "image.jpg");
  InsertFileEntry(head, "document.doc");

  // Backup the files
  int totalSize = BackupFiles(head);

  // Print the total size of backed up files
  printf("Total size of backed up files: %d\n", totalSize);

  return 0;
}