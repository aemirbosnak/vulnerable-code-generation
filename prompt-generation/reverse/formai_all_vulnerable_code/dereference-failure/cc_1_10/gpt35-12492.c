//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define KILOBYTE 1024
#define MEGABYTE 1048576
#define GIGABYTE 1073741824

typedef struct {
  char *name;
  long size;
} File;

void printFileSize(long size) {
  if (size >= GIGABYTE) {
    printf("%.2f GB\n", (float) size / GIGABYTE);
  } else if (size >= MEGABYTE) {
    printf("%.2f MB\n", (float) size / MEGABYTE);
  } else {
    printf("%.2f KB\n", (float) size / KILOBYTE);
  }
}

void printTopFiles(File *files, int numFiles, long totalSize) {
  printf("Top 10 Largest Files:\n");
  for (int i = 0; i < numFiles && i < 10; i++) {
    printf("#%d %s - ", i + 1, files[i].name);
    printFileSize(files[i].size);
  }
  printf("Total Disk Space Used: ");
  printFileSize(totalSize);
}

void swapFiles(File *files, int i, int j) {
  File temp = files[i];
  files[i] = files[j];
  files[j] = temp;
}

void sortFiles(File *files, int numFiles) {
  for (int i = 0; i < numFiles; i++) {
    for (int j = i + 1; j < numFiles; j++) {
      if (files[i].size < files[j].size) {
        swapFiles(files, i, j);
      }
    }
  }
}

long analyzeDirectory(char *path, File *files) {
  DIR *dir = opendir(path);
  if (dir == NULL) {
    fprintf(stderr, "Error: Could not open directory %s\n", path);
    return 0;
  }

  struct dirent *entry;
  struct stat fileStat;
  long totalSize = 0;
  int numFiles = 0;
  while ((entry = readdir(dir)) != NULL) {
    char *name = entry->d_name;
    char fullPath[PATH_MAX];
    snprintf(fullPath, PATH_MAX, "%s/%s", path, name);

    if (lstat(fullPath, &fileStat) == -1) {
      fprintf(stderr, "Error: Could not stat file %s\n", fullPath);
      continue;
    }

    if (S_ISREG(fileStat.st_mode)) {
      files[numFiles].name = strdup(name);
      files[numFiles].size = fileStat.st_size;
      totalSize += fileStat.st_size;
      numFiles++;
    } else if (S_ISDIR(fileStat.st_mode) && strcmp(name, ".") != 0 && strcmp(name, "..") != 0) {
      totalSize += analyzeDirectory(fullPath, &files[numFiles]);
      numFiles += sizeof(&files[numFiles]) / sizeof(File);
    }
  }

  closedir(dir);

  sortFiles(files, numFiles);

  printTopFiles(files, numFiles, totalSize);

  return totalSize;
}

int main(int argc, char **argv) {
  char *path;
  if (argc < 2) {
    path = ".";
  } else {
    path = argv[1];
  }

  File files[10000];

  analyzeDirectory(path, files);

  return 0;
}