//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry {
  char filename[MAX_FILE_NAME_LENGTH];
  struct FileEntry* next;
} FileEntry;

typedef struct BackupSystem {
  FileEntry* head;
  int numFiles;
} BackupSystem;

void insertFileEntry(BackupSystem* system, char* filename) {
  FileEntry* newEntry = malloc(sizeof(FileEntry));
  strcpy(newEntry->filename, filename);
  newEntry->next = NULL;

  if (system->head == NULL) {
    system->head = newEntry;
  } else {
    system->head->next = newEntry;
  }

  system->numFiles++;
}

void backupSystem(BackupSystem* system) {
  FILE* filePointer;
  FILE* backupFile;
  char buffer[1024];

  backupFile = fopen("backup.txt", "w");

  for (FileEntry* entry = system->head; entry != NULL; entry++) {
    filePointer = fopen(entry->filename, "r");

    fprintf(backupFile, "File: %s\n", entry->filename);

    while (fgets(buffer, 1024, filePointer) != NULL) {
      fprintf(backupFile, "%s", buffer);
    }

    fclose(filePointer);
  }

  fclose(backupFile);
}

int main() {
  BackupSystem* system = malloc(sizeof(BackupSystem));
  system->head = NULL;
  system->numFiles = 0;

  insertFileEntry(system, "test.txt");
  insertFileEntry(system, "another.txt");

  backupSystem(system);

  return 0;
}