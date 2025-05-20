//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

typedef struct FileInfo {
  char path[MAX_PATH_LENGTH];
  time_t mtime;
} FileInfo;

int compareFileInfo(const void *a, const void *b) {
  const FileInfo *fa = (const FileInfo *)a;
  const FileInfo *fb = (const FileInfo *)b;
  return strcmp(fa->path, fb->path);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <dir1> <dir2>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *dir1 = argv[1];
  char *dir2 = argv[2];

  // Get a list of files in each directory.
  DIR *d1 = opendir(dir1);
  if (d1 == NULL) {
    perror("opendir(dir1)");
    return EXIT_FAILURE;
  }

  DIR *d2 = opendir(dir2);
  if (d2 == NULL) {
    perror("opendir(dir2)");
    return EXIT_FAILURE;
  }

  FileInfo *files1 = malloc(sizeof(FileInfo) * 1024);
  int numFiles1 = 0;

  FileInfo *files2 = malloc(sizeof(FileInfo) * 1024);
  int numFiles2 = 0;

  struct dirent *de;
  while ((de = readdir(d1)) != NULL) {
    if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
      continue;
    }

    char path[MAX_PATH_LENGTH];
    snprintf(path, sizeof(path), "%s/%s", dir1, de->d_name);

    struct stat st;
    if (stat(path, &st) == -1) {
      perror("stat(path)");
      return EXIT_FAILURE;
    }

    files1[numFiles1].mtime = st.st_mtime;
    strcpy(files1[numFiles1].path, path);
    numFiles1++;
  }

  while ((de = readdir(d2)) != NULL) {
    if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
      continue;
    }

    char path[MAX_PATH_LENGTH];
    snprintf(path, sizeof(path), "%s/%s", dir2, de->d_name);

    struct stat st;
    if (stat(path, &st) == -1) {
      perror("stat(path)");
      return EXIT_FAILURE;
    }

    files2[numFiles2].mtime = st.st_mtime;
    strcpy(files2[numFiles2].path, path);
    numFiles2++;
  }

  closedir(d1);
  closedir(d2);

  // Sort the files by path.
  qsort(files1, numFiles1, sizeof(FileInfo), compareFileInfo);
  qsort(files2, numFiles2, sizeof(FileInfo), compareFileInfo);

  // Compare the files in each directory.
  int i1 = 0;
  int i2 = 0;
  while (i1 < numFiles1 && i2 < numFiles2) {
    int cmp = strcmp(files1[i1].path, files2[i2].path);

    if (cmp == 0) {
      // The files are the same.
      if (files1[i1].mtime != files2[i2].mtime) {
        // The files have different modification times.
        printf("Files %s and %s have different modification times.\n",
               files1[i1].path, files2[i2].path);
      }

      i1++;
      i2++;
    } else if (cmp < 0) {
      // The file in dir1 does not exist in dir2.
      printf("File %s does not exist in dir2.\n", files1[i1].path);

      i1++;
    } else {
      // The file in dir2 does not exist in dir1.
      printf("File %s does not exist in dir1.\n", files2[i2].path);

      i2++;
    }
  }

  while (i1 < numFiles1) {
    // The file in dir1 does not exist in dir2.
    printf("File %s does not exist in dir2.\n", files1[i1].path);

    i1++;
  }

  while (i2 < numFiles2) {
    // The file in dir2 does not exist in dir1.
    printf("File %s does not exist in dir1.\n", files2[i2].path);

    i2++;
  }

  free(files1);
  free(files2);

  return EXIT_SUCCESS;
}