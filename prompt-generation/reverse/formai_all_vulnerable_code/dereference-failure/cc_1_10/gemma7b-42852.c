//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

typedef struct FileEntry {
  char name[MAX_FILE_SIZE];
  int size;
  struct FileEntry* next;
} FileEntry;

typedef struct BackupSystem {
  FileEntry* head;
  int numFiles;
} BackupSystem;

BackupSystem* backupSystem_init() {
  BackupSystem* system = malloc(sizeof(BackupSystem));
  system->head = NULL;
  system->numFiles = 0;
  return system;
}

void backupSystem_addFile(BackupSystem* system, char* name, int size) {
  FileEntry* newFile = malloc(sizeof(FileEntry));
  strcpy(newFile->name, name);
  newFile->size = size;
  newFile->next = system->head;
  system->head = newFile;
  system->numFiles++;
}

void backupSystem_listFiles(BackupSystem* system) {
  FileEntry* currentFile = system->head;
  while (currentFile) {
    printf("%s (%d bytes)\n", currentFile->name, currentFile->size);
    currentFile = currentFile->next;
  }
}

int main() {
  BackupSystem* system = backupSystem_init();

  backupSystem_addFile(system, "my_precious_photo.jpg", 100000);
  backupSystem_addFile(system, "my_favorite_song.mp3", 200000);
  backupSystem_addFile(system, "my_cat.jpg", 50000);

  backupSystem_listFiles(system);

  return 0;
}