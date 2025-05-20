//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct {
  char *path;
  long size;
} FileInfo;

int compareFileInfo(const void *a, const void *b) {
  FileInfo *fa = (FileInfo *)a;
  FileInfo *fb = (FileInfo *)b;
  return fb->size - fa->size;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <directory>\n", argv[0]);
    return 1;
  }

  char *path = argv[1];

  DIR *dir = opendir(path);
  if (dir == NULL) {
    perror("Unable to open directory");
    return 2;
  }

  struct dirent *ent;
  long totalSize = 0;

  while ((ent = readdir(dir)) != NULL) {
    if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
      continue;
    }

    char *fullPath = malloc(strlen(path) + strlen(ent->d_name) + 2);
    strcpy(fullPath, path);
    strcat(fullPath, "/");
    strcat(fullPath, ent->d_name);

    struct stat statbuf;
    if (stat(fullPath, &statbuf) == -1) {
      perror("Unable to stat file");
      continue;
    }

    if (S_ISDIR(statbuf.st_mode)) {
      int fd = open(fullPath, O_RDONLY);
      if (fd == -1) {
        perror("Unable to open directory");
        continue;
      }
      closedir(fd);
    } else if (S_ISREG(statbuf.st_mode)) {
      totalSize += statbuf.st_size;
    }

    free(fullPath);
  }

  closedir(dir);

  FileInfo *files = malloc(sizeof(FileInfo) * 100);
  int numFiles = 0;

  dir = opendir(path);
  if (dir == NULL) {
    perror("Unable to open directory");
    return 2;
  }

  while ((ent = readdir(dir)) != NULL) {
    if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
      continue;
    }

    char *fullPath = malloc(strlen(path) + strlen(ent->d_name) + 2);
    strcpy(fullPath, path);
    strcat(fullPath, "/");
    strcat(fullPath, ent->d_name);

    struct stat statbuf;
    if (stat(fullPath, &statbuf) == -1) {
      perror("Unable to stat file");
      continue;
    }

    if (S_ISREG(statbuf.st_mode)) {
      files[numFiles].path = malloc(strlen(fullPath) + 1);
      strcpy(files[numFiles].path, fullPath);
      files[numFiles].size = statbuf.st_size;
      numFiles++;
    }

    free(fullPath);
  }

  closedir(dir);

  qsort(files, numFiles, sizeof(FileInfo), compareFileInfo);

  printf("Total size: %ld bytes\n", totalSize);
  printf("Top 10 largest files:\n");
  for (int i = 0; i < 10 && i < numFiles; i++) {
    printf("%ld bytes: %s\n", files[i].size, files[i].path);
  }

  for (int i = 0; i < numFiles; i++) {
    free(files[i].path);
  }
  free(files);

  return 0;
}