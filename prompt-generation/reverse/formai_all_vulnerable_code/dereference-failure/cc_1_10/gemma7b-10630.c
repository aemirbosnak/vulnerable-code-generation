//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: complete
#include <stdio.h>
#include <string.h>

#define MAX_DIR_NAME 256
#define MAX_FILE_NAME 256

typedef struct DirEntry {
  char dir_name[MAX_DIR_NAME];
  struct DirEntry* next;
} DirEntry;

typedef struct FileEntry {
  char file_name[MAX_FILE_NAME];
  int file_size;
  struct FileEntry* next;
} FileEntry;

DirEntry* head_dir = NULL;
FileEntry* head_file = NULL;

void create_dir(char* dir_name) {
  DirEntry* new_dir = (DirEntry*)malloc(sizeof(DirEntry));
  strcpy(new_dir->dir_name, dir_name);
  new_dir->next = head_dir;
  head_dir = new_dir;
}

void create_file(char* file_name, int file_size) {
  FileEntry* new_file = (FileEntry*)malloc(sizeof(FileEntry));
  strcpy(new_file->file_name, file_name);
  new_file->file_size = file_size;
  new_file->next = head_file;
  head_file = new_file;
}

void list_dir() {
  DirEntry* current_dir = head_dir;
  while (current_dir) {
    printf("%s\n", current_dir->dir_name);
    current_dir = current_dir->next;
  }
}

void list_file() {
  FileEntry* current_file = head_file;
  while (current_file) {
    printf("%s (%d bytes)\n", current_file->file_name, current_file->file_size);
    current_file = current_file->next;
  }
}

int main() {
  create_dir("mydir");
  create_file("myfile.txt", 100);
  list_dir();
  list_file();

  return 0;
}