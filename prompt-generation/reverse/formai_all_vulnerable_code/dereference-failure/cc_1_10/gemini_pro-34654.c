//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define BUF_SIZE 4096
#define MAX_PATH_LEN 256

// Function to display the usage of the program
void display_usage() {
  printf("Usage: filebackup <source directory> <destination directory>\n");
}

// Function to recursively copy a directory
int copy_directory(char *source_dir, char *dest_dir) {
  DIR *source = opendir(source_dir);
  if (source == NULL) {
    perror("Error opening source directory");
    return -1;
  }

  // Create the destination directory if it doesn't exist
  if (mkdir(dest_dir, 0755) != 0) {
    perror("Error creating destination directory");
    closedir(source);
    return -1;
  }

  // Iterate over the files in the source directory
  struct dirent *dirent;
  while ((dirent = readdir(source)) != NULL) {
    // Skip hidden files and directories
    if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
      continue;
    }

    // Get the full path of the source and destination files
    char source_path[MAX_PATH_LEN];
    snprintf(source_path, MAX_PATH_LEN, "%s/%s", source_dir, dirent->d_name);
    char dest_path[MAX_PATH_LEN];
    snprintf(dest_path, MAX_PATH_LEN, "%s/%s", dest_dir, dirent->d_name);

    // Check if the source file is a directory
    struct stat statbuf;
    if (stat(source_path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
      // Recursively copy the directory
      if (copy_directory(source_path, dest_path) != 0) {
        closedir(source);
        return -1;
      }
    } else {
      // Copy the file
      if (copy_file(source_path, dest_path) != 0) {
        closedir(source);
        return -1;
      }
    }
  }

  closedir(source);
  return 0;
}

// Function to copy a file
int copy_file(char *source_path, char *dest_path) {
  FILE *source = fopen(source_path, "rb");
  if (source == NULL) {
    perror("Error opening source file");
    return -1;
  }

  FILE *dest = fopen(dest_path, "wb");
  if (dest == NULL) {
    fclose(source);
    perror("Error opening destination file");
    return -1;
  }

  // Copy the file data in chunks
  char buffer[BUF_SIZE];
  size_t bytes_read, bytes_written;
  while ((bytes_read = fread(buffer, 1, BUF_SIZE, source)) > 0) {
    bytes_written = fwrite(buffer, 1, bytes_read, dest);
    if (bytes_written != bytes_read) {
      fclose(source);
      fclose(dest);
      perror("Error writing to destination file");
      return -1;
    }
  }

  fclose(source);
  fclose(dest);
  return 0;
}

// Main function
int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 3) {
    display_usage();
    return -1;
  }

  // Get the source and destination directories
  char *source_dir = argv[1];
  char *dest_dir = argv[2];

  // Check if the source directory exists
  struct stat statbuf;
  if (stat(source_dir, &statbuf) != 0 || !S_ISDIR(statbuf.st_mode)) {
    printf("Error: Source directory '%s' does not exist or is not a directory\n", source_dir);
    return -1;
  }

  // Check if the destination directory exists
  if (stat(dest_dir, &statbuf) != 0 || !S_ISDIR(statbuf.st_mode)) {
    printf("Error: Destination directory '%s' does not exist or is not a directory\n", dest_dir);
    return -1;
  }

  // Copy the directory
  if (copy_directory(source_dir, dest_dir) != 0) {
    printf("Error: Failed to copy directory '%s' to '%s'\n", source_dir, dest_dir);
    return -1;
  }

  printf("Directory '%s' successfully copied to '%s'\n", source_dir, dest_dir);
  return 0;
}