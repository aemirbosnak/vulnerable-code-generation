//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Define the maximum size of the file buffer
#define BUFFER_SIZE 1024

// Define the maximum number of backup files to keep
#define MAX_BACKUP_FILES 5

// Define the format of the backup filename
#define BACKUP_FILENAME_FORMAT "%s.%s.%s"

// Define the supported file extensions
char *supported_extensions[] = {".txt", ".cpp", ".h", ".py", ".java", ".rb", ".php", ".js", ".html", ".css"};

// Declare the main function
int main(int argc, char *argv[]) {
  // Check if the user specified a file to backup
  if (argc < 2) {
    printf("Usage: %s <file_to_backup>\n", argv[0]);
    return 1;
  }

  // Get the file to backup
  char *file_to_backup = argv[1];

  // Get the file extension
  char *file_extension = strrchr(file_to_backup, '.');

  // Check if the file extension is supported
  int is_supported_extension = 0;
  for (int i = 0; i < sizeof(supported_extensions) / sizeof(char *); i++) {
    if (strcmp(file_extension, supported_extensions[i]) == 0) {
      is_supported_extension = 1;
      break;
    }
  }

  // If the file extension is not supported, display an error message and exit
  if (!is_supported_extension) {
    printf("Error: The file extension is not supported.\n");
    return 1;
  }

  // Get the current time
  time_t current_time = time(NULL);

  // Format the current time as a string
  char current_time_string[32];
  strftime(current_time_string, 32, "%Y-%m-%d_%H-%M-%S", localtime(&current_time));

  // Create the backup filename
  char backup_filename[128];
  sprintf(backup_filename, BACKUP_FILENAME_FORMAT, file_to_backup, current_time_string, file_extension);

  // Open the file to backup
  FILE *file = fopen(file_to_backup, "rb");

  // Check if the file could be opened
  if (file == NULL) {
    printf("Error: Could not open the file to backup.\n");
    return 1;
  }

  // Open the backup file
  FILE *backup_file = fopen(backup_filename, "wb");

  // Check if the backup file could be opened
  if (backup_file == NULL) {
    printf("Error: Could not open the backup file.\n");
    fclose(file);
    return 1;
  }

  // Read the file to backup in chunks of BUFFER_SIZE bytes
  char buffer[BUFFER_SIZE];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
    // Write the chunk to the backup file
    fwrite(buffer, 1, bytes_read, backup_file);
  }

  // Close the files
  fclose(file);
  fclose(backup_file);

  // Delete the oldest backup file if the maximum number of backup files has been exceeded
  if (access(backup_filename, F_OK) == 0) {
    // Get the oldest backup file
    char oldest_backup_filename[128];
    sprintf(oldest_backup_filename, BACKUP_FILENAME_FORMAT, file_to_backup, "oldest", file_extension);

    // Rename the oldest backup file to the new backup file
    rename(backup_filename, oldest_backup_filename);

    // Get the second oldest backup file
    char second_oldest_backup_filename[128];
    sprintf(second_oldest_backup_filename, BACKUP_FILENAME_FORMAT, file_to_backup, "second_oldest", file_extension);

    // Delete the second oldest backup file
    remove(second_oldest_backup_filename);
  }

  // Display a success message
  printf("File backed up successfully.\n");

  return 0;
}