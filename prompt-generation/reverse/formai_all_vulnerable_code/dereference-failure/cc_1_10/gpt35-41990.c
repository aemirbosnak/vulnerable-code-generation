//FormAI DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void backupFile(char *filename);
char* generateBackupName(char *filename);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s filename\n", argv[0]);
    return 1;
  }
  
  char *filename = argv[1];
 
  backupFile(filename);

  return 0;
}

void backupFile(char *filename) {
  FILE *fp = NULL;

  // Open the file for reading in binary mode
  fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return;
  }

  // Create backup filename
  char *backupFilename = generateBackupName(filename);

  // Open the backup file for writing in binary mode
  FILE *backupFp = fopen(backupFilename, "wb");
  if (backupFp == NULL) {
    printf("Error creating backup file %s\n", backupFilename);
    return;
  }

  // Read from the original file and write to the backup file
  size_t n = 0;
  unsigned char buffer[1024];
  while ((n = fread(buffer, sizeof(unsigned char), sizeof(buffer), fp)) > 0) {
    fwrite(buffer, sizeof(unsigned char), n, backupFp);
  }

  fclose(fp);
  fclose(backupFp);
  
  printf("Backup created successfully: %s\n", backupFilename);
}

char* generateBackupName(char *filename) {
  // Get current time in seconds
  time_t seconds = time(NULL);

  // Convert time to string
  char timestamp[20];
  sprintf(timestamp, "%ld", seconds);

  // Get original file extension
  char *extension = strrchr(filename, '.');
  if (extension == NULL) {
    extension = "";
  }

  // Create backup filename
  char *backupFilename = (char*) malloc(strlen(filename) + strlen(timestamp) + strlen(extension) + 2);
  sprintf(backupFilename, "%s.%s%s", filename, timestamp, extension);

  return backupFilename;
}