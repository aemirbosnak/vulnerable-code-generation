//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FileEntry {
  char name[256];
  int size;
  struct FileEntry* next;
} FileEntry;

FileEntry* createFileEntry(char* name, int size) {
  FileEntry* entry = (FileEntry*)malloc(sizeof(FileEntry));
  strcpy(entry->name, name);
  entry->size = size;
  entry->next = NULL;
  return entry;
}

void addToTail(FileEntry* tail, FileEntry* newEntry) {
  if (tail) {
    tail->next = newEntry;
  } else {
    tail = newEntry;
  }
  tail = newEntry;
}

void backupFiles(FileEntry* head) {
  FILE* backupFile = fopen("backup.dat", "w");
  fprintf(backupFile, "Backup File:\n");
  for (FileEntry* current = head; current; current = current->next) {
    fprintf(backupFile, "Name: %s, Size: %d\n", current->name, current->size);
  }
  fclose(backupFile);
}

int main() {
  FileEntry* head = NULL;
  FileEntry* tail = NULL;

  // Create some file entries
  FileEntry* entry1 = createFileEntry("file1.txt", 1024);
  addToTail(head, entry1);
  FileEntry* entry2 = createFileEntry("file2.txt", 2048);
  addToTail(head, entry2);

  // Backup the files
  backupFiles(head);

  return 0;
}