//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

// Function prototypes
void backupFiles(int numFiles, char** fileNames);
void copyFile(char* sourceFileName, char* destinationFileName);

// Main function
int main() {
  // Declare variables
  int numFiles;
  char** fileNames;
  int i;

  // Get the number of files to back up
  printf("How many files do you want to back up? ");
  scanf("%d", &numFiles);

  // Allocate memory for the file names
  fileNames = malloc(numFiles * sizeof(char*));

  // Get the file names
  for (i = 0; i < numFiles; i++) {
    fileNames[i] = malloc(MAX_FILE_NAME_LENGTH * sizeof(char));
    printf("Enter the name of file %d: ", i + 1);
    scanf("%s", fileNames[i]);
  }

  // Back up the files
  backupFiles(numFiles, fileNames);

  // Free the memory allocated for the file names
  for (i = 0; i < numFiles; i++) {
    free(fileNames[i]);
  }
  free(fileNames);

  // Exit the program
  return 0;
}

// Function to back up the files
void backupFiles(int numFiles, char** fileNames) {
  // Declare variables
  char* backupDirectoryName;
  int i;

  // Get the backup directory name
  printf("Enter the name of the backup directory: ");
  scanf("%s", backupDirectoryName);

  // Create the backup directory
  if (mkdir(backupDirectoryName, 0777) == -1) {
    printf("Error creating backup directory: %s\n", backupDirectoryName);
    exit(1);
  }

  // Copy the files to the backup directory
  for (i = 0; i < numFiles; i++) {
    char* sourceFileName = fileNames[i];
    char* destinationFileName = malloc(strlen(backupDirectoryName) + strlen(sourceFileName) + 2);
    strcpy(destinationFileName, backupDirectoryName);
    strcat(destinationFileName, "/");
    strcat(destinationFileName, sourceFileName);
    copyFile(sourceFileName, destinationFileName);
    free(destinationFileName);
  }

  // Print a success message
  printf("Files backed up successfully to %s\n", backupDirectoryName);
}

// Function to copy a file
void copyFile(char* sourceFileName, char* destinationFileName) {
  // Declare variables
  FILE* sourceFile;
  FILE* destinationFile;
  char buffer[MAX_BUFFER_SIZE];
  size_t bytesRead;

  // Open the source file
  sourceFile = fopen(sourceFileName, "rb");
  if (sourceFile == NULL) {
    printf("Error opening source file: %s\n", sourceFileName);
    exit(1);
  }

  // Open the destination file
  destinationFile = fopen(destinationFileName, "wb");
  if (destinationFile == NULL) {
    printf("Error opening destination file: %s\n", destinationFileName);
    exit(1);
  }

  // Copy the file
  do {
    bytesRead = fread(buffer, 1, MAX_BUFFER_SIZE, sourceFile);
    if (bytesRead > 0) {
      fwrite(buffer, 1, bytesRead, destinationFile);
    }
  } while (bytesRead > 0);

  // Close the files
  fclose(sourceFile);
  fclose(destinationFile);
}