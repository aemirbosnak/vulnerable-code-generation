//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry {
  char filename[MAX_FILE_NAME_LENGTH];
  struct FileEntry* next;
} FileEntry;

FileEntry* file_list = NULL;

void add_file(char* filename) {
  FileEntry* new_entry = malloc(sizeof(FileEntry));
  strcpy(new_entry->filename, filename);
  new_entry->next = NULL;

  if (file_list == NULL) {
    file_list = new_entry;
  } else {
    file_list->next = new_entry;
    file_list = new_entry;
  }
}

void backup_files() {
  FILE* backup_file = fopen("backup.txt", "w");
  FileEntry* current_entry = file_list;

  while (current_entry) {
    fprintf(backup_file, "%s\n", current_entry->filename);
    current_entry = current_entry->next;
  }

  fclose(backup_file);
}

int main() {
  add_file("foo.txt");
  add_file("bar.txt");
  add_file("baz.txt");

  backup_files();

  FILE* backup_file = fopen("backup.txt", "r");
  char line[MAX_FILE_NAME_LENGTH];

  while (fgets(line, MAX_FILE_NAME_LENGTH, backup_file) != NULL) {
    printf("%s\n", line);
  }

  fclose(backup_file);

  return 0;
}