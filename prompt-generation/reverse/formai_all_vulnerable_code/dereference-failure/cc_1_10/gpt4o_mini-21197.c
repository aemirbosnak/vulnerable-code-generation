//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 256

// Function prototypes
void displayOptions();
void handleBackup(const char *filename);
void getCurrentTimestamp(char *timestamp);
void generateBackupFilename(const char *original, char *backup);
void performBackup(const char *source, const char *destination);

int main() {
    char *fileList[MAX_FILES];
    int fileCount = 0;
    char input[FILENAME_LENGTH];
    
    printf("Welcome to the C File Backup System!\n");
    
    // Enter filenames to backup
    while (fileCount < MAX_FILES) {
        printf("Enter file to backup (or 'done' to finish): ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "done") == 0) {
            break;
        }

        // Allocate memory for the filename and save it
        fileList[fileCount] = malloc(strlen(input) + 1);
        if (fileList[fileCount] == NULL) {
            perror("Failed to allocate memory for file name");
            exit(EXIT_FAILURE);
        }
        strcpy(fileList[fileCount], input);
        fileCount++;
    }

    // Display options and backup files
    displayOptions();
    for (int i = 0; i < fileCount; i++) {
        handleBackup(fileList[i]);
        free(fileList[i]); // free allocated memory
    }

    printf("Backup process completed. Thank you!\n");
    return 0;
}

void displayOptions() {
    printf("Options:\n");
    printf("1. Backup files\n");
    printf("2. Exit\n");
}

void handleBackup(const char *filename) {
    char backupFilename[FILENAME_LENGTH];

    // Generate a backup filename
    generateBackupFilename(filename, backupFilename);

    // Perform the file backup
    performBackup(filename, backupFilename);
}

void getCurrentTimestamp(char *timestamp) {
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    
    strftime(timestamp, 20, "%Y%m%d_%H%M%S", tm_struct);
}

void generateBackupFilename(const char *original, char *backup) {
    char timestamp[20];
    getCurrentTimestamp(timestamp);

    // Create a formatted backup filename
    snprintf(backup, FILENAME_LENGTH, "%s_backup_%s", original, timestamp);
}

void performBackup(const char *source, const char *destination) {
    FILE *sourceFile = fopen(source, "rb");
    if (!sourceFile) {
        fprintf(stderr, "Could not open source file: %s\n", source);
        return;
    }
    
    FILE *destinationFile = fopen(destination, "wb");
    if (!destinationFile) {
        fprintf(stderr, "Could not open destination file: %s\n", destination);
        fclose(sourceFile);
        return;
    }

    // Copy the content from source to destination
    char buffer[4096];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) != 0) {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);
    printf("Backup created: %s\n", destination);
}