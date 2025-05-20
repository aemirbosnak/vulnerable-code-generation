//FormAI DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LEN 50
#define MAX_BACKUP_FILES 10
#define MAX_BACKUP_PATH_LEN 100

// Define a struct to hold information about backup files
struct BackupFileInfo {
  char filename[MAX_FILENAME_LEN];
  time_t modification_time;
};

int main() {
  // Define variables
  char filename[MAX_FILENAME_LEN];
  char backup_path[MAX_BACKUP_PATH_LEN];
  time_t current_time;
  struct tm *current_time_info;
  int backup_count = 0;
  struct BackupFileInfo backup_files[MAX_BACKUP_FILES];

  printf("Welcome to the C File Backup System!\n");

  // Get the filename to backup
  printf("\nEnter the filename to backup: ");
  fgets(filename, MAX_FILENAME_LEN, stdin);
  filename[strcspn(filename, "\n")] = '\0'; // Remove newline character from input

  // Get the backup path
  printf("\nEnter the backup path: ");
  fgets(backup_path, MAX_BACKUP_PATH_LEN, stdin);
  backup_path[strcspn(backup_path, "\n")] = '\0'; // Remove newline character from input

  // Open the file to backup
  FILE *original_file = fopen(filename, "r");
  if (original_file == NULL) {
    printf("Error: Unable to open file.\n");
    exit(1);
  }

  // Copy the contents of the original file to the backup file
  char backup_filename[MAX_FILENAME_LEN + 20];
  sprintf(backup_filename, "%s/%s.%d", backup_path, filename, backup_count);
  FILE *backup_file = fopen(backup_filename, "w");
  if (backup_file == NULL) {
    printf("Error: Unable to create backup file.\n");
    exit(1);
  }

  int c;
  while ((c = fgetc(original_file)) != EOF) {
    fputc(c, backup_file);
  }

  // Close the original and backup files
  fclose(original_file);
  fclose(backup_file);

  // Record information about the backup file
  struct tm *modification_time_info;
  time(&current_time);
  current_time_info = localtime(&current_time);

  backup_files[backup_count].modification_time = current_time;
  backup_files[backup_count].filename[0] = '\0';

  modification_time_info = localtime(&backup_files[backup_count].modification_time);

  strftime(backup_files[backup_count].filename, sizeof(backup_files[backup_count].filename), "%d-%m-%Y %H:%M:%S", modification_time_info); 
  strcat(backup_files[backup_count].filename, ".bak");

  // Print information about the backup file
  printf("\nBackup complete!\n");
  printf("Filename: %s/%s\n", backup_path, backup_filename);
  printf("Modification Time: %s\n", asctime(modification_time_info));

  backup_count++;

  return 0;
}