//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: excited
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main() {
  // Declare variables
  DIR *dir;
  struct dirent *entry;
  char path[255];
  long long int total_size = 0;

  // Get the current working directory
  getcwd(path, sizeof(path));

  // Open the directory
  dir = opendir(path);
  if (dir == NULL) {
    perror("Error opening directory");
    return EXIT_FAILURE;
  }

  // Read the directory and calculate the total size
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    // Get the file size
    long long int file_size = 0;
    FILE *file = fopen(entry->d_name, "r");
    if (file != NULL) {
      fseek(file, 0, SEEK_END);
      file_size = ftell(file);
      fclose(file);
    } else {
      printf("Error opening file: %s\n", entry->d_name);
      continue;
    }

    // Add the file size to the total size
    total_size += file_size;
  }

  // Close the directory
  closedir(dir);

  // Print the total size
  printf("The total size of the directory '%s' is: %lld bytes\n", path, total_size);

  // Convert the total size to megabytes
  long long int total_size_mb = total_size / (1024 * 1024);

  // Print the total size in megabytes
  printf("The total size of the directory '%s' is: %lld megabytes\n", path, total_size_mb);

  return EXIT_SUCCESS;
}