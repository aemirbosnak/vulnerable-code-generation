//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct FileEntry {
  char name[255];
  int size;
  struct FileEntry* next;
} FileEntry;

typedef struct BackupSystem {
  FileEntry* head;
  int numFiles;
  char backupDir[255];
} BackupSystem;

void insertFile(BackupSystem* sys, char* name, int size) {
  FileEntry* newEntry = (FileEntry*)malloc(sizeof(FileEntry));
  strcpy(newEntry->name, name);
  newEntry->size = size;
  newEntry->next = NULL;

  if (sys->head == NULL) {
    sys->head = newEntry;
  } else {
    sys->head->next = newEntry;
  }

  sys->numFiles++;
}

void backupFiles(BackupSystem* sys) {
  FILE* backupFile = fopen(sys->backupDir, "w");

  for (FileEntry* currentEntry = sys->head; currentEntry; currentEntry = currentEntry->next) {
    fprintf(backupFile, "%s %d\n", currentEntry->name, currentEntry->size);
  }

  fclose(backupFile);
}

int main() {
  BackupSystem* sys = (BackupSystem*)malloc(sizeof(BackupSystem));
  sys->head = NULL;
  sys->numFiles = 0;
  strcpy(sys->backupDir, "backup.txt");

  insertFile(sys, "file1.txt", 1024);
  insertFile(sys, "file2.txt", 2048);
  insertFile(sys, "file3.txt", 3072);

  backupFiles(sys);

  return 0;
}