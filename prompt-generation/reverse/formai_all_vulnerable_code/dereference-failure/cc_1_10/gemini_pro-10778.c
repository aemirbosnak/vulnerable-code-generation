//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILES_PER_DIRECTORY 512

typedef struct {
  char path[MAX_PATH_LENGTH];
  long long size;
} file_info;

int compare_file_info(const void *a, const void *b) {
  const file_info *fa = (const file_info *)a;
  const file_info *fb = (const file_info *)b;

  return fa->size - fb->size;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *directory = argv[1];
  int num_files = 0;
  long long total_size = 0;
  file_info files[MAX_FILES_PER_DIRECTORY];

  DIR *dir = opendir(directory);
  if (dir == NULL) {
    perror("opendir");
    exit(EXIT_FAILURE);
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char path[MAX_PATH_LENGTH];
    snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
      perror("stat");
      continue;
    }

    if (S_ISDIR(statbuf.st_mode)) {
      continue;
    }

    strncpy(files[num_files].path, path, sizeof(files[num_files].path));
    files[num_files].size = statbuf.st_size;
    num_files++;
  }

  closedir(dir);

  if (num_files == 0) {
    printf("No files found in %s\n", directory);
    exit(EXIT_SUCCESS);
  }

  qsort(files, num_files, sizeof(file_info), compare_file_info);

  printf("Files in %s:\n", directory);
  for (int i = 0; i < num_files; i++) {
    printf("%-40s %lld bytes\n", files[i].path, files[i].size);
    total_size += files[i].size;
  }

  printf("\nTotal size: %lld bytes\n", total_size);

  return EXIT_SUCCESS;
}