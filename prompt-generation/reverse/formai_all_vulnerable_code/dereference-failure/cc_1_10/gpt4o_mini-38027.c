//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int calculateBackupSize(const char *filePath);
void performBackup(const char *source, const char *backup);
void displayInstructions();
int isValidFile(const char *filePath);

int main() {
    char sourceFile[256];
    char backupFile[256];
    
    // Display instructions
    displayInstructions();

    // Get source file path from user
    printf("Enter the path of the source file: ");
    scanf("%s", sourceFile);

    // Validate the source file
    if (!isValidFile(sourceFile)) {
        printf("Invalid file path. Please check and try again.\n");
        return 1;
    }

    // Get backup destination from user
    printf("Enter the backup file path: ");
    scanf("%s", backupFile);

    // Perform backup operation
    performBackup(sourceFile, backupFile);

    printf("Backup completed successfully!\n");
    return 0;
}

// Function to display instructions for the user
void displayInstructions() {
    printf("=== File Backup System ===\n");
    printf("This system creates a backup for your specified file.\n");
    printf("1. Provide the source file path.\n");
    printf("2. Provide the destination where the backup will be stored.\n");
    printf("3. The backup process will begin.\n");
}

// Function to check if file exists
int isValidFile(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    int isValid = (file != NULL);
    if (isValid) {
        fclose(file);
    }
    return isValid;
}

// Function to calculate the size of the file for backup
int calculateBackupSize(const char *filePath) {
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        return -1; // Error opening the file
    }
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    fclose(file);
    return size;
}

// Function to perform backup of the specified file
void performBackup(const char *source, const char *backup) {
    FILE *sourceFile = fopen(source, "rb");
    FILE *backupFile = fopen(backup, "wb");

    if (!sourceFile || !backupFile) {
        printf("Error opening source or backup file.\n");
        exit(1);
    }

    int bufferSize = 1024;
    char *buffer = (char *)malloc(bufferSize);
    if (!buffer) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    int bytesRead;
    int totalBytes = 0;
    while ((bytesRead = fread(buffer, 1, bufferSize, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, backupFile);
        totalBytes += bytesRead;
    }

    // Calculate and display the size of the backup
    int backupSize = calculateBackupSize(backup);
    printf("The size of the backup created is: %d bytes (Total bytes copied: %d)\n", backupSize, totalBytes);

    free(buffer);
    fclose(sourceFile);
    fclose(backupFile);
}