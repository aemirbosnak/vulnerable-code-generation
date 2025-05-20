//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileBackupEntry {
  char file_name[MAX_FILE_NAME_LENGTH];
  struct FileBackupEntry* next;
} FileBackupEntry;

FileBackupEntry* insert_file(FileBackupEntry* head, char* file_name) {
  FileBackupEntry* new_entry = malloc(sizeof(FileBackupEntry));
  strcpy(new_entry->file_name, file_name);
  new_entry->next = NULL;

  if (head == NULL) {
    head = new_entry;
  } else {
    new_entry->next = head;
    head = new_entry;
  }

  return head;
}

void backup_files(FileBackupEntry* head) {
  FILE* file_ptr;
  char backup_directory[] = "/home/backup";

  for (FileBackupEntry* current_entry = head; current_entry; current_entry = current_entry->next) {
    file_ptr = fopen(current_entry->file_name, "r");
    if (file_ptr == NULL) {
      perror("Error opening file");
      exit(1);
    }

    char file_contents[1024];
    int num_read = read(fileno(file_ptr), file_contents, 1024);
    fclose(file_ptr);

    if (num_read > 0) {
      FILE* backup_file = fopen(backup_directory, "a");
      fprintf(backup_file, "%s\n", file_contents);
      fclose(backup_file);
    }
  }
}

int main() {
  FileBackupEntry* head = NULL;

  insert_file(head, "/home/user/my_file.txt");
  insert_file(head, "/home/user/another_file.doc");

  backup_files(head);

  return 0;
}