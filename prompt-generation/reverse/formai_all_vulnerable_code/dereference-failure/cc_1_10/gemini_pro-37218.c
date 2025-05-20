//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to get the file metadata
void get_file_metadata(const char *filename) {
  struct stat file_stat;
  if (stat(filename, &file_stat) < 0) {
    perror("stat");
    exit(1);
  }

  // Print the file metadata
  printf("File: %s\n", filename);
  printf("Size: %ld bytes\n", file_stat.st_size);
  printf("Permissions: %o\n", file_stat.st_mode);
  printf("Last modified: %s", ctime(&file_stat.st_mtime));
}

// Function to get the directory metadata
void get_directory_metadata(const char *dirname) {
  DIR *dir;
  struct dirent *entry;
  if (!(dir = opendir(dirname))) {
    perror("opendir");
    exit(1);
  }

  // Iterate over the directory entries and print the metadata
  while ((entry = readdir(dir)) != NULL) {
    char filepath[strlen(dirname) + strlen(entry->d_name) + 2];
    strcpy(filepath, dirname);
    strcat(filepath, "/");
    strcat(filepath, entry->d_name);

    if (entry->d_type == DT_DIR) {
      printf("Directory: %s\n", filepath);
      get_directory_metadata(filepath);
    } else if (entry->d_type == DT_REG) {
      printf("File: %s\n", filepath);
      get_file_metadata(filepath);
    }
  }

  // Close the directory
  closedir(dir);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <path>\n", argv[0]);
    exit(1);
  }

  // Get the metadata for the specified path
  if (access(argv[1], F_OK) == 0) {
    struct stat file_stat;
    if (stat(argv[1], &file_stat) < 0) {
      perror("stat");
      exit(1);
    }

    if (S_ISDIR(file_stat.st_mode)) {
      printf("Directory: %s\n", argv[1]);
      get_directory_metadata(argv[1]);
    } else if (S_ISREG(file_stat.st_mode)) {
      printf("File: %s\n", argv[1]);
      get_file_metadata(argv[1]);
    } else {
      printf("Invalid path: %s\n", argv[1]);
    }
  } else {
    printf("Path does not exist: %s\n", argv[1]);
  }

  return 0;
}