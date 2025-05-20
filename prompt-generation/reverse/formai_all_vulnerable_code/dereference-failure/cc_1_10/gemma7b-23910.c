//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024 * 1024

typedef struct FileEntry {
  char name[256];
  int size;
  struct FileEntry* next;
} FileEntry;

void insertFile(FileEntry** head, char* name, int size) {
  FileEntry* newEntry = malloc(sizeof(FileEntry));
  strcpy(newEntry->name, name);
  newEntry->size = size;
  newEntry->next = NULL;

  if (*head == NULL) {
    *head = newEntry;
  } else {
    ((*head)->next = newEntry);
    *head = newEntry;
  }
}

void backupFiles(FileEntry** head) {
  time_t t = time(NULL);
  char backupDir[256];
  sprintf(backupDir, "/backup/%d/", t);
  mkdir(backupDir, 0755);

  FileEntry* current = *head;
  while (current) {
    char backupFile[256];
    sprintf(backupFile, "%s/%s", backupDir, current->name);
    FILE* file = fopen(backupFile, "w");
    fwrite(current->name, 1, current->size, file);
    fclose(file);
    current = current->next;
  }
}

int main() {
  FileEntry* head = NULL;

  // Insert some files
  insertFile(&head, "myphoto.jpg", 1000);
  insertFile(&head, "mydocument.doc", 2000);
  insertFile(&head, "mymusic.mp3", 3000);

  // Backup the files
  backupFiles(&head);

  return 0;
}