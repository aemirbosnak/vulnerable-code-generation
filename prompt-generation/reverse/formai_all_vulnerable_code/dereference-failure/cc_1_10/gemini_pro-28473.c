//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *source_directory = argv[1];
  char *destination_directory = argv[2];

  // Create the destination directory if it doesn't exist.
  if (mkdir(destination_directory, 0755) != 0) {
    perror("Error creating destination directory");
    return EXIT_FAILURE;
  }

  // Open the source directory.
  DIR *source_dir = opendir(source_directory);
  if (source_dir == NULL) {
    perror("Error opening source directory");
    return EXIT_FAILURE;
  }

  // Iterate over the files in the source directory.
  struct dirent *source_file;
  while ((source_file = readdir(source_dir)) != NULL) {
    // Skip hidden files.
    if (source_file->d_name[0] == '.') {
      continue;
    }

    // Get the source file path.
    char *source_file_path = malloc(strlen(source_directory) + strlen(source_file->d_name) + 1);
    strcpy(source_file_path, source_directory);
    strcat(source_file_path, "/");
    strcat(source_file_path, source_file->d_name);

    // Get the destination file path.
    char *destination_file_path = malloc(strlen(destination_directory) + strlen(source_file->d_name) + 1);
    strcpy(destination_file_path, destination_directory);
    strcat(destination_file_path, "/");
    strcat(destination_file_path, source_file->d_name);

    // Check if the destination file exists.
    if (access(destination_file_path, F_OK) == 0) {
      // If the destination file exists, compare its timestamp with the source file's timestamp.
      struct stat source_file_stat;
      struct stat destination_file_stat;
      if (stat(source_file_path, &source_file_stat) != 0) {
        perror("Error getting source file stats");
        return EXIT_FAILURE;
      }
      if (stat(destination_file_path, &destination_file_stat) != 0) {
        perror("Error getting destination file stats");
        return EXIT_FAILURE;
      }

      if (source_file_stat.st_mtime > destination_file_stat.st_mtime) {
        // If the source file is newer, copy it to the destination.
        if (copy_file(source_file_path, destination_file_path) != 0) {
          perror("Error copying file");
          return EXIT_FAILURE;
        }
      }
    } else {
      // If the destination file doesn't exist, copy the source file to the destination.
      if (copy_file(source_file_path, destination_file_path) != 0) {
        perror("Error copying file");
        return EXIT_FAILURE;
      }
    }

    // Free the allocated memory.
    free(source_file_path);
    free(destination_file_path);
  }

  // Close the source directory.
  closedir(source_dir);

  return EXIT_SUCCESS;
}

int copy_file(char *source_file_path, char *destination_file_path) {
  // Open the source file.
  FILE *source_file = fopen(source_file_path, "rb");
  if (source_file == NULL) {
    perror("Error opening source file");
    return EXIT_FAILURE;
  }

  // Open the destination file.
  FILE *destination_file = fopen(destination_file_path, "wb");
  if (destination_file == NULL) {
    perror("Error opening destination file");
    return EXIT_FAILURE;
  }

  // Copy the file contents.
  int c;
  while ((c = fgetc(source_file)) != EOF) {
    fputc(c, destination_file);
  }

  // Close the files.
  fclose(source_file);
  fclose(destination_file);

  return EXIT_SUCCESS;
}