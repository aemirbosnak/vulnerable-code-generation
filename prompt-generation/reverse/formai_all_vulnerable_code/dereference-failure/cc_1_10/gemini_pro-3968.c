//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define HEADER_COLOR "\e[38;5;39m"
#define TEXT_COLOR "\e[38;5;240m"
#define ERROR_COLOR "\e[38;5;196m"
#define RESET_COLOR "\e[0m"

struct FileInfo {
  char *name;
  long size;
};

int compareFiles(const void *a, const void *b) {
  struct FileInfo *file1 = (struct FileInfo *)a;
  struct FileInfo *file2 = (struct FileInfo *)b;
  return file2->size - file1->size;
}

int main() {
  // Initialize the directory stream
  DIR *dir = opendir(".");
  if (dir == NULL) {
    fprintf(stderr, ERROR_COLOR "Error opening directory.\n" RESET_COLOR);
    return 1;
  }

  // Allocate memory for the file array
  struct FileInfo *files = malloc(sizeof(struct FileInfo) * 100);
  if (files == NULL) {
    fprintf(stderr, ERROR_COLOR "Error allocating memory for file array.\n" RESET_COLOR);
    closedir(dir);
    return 1;
  }

  // Iterate over the directory entries
  int fileCount = 0;
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Skip hidden files
    if (entry->d_name[0] == '.') {
      continue;
    }

    // Get the file size
    struct stat statbuf;
    if (stat(entry->d_name, &statbuf) != 0) {
      fprintf(stderr, ERROR_COLOR "Error getting file size for %s.\n" RESET_COLOR, entry->d_name);
      continue;
    }

    // Add the file to the array
    files[fileCount].name = strdup(entry->d_name);
    files[fileCount].size = statbuf.st_size;
    fileCount++;
  }

  // Sort the files by size
  qsort(files, fileCount, sizeof(struct FileInfo), compareFiles);

  // Print the header
  printf(HEADER_COLOR "** C Disk Space Analyzer v3.0 **\n" RESET_COLOR);
  printf(TEXT_COLOR "Total number of files: %d\n\n" RESET_COLOR, fileCount);

  // Iterate over the files and print their information
  for (int i = 0; i < fileCount; i++) {
    printf("%-20s %7.2f MB\n", files[i].name, (float)files[i].size / 1024 / 1024);
  }

  // Free the allocated memory
  for (int i = 0; i < fileCount; i++) {
    free(files[i].name);
  }
  free(files);
  closedir(dir);

  return 0;
}