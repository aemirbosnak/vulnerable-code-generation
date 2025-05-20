//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to get the file size in bytes
long long get_file_size(char *file_path) {
  struct stat file_stat;
  if (stat(file_path, &file_stat) != 0) {
    printf("Error getting file size for %s", file_path);
    return -1;
  }
  return file_stat.st_size;
}

// Function to recursively calculate the total size of a directory
long long calculate_directory_size(char *directory_path) {
  long long total_size = 0;
  struct dirent *file;
  DIR *directory = opendir(directory_path);
  if (directory == NULL) {
    printf("Error opening directory %s", directory_path);
    return -1;
  }
  while ((file = readdir(directory)) != NULL) {
    char *file_name = file->d_name;
    char *full_file_path = malloc(strlen(directory_path) + strlen(file_name) + 2);
    sprintf(full_file_path, "%s/%s", directory_path, file_name);
    if (strcmp(file_name, ".") == 0 || strcmp(file_name, "..") == 0) {
      // Skip current and parent directories
      continue;
    }
    if (file->d_type == DT_DIR) {
      // Recursively calculate the size of subdirectories
      total_size += calculate_directory_size(full_file_path);
    } else {
      // Add the size of regular files
      total_size += get_file_size(full_file_path);
    }
    free(full_file_path);
  }
  closedir(directory);
  return total_size;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <directory_path>", argv[0]);
    return 1;
  }

  char *directory_path = argv[1];
  long long directory_size = calculate_directory_size(directory_path);
  if (directory_size == -1) {
    printf("Error calculating directory size");
    return 1;
  }

  printf("Total size of directory %s: %lld bytes\n", directory_path, directory_size);
  return 0;
}