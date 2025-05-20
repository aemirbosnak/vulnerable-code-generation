//FormAI DATASET v1.0 Category: File Backup System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_FILENAME_LEN 100
#define MAX_FILE_SIZE 2000000
#define MAX_BACKUPS 50

// Define struct for storing file information
typedef struct {
   char fileName[MAX_FILENAME_LEN];
   time_t modifiedTime;
   int size;
} FileInfo;

// Function to log backup information
void logBackup(char* fileName) {
   printf("File %s backed up successfully.\n", fileName);
}

int main() {
   // Array to store backup files
   FileInfo backups[MAX_BACKUPS];
   
   // Ask for file name input
   char fileName[MAX_FILENAME_LEN];
   printf("Enter file name to backup: ");
   fgets(fileName, MAX_FILENAME_LEN, stdin);
   fileName[strcspn(fileName, "\n")] = 0;
   
   // Open file for backup
   FILE* file = fopen(fileName, "rb");
   if (file == NULL) {
      printf("Failed to open file %s for backup.\n", fileName);
      return 1;
   }
   
   // Check file size and allocate buffer
   fseek(file, 0L, SEEK_END);
   int fileSize = ftell(file);
   rewind(file);
   if (fileSize > MAX_FILE_SIZE) {
      printf("File size too large for backup.\n");
      return 1;
   }
   char* buffer = (char*) malloc(fileSize * sizeof(char));
   
   // Read file into buffer
   fread(buffer, sizeof(char), fileSize, file);
   
   // Close file
   fclose(file);
   
   // Generate backup file name
   char backupFileName[MAX_FILENAME_LEN];
   snprintf(backupFileName, MAX_FILENAME_LEN, "%s_%ld.bak", fileName, time(NULL));
   
   // Check if backup file already exists
   for (int i = 0; i < MAX_BACKUPS; i++) {
      if (strcmp(backups[i].fileName, backupFileName) == 0) {
         printf("Backup file for %s already exists.\n", fileName);
         return 1;
      }
   }
   
   // Check if max number of backups reached
   if (MAX_BACKUPS <= 0) {
      printf("Maximum number of backups reached.\n");
      return 1;
   }
   
   // Create backup file and write buffer
   FILE* backupFile = fopen(backupFileName, "wb");
   fwrite(buffer, sizeof(char), fileSize, backupFile);
   fclose(backupFile);
   
   // Free buffer memory
   free(buffer);
   
   // Add backup info to array
   FileInfo backupInfo;
   strcpy(backupInfo.fileName, backupFileName);
   backupInfo.modifiedTime = time(NULL);
   backupInfo.size = fileSize;
   backups[MAX_BACKUPS - 1] = backupInfo;
   
   // Call log function
   logBackup(fileName);
   
   return 0;
}