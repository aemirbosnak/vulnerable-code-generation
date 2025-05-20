//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

typedef struct {
  char *name;
  long size;
  time_t mtime;
} FileInfo;

int compare_files(const void *a, const void *b) {
  const FileInfo *fa = (const FileInfo *)a;
  const FileInfo *fb = (const FileInfo *)b;
  return fa->size - fb->size;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    return EXIT_FAILURE;
  }

  DIR *dir = opendir(argv[1]);
  if (!dir) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  struct dirent *ent;
  int num_files = 0;
  while ((ent = readdir(dir))) {
    if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
      continue;
    }

    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s/%s", argv[1], ent->d_name);

    struct stat st;
    if (lstat(path, &st) == -1) {
      perror("lstat");
      continue;
    }

    if (!S_ISREG(st.st_mode)) {
      continue;
    }

    num_files++;
  }

  closedir(dir);

  FileInfo *files = malloc(sizeof(FileInfo) * num_files);
  if (!files) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  dir = opendir(argv[1]);
  if (!dir) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  int i = 0;
  while ((ent = readdir(dir))) {
    if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
      continue;
    }

    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s/%s", argv[1], ent->d_name);

    struct stat st;
    if (lstat(path, &st) == -1) {
      perror("lstat");
      continue;
    }

    if (!S_ISREG(st.st_mode)) {
      continue;
    }

    files[i].name = strdup(ent->d_name);
    files[i].size = st.st_size;
    files[i].mtime = st.st_mtime;
    i++;
  }

  closedir(dir);

  qsort(files, num_files, sizeof(FileInfo), compare_files);

  printf("File Size Distribution:\n");
  printf("------------------------\n");
  printf("Rank | File Name | Size (bytes) | Modification Time\n");
  printf("---------------------------------------------------\n");
  for (i = 0; i < num_files; i++) {
    printf("%3d | %-15s | %10ld | %s", i + 1, files[i].name, files[i].size, ctime(&files[i].mtime));
  }

  free(files);

  return EXIT_SUCCESS;
}