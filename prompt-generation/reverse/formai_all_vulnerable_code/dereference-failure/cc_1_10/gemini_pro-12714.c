//GEMINI-pro DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

void list_files(const char *path) {
  DIR *dir = opendir(path);
  if (dir == NULL) {
    perror("opendir");
    return;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
    if (full_path == NULL) {
      perror("malloc");
      closedir(dir);
      return;
    }

    strcpy(full_path, path);
    strcat(full_path, "/");
    strcat(full_path, entry->d_name);

    struct stat statbuf;
    if (stat(full_path, &statbuf) == -1) {
      perror("stat");
      free(full_path);
      closedir(dir);
      return;
    }

    if (S_ISDIR(statbuf.st_mode)) {
      list_files(full_path);
    } else {
      printf("%s\n", full_path);
    }

    free(full_path);
  }

  closedir(dir);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <path>\n", argv[0]);
    return EXIT_FAILURE;
  }

  list_files(argv[1]);

  return EXIT_SUCCESS;
}