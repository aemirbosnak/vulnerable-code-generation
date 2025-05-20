//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_PATH_LENGTH 1024

// Function to calculate the size of a file or directory
long get_size(const char *path) {
  struct stat buf;
  if (stat(path, &buf) == -1) {
    perror("stat");
    return -1;
  }
  return buf.st_size;
}

// Function to recursively traverse a directory and calculate its size
long get_directory_size(const char *path) {
  DIR *dir;
  struct dirent *entry;
  long size = 0;

  dir = opendir(path);
  if (dir == NULL) {
    perror("opendir");
    return -1;
  }

  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char new_path[MAX_PATH_LENGTH];
    snprintf(new_path, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);

    if (entry->d_type == DT_DIR) {
      size += get_directory_size(new_path);
    } else {
      size += get_size(new_path);
    }
  }

  closedir(dir);

  return size;
}

// Function to print the size of a file or directory in a human-readable format
void print_size(const char *path, long size) {
  if (size < 1024) {
    printf("%s: %ld bytes\n", path, size);
  } else if (size < 1048576) {
    printf("%s: %.2f KB\n", path, (double)size / 1024);
  } else if (size < 1073741824) {
    printf("%s: %.2f MB\n", path, (double)size / 1048576);
  } else {
    printf("%s: %.2f GB\n", path, (double)size / 1073741824);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <path>\n", argv[0]);
    return EXIT_FAILURE;
  }

  long size = get_directory_size(argv[1]);
  if (size == -1) {
    perror("get_directory_size");
    return EXIT_FAILURE;
  }

  print_size(argv[1], size);

  return EXIT_SUCCESS;
}