//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

// Define the maximum length of file names
#define MAX_FILE_NAME_LENGTH 256

// Define the maximum number of files to backup
#define MAX_FILES_TO_BACKUP 10

// Define the backup directory
#define BACKUP_DIRECTORY "/backup"

// Define the file extension to backup
#define FILE_EXTENSION ".txt"

// Function to check if a file exists
int file_exists(const char *filename) {
  struct stat buf;
  return (stat(filename, &buf) == 0);
}

// Function to create a directory
int create_directory(const char *directory) {
  int status = mkdir(directory, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  return (status == 0);
}

// Function to copy a file
int copy_file(const char *source, const char *destination) {
  // Open the source file
  FILE *source_file = fopen(source, "r");
  if (source_file == NULL) {
    return 0;
  }

  // Open the destination file
  FILE *destination_file = fopen(destination, "w");
  if (destination_file == NULL) {
    fclose(source_file);
    return 0;
  }

  // Copy the file contents
  char buffer[1024];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
    fwrite(buffer, 1, bytes_read, destination_file);
  }

  // Close the files
  fclose(source_file);
  fclose(destination_file);

  return 1;
}

// Function to backup files
int backup_files(const char *directory) {
  // Create the backup directory if it doesn't exist
  if (!file_exists(BACKUP_DIRECTORY)) {
    if (!create_directory(BACKUP_DIRECTORY)) {
      return 0;
    }
  }

  // Get a list of files in the directory
  DIR *dir = opendir(directory);
  if (dir == NULL) {
    return 0;
  }

  // Loop through the files
  struct dirent *entry;
  int file_count = 0;
  while ((entry = readdir(dir)) != NULL) {
    // Check if the file is a regular file and has the correct file extension
    if (entry->d_type == DT_REG && strcmp(strrchr(entry->d_name, '.'), FILE_EXTENSION) == 0) {
      // Create the backup file name
      char backup_file_name[MAX_FILE_NAME_LENGTH];
      snprintf(backup_file_name, MAX_FILE_NAME_LENGTH, "%s/%s", BACKUP_DIRECTORY, entry->d_name);

      // Copy the file
      if (!copy_file(entry->d_name, backup_file_name)) {
        return 0;
      }

      // Increment the file count
      file_count++;

      // Check if the maximum number of files has been backed up
      if (file_count >= MAX_FILES_TO_BACKUP) {
        break;
      }
    }
  }

  // Close the directory
  closedir(dir);

  return 1;
}

// Main function
int main(void) {
  // Get the current working directory
  char cwd[MAX_FILE_NAME_LENGTH];
  if (getcwd(cwd, sizeof(cwd)) == NULL) {
    return 1;
  }

  // Backup the files in the current working directory
  if (!backup_files(cwd)) {
    return 1;
  }

  // Print a success message
  printf("Files backed up successfully!\n");

  return 0;
}