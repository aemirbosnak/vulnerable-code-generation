//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct FileSynchronizer {
  int files_num;
  char **files_names;
  FILE **files_pointers;
  int **file_locks;
} FileSynchronizer;

FileSynchronizer *file_synchronizer_init(int files_num) {
  FileSynchronizer *fs = malloc(sizeof(FileSynchronizer));
  fs->files_num = files_num;
  fs->files_names = malloc(files_num * sizeof(char *));
  fs->files_pointers = malloc(files_num * sizeof(FILE *));
  fs->file_locks = malloc(files_num * sizeof(int *));

  for (int i = 0; i < files_num; i++) {
    fs->files_names[i] = malloc(256);
    fs->files_pointers[i] = NULL;
    fs->file_locks[i] = NULL;
  }

  return fs;
}

void file_synchronizer_add_file(FileSynchronizer *fs, char *file_name) {
  for (int i = 0; i < fs->files_num; i++) {
    if (strcmp(fs->files_names[i], file_name) == 0) {
      return;
    }
  }

  fs->files_num++;
  fs->files_names = realloc(fs->files_names, fs->files_num * sizeof(char *));
  fs->files_pointers = realloc(fs->files_pointers, fs->files_num * sizeof(FILE *));
  fs->file_locks = realloc(fs->file_locks, fs->files_num * sizeof(int *));

  fs->files_names[fs->files_num - 1] = malloc(256);
  strcpy(fs->files_names[fs->files_num - 1], file_name);
  fs->files_pointers[fs->files_num - 1] = NULL;
  fs->file_locks[fs->files_num - 1] = NULL;
}

void file_synchronizer_lock_file(FileSynchronizer *fs, char *file_name) {
  for (int i = 0; i < fs->files_num; i++) {
    if (strcmp(fs->files_names[i], file_name) == 0) {
      fs->file_locks[i] = 1;
      return;
    }
  }

  return;
}

void file_synchronizer_unlock_file(FileSynchronizer *fs, char *file_name) {
  for (int i = 0; i < fs->files_num; i++) {
    if (strcmp(fs->files_names[i], file_name) == 0) {
      fs->file_locks[i] = 0;
      return;
    }
  }

  return;
}

int main() {
  FileSynchronizer *fs = file_synchronizer_init(5);
  file_synchronizer_add_file(fs, "a.txt");
  file_synchronizer_add_file(fs, "b.txt");
  file_synchronizer_lock_file(fs, "a.txt");
  file_synchronizer_unlock_file(fs, "a.txt");

  return 0;
}