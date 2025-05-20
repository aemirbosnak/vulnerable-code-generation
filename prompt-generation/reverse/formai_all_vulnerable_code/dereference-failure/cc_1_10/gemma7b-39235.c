//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

typedef struct FileEntry {
  char filename[MAX_FILENAME_LENGTH];
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
  newEntry->next = fs->head;
  fs->head = newEntry;
  fs->size++;
}

int main() {
  FileSystem* fs = createFileSystem();
  addFile(fs, "secret.txt");
  addFile(fs, "suspicious_file.doc");
  addFile(fs, "malicious_code.bin");

  // Paranoia: Check if the file "malicious_code.bin" exists
  FileEntry* currentEntry = fs->head;
  while (currentEntry) {
    if (strcmp(currentEntry->filename, "malicious_code.bin") == 0) {
      printf("Malicious file found!\n");
      exit(1);
    }
    currentEntry = currentEntry->next;
  }

  // If the file does not exist, proceed...
  printf("No malicious file found.\n");

  return 0;
}