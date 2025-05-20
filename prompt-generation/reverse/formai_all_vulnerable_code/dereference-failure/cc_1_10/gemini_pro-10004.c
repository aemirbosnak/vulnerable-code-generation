//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store file information
typedef struct file_info {
  char* name;
  char* path;
  int size;
} file_info;

// Function to get file information
file_info* get_file_info(char* path) {
  // Allocate memory for file information
  file_info* info = malloc(sizeof(file_info));

  // Get file name
  char* filename = strrchr(path, '/');
  if (filename == NULL) {
    filename = path;
  } else {
    filename++;
  }
  info->name = strdup(filename);

  // Get file path
  info->path = strdup(path);

  // Get file size
  FILE* file = fopen(path, "rb");
  if (file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }
  fseek(file, 0, SEEK_END);
  info->size = ftell(file);
  fclose(file);

  // Return file information
  return info;
}

// Function to create a backup of a file
void backup_file(file_info* info, char* backup_path) {
  // Open the original file
  FILE* original = fopen(info->path, "rb");
  if (original == NULL) {
    perror("Error opening original file");
    exit(EXIT_FAILURE);
  }

  // Open the backup file
  FILE* backup = fopen(backup_path, "wb");
  if (backup == NULL) {
    perror("Error opening backup file");
    exit(EXIT_FAILURE);
  }

  // Copy the file contents
  char buffer[1024];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, sizeof(buffer), original)) > 0) {
    fwrite(buffer, 1, bytes_read, backup);
  }

  // Close the files
  fclose(original);
  fclose(backup);
}

// Function to restore a file from a backup
void restore_file(file_info* info, char* backup_path) {
  // Open the backup file
  FILE* backup = fopen(backup_path, "rb");
  if (backup == NULL) {
    perror("Error opening backup file");
    exit(EXIT_FAILURE);
  }

  // Open the original file
  FILE* original = fopen(info->path, "wb");
  if (original == NULL) {
    perror("Error opening original file");
    exit(EXIT_FAILURE);
  }

  // Copy the file contents
  char buffer[1024];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, sizeof(buffer), backup)) > 0) {
    fwrite(buffer, 1, bytes_read, original);
  }

  // Close the files
  fclose(backup);
  fclose(original);
}

// Function to delete a file backup
void delete_file_backup(char* backup_path) {
  // Delete the backup file
  if (remove(backup_path) != 0) {
    perror("Error deleting backup file");
    exit(EXIT_FAILURE);
  }
}

// Function to print file information
void print_file_info(file_info* info) {
  printf("File name: %s\n", info->name);
  printf("File path: %s\n", info->path);
  printf("File size: %d bytes\n", info->size);
}

// Function to print usage information
void print_usage() {
  printf("Usage: %s <command> <file> <backup file>\n", "file_backup");
  printf("Commands:\n");
  printf("  backup: Create a backup of a file.\n");
  printf("  restore: Restore a file from a backup.\n");
  printf("  delete: Delete a file backup.\n");
  printf("  info: Print information about a file.\n");
}

// Main function
int main(int argc, char* argv[]) {
  // Check for the correct number of arguments
  if (argc != 4) {
    print_usage();
    exit(EXIT_FAILURE);
  }

  // Get the command
  char* command = argv[1];

  // Get the file path
  char* path = argv[2];

  // Get the backup file path
  char* backup_path = argv[3];

  // Get file information
  file_info* info = get_file_info(path);

  // Execute the command
  if (strcmp(command, "backup") == 0) {
    backup_file(info, backup_path);
  } else if (strcmp(command, "restore") == 0) {
    restore_file(info, backup_path);
  } else if (strcmp(command, "delete") == 0) {
    delete_file_backup(backup_path);
  } else if (strcmp(command, "info") == 0) {
    print_file_info(info);
  } else {
    print_usage();
    exit(EXIT_FAILURE);
  }

  // Free the allocated memory
  free(info->name);
  free(info->path);
  free(info);

  return EXIT_SUCCESS;
}