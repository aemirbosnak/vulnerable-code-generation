//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry {
  char filename[MAX_FILE_NAME_LENGTH];
  struct FileEntry* next;
} FileEntry;

FileEntry* CreateFileEntry(char* filename) {
  FileEntry* newEntry = malloc(sizeof(FileEntry));
  strcpy(newEntry->filename, filename);
  newEntry->next = NULL;
  return newEntry;
}

void AddFileEntry(FileEntry* head, char* filename) {
  FileEntry* newEntry = CreateFileEntry(filename);
  if (head == NULL) {
    head = newEntry;
  } else {
    newEntry->next = head;
    head = newEntry;
  }
}

void BackupFiles(FileEntry* head) {
  time_t t = time(NULL);
  char backupFileName[MAX_FILE_NAME_LENGTH];
  sprintf(backupFileName, "backup_%ld.tar", t);
  FILE* backupFile = fopen(backupFileName, "w");
  fprintf(backupFile, "tar -zcvf %s", backupFileName);
  for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
    fprintf(backupFile, "cp %s ./", currentEntry->filename);
  }
  fclose(backupFile);
  printf("Files backed up to %s.\n", backupFileName);
}

int main() {
  FileEntry* head = NULL;
  AddFileEntry(head, "my_file.txt");
  AddFileEntry(head, "another_file.doc");
  BackupFiles(head);

  return 0;
}