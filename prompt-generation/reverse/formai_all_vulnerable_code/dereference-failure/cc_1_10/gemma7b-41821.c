//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry
{
  char file_name[MAX_FILE_NAME_LENGTH];
  int file_size;
  struct FileEntry* next;
} FileEntry;

FileEntry* head = NULL;

void AddFileEntry(char* file_name, int file_size)
{
  FileEntry* new_entry = (FileEntry*)malloc(sizeof(FileEntry));
  strcpy(new_entry->file_name, file_name);
  new_entry->file_size = file_size;
  new_entry->next = NULL;

  if (head == NULL)
  {
    head = new_entry;
  }
  else
  {
    head->next = new_entry;
  }
}

void BackupFiles()
{
  FILE* backup_file = fopen("backup.txt", "w");
  FileEntry* current_entry = head;

  while (current_entry)
  {
    fprintf(backup_file, "File name: %s, File size: %d\n", current_entry->file_name, current_entry->file_size);
    current_entry = current_entry->next;
  }

  fclose(backup_file);
}

int main()
{
  AddFileEntry("my_file.txt", 100);
  AddFileEntry("another_file.doc", 200);

  BackupFiles();

  return 0;
}