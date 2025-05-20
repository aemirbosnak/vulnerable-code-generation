//FormAI DATASET v1.0 Category: File Backup System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME_LEN 100

// Function to get current date and time
char* getDateTime() {
  time_t now = time(NULL);
  char* dateTime = ctime(&now);
  dateTime[strlen(dateTime) - 1] = '\0';
  return dateTime;
}

// Function to check if file exists
int fileExists(char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    return 0;
  }
  fclose(file);
  return 1;
}

// Function to backup a file
int backupFile(char* filename) {
  // Check if file exists
  if (!fileExists(filename)) {
    printf("File %s does not exist.\n", filename);
    return 0;
  }

  // Generate backup filename
  char backupFilename[FILENAME_LEN];
  sprintf(backupFilename, "%s_%s", filename, getDateTime());

  // Copy file to backup filename
  FILE* file = fopen(filename, "rb");
  FILE* backupFile = fopen(backupFilename, "wb");
  if (file == NULL || backupFile == NULL) {
    printf("Error in opening files.\n");
    return 0;
  }
  int ch = 0;
  while ((ch = fgetc(file)) != EOF) {
    fputc(ch, backupFile);
  }
  fclose(file);
  fclose(backupFile);

  // Print success message
  printf("File %s backed up to %s.\n", filename, backupFilename);
  return 1;
}

int main() {
  char filename[FILENAME_LEN];
  printf("Enter the filename to backup: ");
  fgets(filename, FILENAME_LEN, stdin);
  filename[strcspn(filename, "\n")] = '\0';
  backupFile(filename);
  return 0;
}