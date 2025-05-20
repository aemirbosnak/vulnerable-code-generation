//FormAI DATASET v1.0 Category: File Backup System ; Style: Ken Thompson
// Ken Thompson Style C File Backup System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int backup_file(char* filename) {
  // Append "_bak_" and current time to the original filename
  char new_filename[256];
  memset(new_filename, 0, sizeof(new_filename));
  sprintf(new_filename, "%s_bak_%ld", filename, (long)time(NULL));

  // Open the original file
  FILE* original_file = fopen(filename, "r");
  if (original_file == NULL) {
    printf("Error: Could not open file %s", filename);
    return -1;
  }

  // Open the backup file
  FILE* backup_file = fopen(new_filename, "w");
  if (backup_file == NULL) {
    printf("Error: Could not create backup file %s", new_filename);
    return -1;
  }

  // Copy the contents of original file to backup file
  char buffer[1024];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, sizeof(buffer), original_file)) > 0) {
    fwrite(buffer, 1, bytes_read, backup_file);
  }

  // Close files
  fclose(original_file);
  fclose(backup_file);

  return 0;
}

int main(int argc, char* argv[]) {
  // Check if filename is provided
  if (argc < 2) {
    printf("Usage: %s filename\n", argv[0]);
    return -1;
  }

  char* filename = argv[1];

  // Backup the file
  if (backup_file(filename) == 0) {
    printf("File %s backed up successfully\n", filename);
  } else {
    printf("Error: Failed to backup file %s\n", filename);
  }

  return 0;
}