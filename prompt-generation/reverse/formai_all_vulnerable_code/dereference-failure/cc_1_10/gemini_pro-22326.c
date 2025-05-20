//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum file size
#define MAX_FILE_SIZE 1024 * 1024

// Define the number of backup generations to keep
#define NUM_BACKUP_GENERATIONS 5

// Define the file extension for backup files
#define BACKUP_FILE_EXTENSION ".bak"

// Get the current date and time as a string
char *get_current_date_time() {
  time_t now = time(NULL);
  struct tm *tm = localtime(&now);
  char *date_time = malloc(100);
  strftime(date_time, 100, "%Y-%m-%d %H:%M:%S", tm);
  return date_time;
}

// Create a backup of the specified file
int create_backup(char *filename) {
  // Get the current date and time
  char *date_time = get_current_date_time();

  // Create the backup filename
  char backup_filename[100];
  snprintf(backup_filename, 100, "%s%s%s", filename, BACKUP_FILE_EXTENSION, date_time);

  // Open the original file
  FILE *original_file = fopen(filename, "rb");
  if (original_file == NULL) {
    printf("Error opening file %s\n", filename);
    return -1;
  }

  // Open the backup file
  FILE *backup_file = fopen(backup_filename, "wb");
  if (backup_file == NULL) {
    printf("Error opening file %s\n", backup_filename);
    fclose(original_file);
    return -1;
  }

  // Copy the data from the original file to the backup file
  char buffer[MAX_FILE_SIZE];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, original_file)) > 0) {
    fwrite(buffer, 1, bytes_read, backup_file);
  }

  // Close the files
  fclose(original_file);
  fclose(backup_file);

  // Free the date and time string
  free(date_time);

  return 0;
}

// Delete the oldest backup of the specified file
int delete_oldest_backup(char *filename) {
  // Get a list of all the backup files for the specified file
  char command[100];
  snprintf(command, 100, "ls -t %s%s | tail -n +6", filename, BACKUP_FILE_EXTENSION);
  FILE *pipe = popen(command, "r");
  if (pipe == NULL) {
    printf("Error getting list of backup files\n");
    return -1;
  }

  // Get the oldest backup filename
  char oldest_backup_filename[100];
  fgets(oldest_backup_filename, 100, pipe);
  pclose(pipe);

  // Delete the oldest backup file
  if (remove(oldest_backup_filename) != 0) {
    printf("Error deleting file %s\n", oldest_backup_filename);
    return -1;
  }

  return 0;
}

// Perform a backup of all the files in the specified directory
int backup_directory(char *directory) {
  // Get a list of all the files in the specified directory
  char command[100];
  snprintf(command, 100, "find %s -type f", directory);
  FILE *pipe = popen(command, "r");
  if (pipe == NULL) {
    printf("Error getting list of files in directory %s\n", directory);
    return -1;
  }

  // Create a backup of each file
  char filename[100];
  while (fgets(filename, 100, pipe) != NULL) {
    // Remove the newline character from the filename
    filename[strlen(filename) - 1] = '\0';

    // Create a backup of the file
    if (create_backup(filename) != 0) {
      printf("Error creating backup of file %s\n", filename);
      pclose(pipe);
      return -1;
    }

    // Delete the oldest backup of the file
    if (delete_oldest_backup(filename) != 0) {
      printf("Error deleting oldest backup of file %s\n", filename);
      pclose(pipe);
      return -1;
    }
  }

  // Close the pipe
  pclose(pipe);

  return 0;
}

// Main function
int main() {
  // Get the current directory
  char directory[100];
  getcwd(directory, 100);

  // Perform a backup of all the files in the current directory
  if (backup_directory(directory) != 0) {
    printf("Error backing up files in directory %s\n", directory);
    return -1;
  }

  return 0;
}