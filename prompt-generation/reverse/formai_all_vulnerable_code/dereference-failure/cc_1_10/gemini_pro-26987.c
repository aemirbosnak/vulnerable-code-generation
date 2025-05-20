//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024

typedef struct {
  char name[100];
  int size;
  time_t timestamp;
} File;

File files[MAX_FILES];
int numFiles = 0;

void addFile(char *name, int size, time_t timestamp) {
  if (numFiles >= MAX_FILES) {
    printf("Error: Too many files.\n");
    return;
  }

  strcpy(files[numFiles].name, name);
  files[numFiles].size = size;
  files[numFiles].timestamp = timestamp;
  numFiles++;
}

void printFiles() {
  for (int i = 0; i < numFiles; i++) {
    printf("%s (%d bytes, %s)\n", files[i].name, files[i].size, ctime(&files[i].timestamp));
  }
}

void backupFiles(char *backupDirectory) {
  DIR *dir;
  struct dirent *entry;

  dir = opendir(".");
  if (dir == NULL) {
    printf("Error: Could not open directory.\n");
    return;
  }

  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    struct stat st;
    if (stat(entry->d_name, &st) == -1) {
      printf("Error: Could not stat file.\n");
      continue;
    }

    if (S_ISREG(st.st_mode)) {
      FILE *file;
      FILE *backupFile;

      file = fopen(entry->d_name, "rb");
      if (file == NULL) {
        printf("Error: Could not open file.\n");
        continue;
      }

      char backupFileName[100];
      sprintf(backupFileName, "%s/%s-%ld.bak", backupDirectory, entry->d_name, time(NULL));

      backupFile = fopen(backupFileName, "wb");
      if (backupFile == NULL) {
        printf("Error: Could not open backup file.\n");
        fclose(file);
        continue;
      }

      int size;
      while ((size = fread(files[numFiles].name, 1, MAX_FILE_SIZE, file)) > 0) {
        fwrite(files[numFiles].name, 1, size, backupFile);
      }

      fclose(file);
      fclose(backupFile);

      addFile(entry->d_name, st.st_size, time(NULL));
    }
  }

  closedir(dir);
}

int main() {
  backupFiles("backup");
  printFiles();

  return 0;
}