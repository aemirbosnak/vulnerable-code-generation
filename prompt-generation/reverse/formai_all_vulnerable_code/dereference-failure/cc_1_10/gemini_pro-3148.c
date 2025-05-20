//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>

// Define the maximum file size
#define MAX_FILE_SIZE 1024 * 1024 * 1024

// Define the backup directory
#define BACKUP_DIR "/backup"

// Define the number of backup generations to keep
#define NUM_BACKUP_GENERATIONS 5

// Define the time format for the backup file name
#define TIME_FORMAT "%Y-%m-%d_%H:%M:%S"

// Function to create a backup file
int create_backup(char *file_name) {
  // Get the current time
  time_t current_time;
  time(&current_time);

  // Create the backup file name
  char backup_file_name[256];
  strftime(backup_file_name, sizeof(backup_file_name), TIME_FORMAT, localtime(&current_time));
  strcat(backup_file_name, "_");
  strcat(backup_file_name, file_name);

  // Open the original file
  FILE *original_file = fopen(file_name, "rb");
  if (original_file == NULL) {
    perror("Error opening original file");
    return -1;
  }

  // Open the backup file
  FILE *backup_file = fopen(backup_file_name, "wb");
  if (backup_file == NULL) {
    perror("Error opening backup file");
    fclose(original_file);
    return -1;
  }

  // Copy the data from the original file to the backup file
  char buffer[MAX_FILE_SIZE];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, original_file)) > 0) {
    fwrite(buffer, 1, bytes_read, backup_file);
  }

  // Close the original file and the backup file
  fclose(original_file);
  fclose(backup_file);

  return 0;
}

// Function to delete old backup files
int delete_old_backup_files() {
  // Open the backup directory
  DIR *backup_dir = opendir(BACKUP_DIR);
  if (backup_dir == NULL) {
    perror("Error opening backup directory");
    return -1;
  }

  // Get the current time
  time_t current_time;
  time(&current_time);

  // Iterate over the files in the backup directory
  struct dirent *entry;
  while ((entry = readdir(backup_dir)) != NULL) {
    // Get the file name
    char file_name[256];
    strcpy(file_name, entry->d_name);

    // Get the file stats
    struct stat file_stats;
    if (stat(file_name, &file_stats) == -1) {
      perror("Error getting file stats");
      continue;
    }

    // Check if the file is a regular file
    if (!S_ISREG(file_stats.st_mode)) {
      continue;
    }

    // Check if the file is old enough to be deleted
    if (difftime(current_time, file_stats.st_mtime) > NUM_BACKUP_GENERATIONS * 24 * 60 * 60) {
      // Delete the file
      if (unlink(file_name) == -1) {
        perror("Error deleting file");
      }
    }
  }

  // Close the backup directory
  closedir(backup_dir);

  return 0;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the backup directory exists
  struct stat backup_dir_stats;
  if (stat(BACKUP_DIR, &backup_dir_stats) == -1) {
    // Create the backup directory
    if (mkdir(BACKUP_DIR, 0755) == -1) {
      perror("Error creating backup directory");
      return -1;
    }
  }

  // Check if the input file exists
  if (argc < 2) {
    printf("Usage: %s <file_name>\n", argv[0]);
    return -1;
  }

  // Create a backup of the input file
  if (create_backup(argv[1]) == -1) {
    return -1;
  }

  // Delete old backup files
  if (delete_old_backup_files() == -1) {
    return -1;
  }

  return 0;
}