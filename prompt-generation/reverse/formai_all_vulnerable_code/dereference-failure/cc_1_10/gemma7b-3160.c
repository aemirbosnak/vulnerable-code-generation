//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct FileEntry {
  char filename[256];
  struct FileEntry* next;
} FileEntry;

typedef struct FileSystem {
  FileEntry* head;
  int size;
} FileSystem;

FileSystem* createFileSystem() {
  FileSystem* fs = malloc(sizeof(FileSystem));
  fs->head = NULL;
  fs->size = 0;
  return fs;
}

void addFile(FileSystem* fs, char* filename) {
  FileEntry* newEntry = malloc(sizeof(FileEntry));
  strcpy(newEntry->filename, filename);
  newEntry->next = NULL;

  if (fs->head == NULL) {
    fs->head = newEntry;
  } else {
    fs->head->next = newEntry;
  }

  fs->size++;
}

void backupFiles(FileSystem* fs) {
  FILE* backupFile = fopen("backup.dat", "w");

  for (FileEntry* entry = fs->head; entry; entry = entry->next) {
    fprintf(backupFile, "%s\n", entry->filename);
  }

  fclose(backupFile);
}

int main() {
  FileSystem* fs = createFileSystem();

  // Add some files to the file system
  addFile(fs, "file1.txt");
  addFile(fs, "file2.doc");
  addFile(fs, "file3.pdf");

  // Backup the files to a file
  backupFiles(fs);

  // Print the backup file contents
  FILE* backupFile = fopen("backup.dat", "r");
  char line[BUFFER_SIZE];
  while (fgets(line, BUFFER_SIZE, backupFile) != NULL) {
    printf("%s\n", line);
  }
  fclose(backupFile);

  return 0;
}