//FormAI DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NUM 100
#define MAX_FILE_LENGTH 200

typedef struct {
  char* filename;
  int size;
} File;

void listFiles(File* files, int numFiles) {
  printf("List of files:\n");
  for (int i = 0; i < numFiles; i++) {
    printf("  %s (%d bytes)\n", files[i].filename, files[i].size);
  }
}

void backupFiles(File* files, int numFiles) {
  FILE* backup = fopen("backup.txt", "w");
  if (backup == NULL) {
    printf("Error: could not open backup file\n");
    return;
  }
  for (int i = 0; i < numFiles; i++) {
    FILE* f = fopen(files[i].filename, "r");
    if (f == NULL) {
      printf("Error: could not open file %s\n", files[i].filename);
      continue;
    }
    char line[MAX_FILE_LENGTH];
    while (fgets(line, MAX_FILE_LENGTH, f) != NULL) {
      if (fputs(line, backup) < 0) {
        printf("Error: could not write to backup file\n");
        break;
      }
    }
    fclose(f);
  }
  fclose(backup);
  printf("Files backed up successfully!\n");
}

int main() {
  File files[MAX_FILE_NUM];
  int numFiles = 0;
  char filename[MAX_FILE_LENGTH];
  for (;;) { // infinite loop
    printf("Enter filename (or 'done' to finish): ");
    fgets(filename, MAX_FILE_LENGTH, stdin);
    if (strcmp(filename, "done\n") == 0) {
      break; // exit loop
    }
    if (filename[strlen(filename) - 1] == '\n') {
      filename[strlen(filename) - 1] = '\0'; // remove newline character
    }
    FILE* f = fopen(filename, "r"); // check if file exists
    if (f == NULL) {
      printf("Error: file %s not found\n", filename);
      continue; // back to start of loop
    }
    fclose(f);
    if (numFiles == MAX_FILE_NUM) {
      printf("Error: maximum number of files reached\n");
      break; // exit loop
    }
    files[numFiles].filename = malloc(strlen(filename) + 1);
    strcpy(files[numFiles].filename, filename);
    f = fopen(filename, "r"); // get file size
    fseek(f, 0, SEEK_END);
    files[numFiles].size = ftell(f);
    fclose(f);
    numFiles++;
  }
  listFiles(files, numFiles);
  backupFiles(files, numFiles);
  for (int i = 0; i < numFiles; i++) {
    free(files[i].filename);
  }
  return 0;
}