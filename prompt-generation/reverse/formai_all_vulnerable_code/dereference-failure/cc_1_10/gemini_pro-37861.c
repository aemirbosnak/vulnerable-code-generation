//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: cheerful
// Welcome to the jolly file backup system!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare some cheerful colors!
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define RESET "\x1B[0m"

// Let's backup some files!
void backup(char *filename) {
  // Check if the file exists
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf(RED "Oops! File '%s' not found. Skipping...\n" RESET, filename);
    return;
  }

  // Get the current time for the backup name
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char timestamp[20];
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H-%M-%S", tm);

  // Create the backup filename
  char backup_filename[50];
  sprintf(backup_filename, "%s_backup_%s.txt", filename, timestamp);

  // Open the backup file
  FILE *fp_backup = fopen(backup_filename, "w");
  if (fp_backup == NULL) {
    printf(RED "Oops! Could not create backup file '%s'. Skipping...\n" RESET, backup_filename);
    return;
  }

  // Copy the file contents
  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    fputs(buffer, fp_backup);
  }

  // Close the files
  fclose(fp);
  fclose(fp_backup);

  // Show a cheerful message!
  printf(GREEN "File '%s' backed up successfully to '%s'\n" RESET, filename, backup_filename);
}

// The main event where the magic happens!
int main() {
  // Let's backup some files!
  char files[][20] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};

  // Loop through the files and backup them!
  for (int i = 0; i < 5; i++) {
    backup(files[i]);
  }

  // Show a cheerful farewell message!
  printf(YELLOW "File backup complete! Rest assured, your precious files are safe.\n" RESET);
  return 0;
}