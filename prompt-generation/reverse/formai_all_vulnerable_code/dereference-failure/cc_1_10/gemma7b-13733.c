//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024 * 1024

typedef struct FileEntry {
  char *name;
  long size;
  struct FileEntry *next;
} FileEntry;

void insertFile(FileEntry **head, char *name, long size) {
  FileEntry *newEntry = malloc(sizeof(FileEntry));
  newEntry->name = strdup(name);
  newEntry->size = size;
  newEntry->next = NULL;

  if (*head == NULL) {
    *head = newEntry;
  } else {
    (*head)->next = newEntry;
  }
}

void backupFiles(FileEntry *head) {
  time_t t = time(NULL);
  char timestamp[20];
  strftime(timestamp, 20, "%Y-%m-%d_%H-%M-%S", localtime(&t));

  FILE *backupFile = fopen("backup.txt", "w");
  fprintf(backupFile, "Backup Timestamp: %s\n", timestamp);

  for (FileEntry *current = head; current; current = current->next) {
    fprintf(backupFile, "File Name: %s, Size: %ld bytes\n", current->name, current->size);
  }

  fclose(backupFile);
}

int main() {
  FileEntry *head = NULL;
  insertFile(&head, "test.txt", 100);
  insertFile(&head, "image.jpg", 1000);
  insertFile(&head, "document.pdf", 2000);

  backupFiles(head);

  return 0;
}