//FormAI DATASET v1.0 Category: File Backup System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum file name length
#define MAX_FILE_NAME_LENGTH 50

// Define maximum backup file name length
#define MAX_BACKUP_NAME_LENGTH 100

// Define maximum number of backup files to keep
#define MAX_BACKUP_COUNT 10

// Define array to store backup file names
char backupFiles[MAX_BACKUP_COUNT][MAX_BACKUP_NAME_LENGTH];

// Function to generate backup file name
char* generateBackupName(char* fileName, int count) {
  char* backupName = malloc(MAX_BACKUP_NAME_LENGTH * sizeof(char));
  sprintf(backupName, "BACKUP%d_%s", count, fileName);
  return backupName;
}

// Function to create backup of the given file
void createBackup(char* fileName) {
  // Open the input file
  FILE* file = fopen(fileName, "r");
  if (file == NULL) {
    printf("Error: Could not open file %s!\n", fileName);
    return;
  }

  // Generate backup file name
  char* backupName = generateBackupName(fileName, 1);

  // Open the backup file for writing
  FILE* backup = fopen(backupName, "w");
  if (backup == NULL) {
    printf("Error: Could not create backup file %s!\n", backupName);
    fclose(file);
    free(backupName);
    return;
  }

  // Copy contents of the input file to the backup file
  char c;
  while ((c = fgetc(file)) != EOF) {
    fputc(c, backup);
  }

  // Close both the input and backup files
  fclose(file);
  fclose(backup);

  // Add the backup file name to the backup files array
  strcpy(backupFiles[0], backupName);

  printf("Created backup file %s!\n", backupName);

  free(backupName);
}

int main() {
  int option;

  printf("Welcome to the Surreal File Backup System!\n");

  while (1) {
    printf("\nPlease choose an option:\n");
    printf("1. Create backup of a file\n");
    printf("2. View list of backup files\n");
    printf("3. Exit\n");
    printf("Option: ");

    scanf("%d", &option);

    switch (option) {
      case 1: {
        char fileName[MAX_FILE_NAME_LENGTH];
        printf("\nEnter the file name: ");
        scanf("%s", fileName);
        createBackup(fileName);
        break;
      }
      case 2: {
        printf("\nList of backup files:\n");
        for (int i = 0; i < MAX_BACKUP_COUNT; i++) {
          if (strlen(backupFiles[i]) > 0) {
            printf("%s\n", backupFiles[i]);
          }
        }
        break;
      }
      case 3: {
        printf("\nGoodbye!\n");
        exit(0);
      }
      default: {
        printf("\nInvalid option! Please try again.\n");
        break;
      }
    }
  }
  
  return 0;
}