//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

typedef struct {
  char *name;
  long long size;
} FileInfo;

int compareFileInfo(const void *a, const void *b) {
  FileInfo *fa = (FileInfo *)a;
  FileInfo *fb = (FileInfo *)b;
  return fb->size - fa->size;
}

int main() {
  DIR *dir = opendir(".");
  if (dir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  struct dirent *entry;
  int numFiles = 0;
  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_REG) {
      numFiles++;
    }
  }

  rewinddir(dir);

  FileInfo *files = malloc(numFiles * sizeof(FileInfo));
  if (files == NULL) {
    perror("malloc");
    closedir(dir);
    return EXIT_FAILURE;
  }

  int i = 0;
  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_REG) {
      char *path = malloc(strlen(entry->d_name) + 2);
      if (path == NULL) {
        perror("malloc");
        closedir(dir);
        free(files);
        return EXIT_FAILURE;
      }
      strcpy(path, entry->d_name);
      strcat(path, "/");

      struct stat statbuf;
      if (stat(path, &statbuf) == -1) {
        perror("stat");
        closedir(dir);
        free(files);
        free(path);
        return EXIT_FAILURE;
      }

      files[i].name = path;
      files[i].size = statbuf.st_size;
      i++;
    }
  }

  closedir(dir);

  qsort(files, numFiles, sizeof(FileInfo), compareFileInfo);

  for (i = 0; i < numFiles; i++) {
    printf("%-20s %lld bytes\n", files[i].name, files[i].size);
    free(files[i].name);
  }

  free(files);

  return EXIT_SUCCESS;
}