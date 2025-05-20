//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileEntry {
  char name[255];
  int size;
  struct FileEntry* next;
} FileEntry;

FileEntry* createFileEntry(char* name, int size) {
  FileEntry* newEntry = malloc(sizeof(FileEntry));
  strcpy(newEntry->name, name);
  newEntry->size = size;
  newEntry->next = NULL;
  return newEntry;
}

void addToFiles(FileEntry* head, char* name, int size) {
  FileEntry* newEntry = createFileEntry(name, size);
  if (head == NULL) {
    head = newEntry;
  } else {
    newEntry->next = head;
    head = newEntry;
  }
}

void backupFiles(FileEntry* head) {
  FILE* backupFile = fopen("files.dat", "w");
  fprintf(backupFile, "Number of files: %d\n", head->size);
  for (FileEntry* current = head; current; current = current->next) {
    fprintf(backupFile, "File name: %s\n", current->name);
    fprintf(backupFile, "File size: %d\n", current->size);
  }
  fclose(backupFile);
}

int main() {
  FileEntry* files = NULL;

  // Add some files
  addToFiles(files, "file1.txt", 100);
  addToFiles(files, "file2.txt", 200);
  addToFiles(files, "file3.txt", 300);

  // Backup the files
  backupFiles(files);

  // Print the backup file contents
  FILE* backupFile = fopen("files.dat", "r");
  fprintf(stdout, "Number of files: %d\n", files->size);
  for (FileEntry* current = files; current; current = current->next) {
    fprintf(stdout, "File name: %s\n", current->name);
    fprintf(stdout, "File size: %d\n", current->size);
  }
  fclose(backupFile);

  return 0;
}