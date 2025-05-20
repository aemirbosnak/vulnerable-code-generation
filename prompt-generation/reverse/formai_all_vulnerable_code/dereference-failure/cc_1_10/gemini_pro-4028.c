//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

typedef struct stat stat_t;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *dir_name = argv[1];
  DIR *dir = opendir(dir_name);
  if (dir == NULL) {
    perror(dir_name);
    return EXIT_FAILURE;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char *file_name = malloc(strlen(dir_name) + strlen(entry->d_name) + 2);
    sprintf(file_name, "%s/%s", dir_name, entry->d_name);

    stat_t buf;
    if (stat(file_name, &buf) == -1) {
      perror(file_name);
      free(file_name);
      continue;
    }

    if (S_ISDIR(buf.st_mode)) {
      printf("%s (directory)\n", file_name);
    } else {
      printf("%s (file, size: %ld bytes)\n", file_name, buf.st_size);
    }

    free(file_name);
  }

  closedir(dir);

  return EXIT_SUCCESS;
}