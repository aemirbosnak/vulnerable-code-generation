//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of files to be backed up
#define MAX_FILES 10

// Define the maximum size of each file to be backed up
#define MAX_FILE_SIZE 1024

// Define the backup directory
#define BACKUP_DIR "backup"

// Function to create a backup directory
void create_backup_dir() {
  // Check if the backup directory already exists
  if (mkdir(BACKUP_DIR, 0755) == -1) {
    // If the backup directory does not exist, create it
    printf("Backup directory created successfully.\n");
  } else {
    // If the backup directory already exists, print a message
    printf("Backup directory already exists.\n");
  }
}

// Function to get the current time in a string
char *get_current_time() {
  // Get the current time
  time_t current_time = time(NULL);

  // Convert the current time to a string
  char *current_time_str = ctime(&current_time);

  // Remove the newline character from the string
  current_time_str[strlen(current_time_str) - 1] = '\0';

  // Return the current time string
  return current_time_str;
}

// Function to create a backup file
void create_backup_file(char *file_name) {
  // Open the file to be backed up
  FILE *file = fopen(file_name, "rb");

  // Check if the file was opened successfully
  if (file == NULL) {
    // If the file was not opened successfully, print an error message
    printf("Error opening file %s.\n", file_name);
    return;
  }

  // Get the current time
  char *current_time = get_current_time();

  // Create the backup file name
  char backup_file_name[strlen(BACKUP_DIR) + strlen("/") + strlen(file_name) + strlen(current_time) + 1];
  sprintf(backup_file_name, "%s/%s-%s", BACKUP_DIR, file_name, current_time);

  // Open the backup file
  FILE *backup_file = fopen(backup_file_name, "wb");

  // Check if the backup file was opened successfully
  if (backup_file == NULL) {
    // If the backup file was not opened successfully, print an error message
    printf("Error opening backup file %s.\n", backup_file_name);
    return;
  }

  // Read the file to be backed up
  char buffer[MAX_FILE_SIZE];
  size_t bytes_read;

  while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file)) > 0) {
    // Write the file to the backup file
    fwrite(buffer, sizeof(char), bytes_read, backup_file);
  }

  // Close the file to be backed up
  fclose(file);

  // Close the backup file
  fclose(backup_file);

  // Print a message
  printf("Backup file %s created successfully.\n", backup_file_name);
}

// Function to backup multiple files
void backup_files(char *file_names[], int num_files) {
  // Create the backup directory
  create_backup_dir();

  // Iterate over the files to be backed up
  for (int i = 0; i < num_files; i++) {
    // Create a backup file
    create_backup_file(file_names[i]);
  }
}

// Main function
int main() {
  // Define the files to be backed up
  char *file_names[] = {
    "file1.txt",
    "file2.txt",
    "file3.txt",
    "file4.txt",
    "file5.txt",
  };

  // Get the number of files to be backed up
  int num_files = sizeof(file_names) / sizeof(char *);

  // Backup the files
  backup_files(file_names, num_files);

  return 0;
}