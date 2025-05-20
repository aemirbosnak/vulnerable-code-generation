//FormAI DATASET v1.0 Category: File Backup System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare function to backup file
void backupFile(char* filename);

int main(int argc, char** argv) {

  // Check if the user entered a filename
  if (argc < 2) {
    printf("Sorry, you need to specify a filename to backup.\n");
    exit(1);
  }

  // Backup each file specified by the user
  for (int i = 1; i < argc; i++) {
    backupFile(argv[i]);
  }

  // Let the user know their files have been backed up
  printf("Your files have been surreally backed up!\n");

  return 0;
}

// Define backupFile() function
void backupFile(char* filename) {

  // Variables to hold file information
  FILE* original;
  FILE* backup;
  char* backupName = malloc(strlen(filename)+8);

  // Create backup file name with surrealistic twist
  sprintf(backupName, "%s_backup.txt", filename);

  // Open the original file
  original = fopen(filename, "r");
  if (original == NULL) {
    printf("Sorry, couldn't open %s for backup.\n", filename);
    return;
  }

  // Open the backup file
  backup = fopen(backupName, "w");
  if (backup == NULL) {
    printf("Sorry, couldn't open %s for writing.\n", backupName);
    return;
  }

  // Copy the contents of the original file to the backup file
  int c;
  while ((c = fgetc(original)) != EOF) {
    fputc(c, backup);
  }

  // Close both files
  fclose(original);
  fclose(backup);

  // Let the user know that their file has been backed up
  printf("The contents of %s have been surreally copied to %s_backup.txt.\n", filename, filename);
  printf("Do not question the surrealist nature of the backup!\n");

  // Free memory allocated for backupName
  free(backupName);
}