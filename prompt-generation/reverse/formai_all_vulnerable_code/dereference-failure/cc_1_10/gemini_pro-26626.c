//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_FILES 100
#define MAX_FILE_SIZE 1000000
#define STRLEN(s) (sizeof(s) / sizeof(s[0]))

// Data structures
typedef struct {
  char *name;
  char *content;
  size_t size;
  time_t last_modified;
} File;

typedef struct {
  File files[MAX_FILES];
  size_t num_files;
} FileSynchronizer;

// Functions
FileSynchronizer *file_synchronizer_new();
void file_synchronizer_free(FileSynchronizer *fs);
int file_synchronizer_add(FileSynchronizer *fs, File *file);
int file_synchronizer_remove(FileSynchronizer *fs, char *name);
File *file_synchronizer_get(FileSynchronizer *fs, char *name);
int file_synchronizer_sync(FileSynchronizer *fs);

// Main function
int main() {
  // Create a new file synchronizer
  FileSynchronizer *fs = file_synchronizer_new();

  // Add some files to the synchronizer
  File *file1 = malloc(sizeof(File));
  file1->name = "file1.txt";
  file1->content = "This is file 1.";
  file1->size = STRLEN(file1->content);
  file1->last_modified = time(NULL);
  file_synchronizer_add(fs, file1);

  File *file2 = malloc(sizeof(File));
  file2->name = "file2.txt";
  file2->content = "This is file 2.";
  file2->size = STRLEN(file2->content);
  file2->last_modified = time(NULL);
  file_synchronizer_add(fs, file2);

  // Sync the files
  file_synchronizer_sync(fs);

  // Free the file synchronizer
  file_synchronizer_free(fs);

  return 0;
}

// Function definitions

FileSynchronizer *file_synchronizer_new() {
  FileSynchronizer *fs = malloc(sizeof(FileSynchronizer));
  fs->num_files = 0;
  return fs;
}

void file_synchronizer_free(FileSynchronizer *fs) {
  for (size_t i = 0; i < fs->num_files; i++) {
    free(fs->files[i].name);
    free(fs->files[i].content);
  }
  free(fs);
}

int file_synchronizer_add(FileSynchronizer *fs, File *file) {
  if (fs->num_files >= MAX_FILES) {
    return -1;
  }
  fs->files[fs->num_files++] = *file;
  return 0;
}

int file_synchronizer_remove(FileSynchronizer *fs, char *name) {
  for (size_t i = 0; i < fs->num_files; i++) {
    if (strcmp(fs->files[i].name, name) == 0) {
      fs->num_files--;
      memmove(&fs->files[i], &fs->files[i + 1],
              (fs->num_files - i) * sizeof(File));
      return 0;
    }
  }
  return -1;
}

File *file_synchronizer_get(FileSynchronizer *fs, char *name) {
  for (size_t i = 0; i < fs->num_files; i++) {
    if (strcmp(fs->files[i].name, name) == 0) {
      return &fs->files[i];
    }
  }
  return NULL;
}

int file_synchronizer_sync(FileSynchronizer *fs) {
  // Loop through all the files and sync them to the local storage
  for (size_t i = 0; i < fs->num_files; i++) {
    // Open the file
    FILE *fp = fopen(fs->files[i].name, "w");
    if (fp == NULL) {
      return -1;
    }

    // Write the file content to the local storage
    fwrite(fs->files[i].content, 1, fs->files[i].size, fp);

    // Close the file
    fclose(fp);
  }

  return 0;
}