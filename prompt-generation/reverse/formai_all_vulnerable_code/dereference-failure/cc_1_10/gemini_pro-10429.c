//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

// Define the maximum size of the backup file name
#define MAX_FILENAME_LENGTH 256

// Define the maximum number of files to backup
#define MAX_FILES_TO_BACKUP 100

// Define the default backup directory
#define DEFAULT_BACKUP_DIR "/tmp/backups"

// Define the file extension for backup files
#define BACKUP_FILE_EXTENSION ".bak"

// Function to get the current time in a string
char *get_current_time() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char *time_string = malloc(sizeof(char) * 256);
  strftime(time_string, 256, "%Y-%m-%d %H:%M:%S", tm);
  return time_string;
}

// Function to create a backup of a file
int create_backup(char *filename, char *backup_dir) {
  // Create the backup file name
  char backup_filename[MAX_FILENAME_LENGTH];
  snprintf(backup_filename, MAX_FILENAME_LENGTH, "%s/%s%s", backup_dir, filename, BACKUP_FILE_EXTENSION);

  // Open the original file
  FILE *original_file = fopen(filename, "rb");
  if (original_file == NULL) {
    return 1;
  }

  // Open the backup file
  FILE *backup_file = fopen(backup_filename, "wb");
  if (backup_file == NULL) {
    fclose(original_file);
    return 1;
  }

  // Copy the data from the original file to the backup file
  int c;
  while ((c = fgetc(original_file)) != EOF) {
    fputc(c, backup_file);
  }

  // Close the files
  fclose(original_file);
  fclose(backup_file);

  return 0;
}

// Function to backup a directory
int backup_directory(char *directory, char *backup_dir) {
  // Open the directory
  DIR *dir = opendir(directory);
  if (dir == NULL) {
    return 1;
  }

  // Create the backup directory if it doesn't exist
  struct stat st;
  if (stat(backup_dir, &st) == -1) {
    mkdir(backup_dir, 0755);
  }

  // Iterate over the files in the directory
  struct dirent *dirent;
  while ((dirent = readdir(dir)) != NULL) {
    // Skip the "." and ".." directories
    if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
      continue;
    }

    // Create a backup of the file
    char filename[MAX_FILENAME_LENGTH];
    snprintf(filename, MAX_FILENAME_LENGTH, "%s/%s", directory, dirent->d_name);
    create_backup(filename, backup_dir);
  }

  // Close the directory
  closedir(dir);

  return 0;
}

// Main function
int main(int argc, char *argv[]) {
  // Get the backup directory
  char *backup_dir = DEFAULT_BACKUP_DIR;
  if (argc > 1) {
    backup_dir = argv[1];
  }

  // Get the list of files to backup
  char *files_to_backup[MAX_FILES_TO_BACKUP];
  int num_files_to_backup = 0;
  if (argc > 2) {
    for (int i = 2; i < argc; i++) {
      files_to_backup[num_files_to_backup++] = argv[i];
    }
  }

  // Create a backup of the files
  if (num_files_to_backup > 0) {
    for (int i = 0; i < num_files_to_backup; i++) {
      create_backup(files_to_backup[i], backup_dir);
    }
  } else {
    // Backup the current directory
    backup_directory(".", backup_dir);
  }

  // Print the backup directory
  printf("Backups created in %s\n", backup_dir);

  return 0;
}