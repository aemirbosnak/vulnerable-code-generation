//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createBackupFile(char* originalFile, char* backupDir) {
    // Check if original file exists
    FILE* originalFilePtr = fopen(originalFile, "r");
    if (originalFilePtr == NULL) {
        printf("Error: Original file does not exist.\n");
        return;
    }
    
    // Check if backup directory is valid
    char backupDirPath[100];
    sprintf(backupDirPath, "%s/backup", backupDir);
    char* backupDirPtr = strtok(backupDirPath, "/");
    while (backupDirPtr!= NULL) {
        if (access(backupDirPtr, 0) == -1) {
            printf("Error: Backup directory is not valid.\n");
            return;
        }
        backupDirPtr = strtok(NULL, "/");
    }
    
    // Create backup file
    char backupFileName[100];
    sprintf(backupFileName, "%s/backup-%s", backupDirPath, originalFile);
    FILE* backupFilePtr = fopen(backupFileName, "w");
    if (backupFilePtr == NULL) {
        printf("Error: Failed to create backup file.\n");
        fclose(originalFilePtr);
        return;
    }
    
    // Copy content from original file to backup file
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), originalFilePtr)) {
        fputs(buffer, backupFilePtr);
    }
    
    // Close files
    fclose(originalFilePtr);
    fclose(backupFilePtr);
    
    printf("Backup completed successfully.\n");
}

int main() {
    // Prompt user for input
    char originalFile[100];
    printf("Enter the name of the file to be backed up: ");
    fgets(originalFile, sizeof(originalFile), stdin);
    
    // Remove newline character from input
    originalFile[strcspn(originalFile, "\n")] = '\0';
    
    char backupDir[100];
    printf("Enter the directory where the backup should be stored: ");
    fgets(backupDir, sizeof(backupDir), stdin);
    
    // Remove newline character from input
    backupDir[strcspn(backupDir, "\n")] = '\0';
    
    // Call createBackupFile function
    createBackupFile(originalFile, backupDir);
    
    return 0;
}