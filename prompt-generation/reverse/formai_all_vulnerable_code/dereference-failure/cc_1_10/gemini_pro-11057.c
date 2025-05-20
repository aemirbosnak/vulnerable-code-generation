//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of a file name
#define MAX_FILE_NAME_SIZE 256

// Define the maximum number of files to backup
#define MAX_FILES 10

// Define the maximum size of a file
#define MAX_FILE_SIZE 1024

// Define the backup directory
#define BACKUP_DIR "backup"

// Define the file extension for backup files
#define BACKUP_EXT ".bak"

// Define the buffer size for reading/writing files
#define BUFFER_SIZE 1024

// Function to create a backup directory
void create_backup_dir() {
  // Check if the backup directory already exists
  if (mkdir(BACKUP_DIR, 0777) == -1) {
    // If the directory does not exist, create it
    perror("Error creating backup directory");
    exit(EXIT_FAILURE);
  }
}

// Function to get the current date and time
void get_date_time(char *date_time) {
  // Get the current time
  time_t t = time(NULL);

  // Convert the time to a string
  strftime(date_time, sizeof(date_time), "%Y-%m-%d %H:%M:%S", localtime(&t));
}

// Function to backup a file
void backup_file(char *file_name) {
  // Open the file to be backed up
  FILE *file = fopen(file_name, "rb");
  if (file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  // Get the current date and time
  char date_time[256];
  get_date_time(date_time);

  // Create the backup file name
  char backup_file_name[MAX_FILE_NAME_SIZE];
  snprintf(backup_file_name, sizeof(backup_file_name), "%s/%s-%s%s", BACKUP_DIR, file_name, date_time, BACKUP_EXT);

  // Open the backup file
  FILE *backup_file = fopen(backup_file_name, "wb");
  if (backup_file == NULL) {
    perror("Error opening backup file");
    exit(EXIT_FAILURE);
  }

  // Buffer for reading and writing
  char buffer[BUFFER_SIZE];

  // Read the file to be backed up and write it to the backup file
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
    fwrite(buffer, 1, bytes_read, backup_file);
  }

  // Close the files
  fclose(file);
  fclose(backup_file);

  // Print a message to indicate that the file has been backed up
  printf("File \"%s\" backed up to \"%s\"\n", file_name, backup_file_name);
}

// Function to backup multiple files
void backup_files(char *file_names[], int num_files) {
  // Create the backup directory if it does not exist
  create_backup_dir();

  // Backup each file
  for (int i = 0; i < num_files; i++) {
    backup_file(file_names[i]);
  }
}

// Main function
int main() {
  // Define the file names to be backed up
  char *file_names[] = {"file1.txt", "file2.txt", "file3.txt"};

  // Backup the files
  backup_files(file_names, sizeof(file_names) / sizeof(char *));

  return 0;
}