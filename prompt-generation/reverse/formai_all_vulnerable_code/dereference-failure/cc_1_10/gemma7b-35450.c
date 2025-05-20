//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255
#define MAX_BACKUP_DIRECTORY_LENGTH 255

typedef struct FileBackupEntry {
  char file_name[MAX_FILE_NAME_LENGTH];
  char backup_directory[MAX_BACKUP_DIRECTORY_LENGTH];
  struct FileBackupEntry* next;
} FileBackupEntry;

void insert_file_backup_entry(FileBackupEntry** head, char* file_name, char* backup_directory) {
  FileBackupEntry* new_entry = malloc(sizeof(FileBackupEntry));
  strcpy(new_entry->file_name, file_name);
  strcpy(new_entry->backup_directory, backup_directory);
  new_entry->next = NULL;

  if (*head == NULL) {
    *head = new_entry;
  } else {
    (*head)->next = new_entry;
  }
}

void backup_files(FileBackupEntry* head) {
  FILE* file_ptr;
  char* file_path;
  char* backup_path;

  while (head) {
    file_path = malloc(MAX_FILE_NAME_LENGTH);
    backup_path = malloc(MAX_BACKUP_DIRECTORY_LENGTH);

    strcpy(file_path, head->file_name);
    strcpy(backup_path, head->backup_directory);

    file_ptr = fopen(file_path, "r");
    if (file_ptr) {
      backup_files(head->next);
      fclose(file_ptr);
    }

    free(file_path);
    free(backup_path);
  }
}

int main() {
  FileBackupEntry* head = NULL;

  insert_file_backup_entry(&head, "my_file.txt", "backup/directory");
  insert_file_backup_entry(&head, "another_file.doc", "backup/directory");

  backup_files(head);

  return 0;
}