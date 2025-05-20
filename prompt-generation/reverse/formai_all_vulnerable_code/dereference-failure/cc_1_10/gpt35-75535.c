//FormAI DATASET v1.0 Category: File Backup System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum file name and extension length
#define MAX_NAME_LEN 50
#define MAX_EXT_LEN 10

// Define struct to hold file name, extension, and time stamp
typedef struct {
    char name[MAX_NAME_LEN];
    char ext[MAX_EXT_LEN];
    time_t timestamp;
} FileInfo;

// Function to get current time stamp
time_t getCurrentTimeStamp() {
    time_t currentTime;
    time(&currentTime);
    return currentTime;
}

int main() {
    // Prompt user for file name and extension
    char filename[MAX_NAME_LEN];
    char extension[MAX_EXT_LEN];
    printf("Enter file name: ");
    scanf("%s", filename);
    printf("Enter file extension (without '.'): ");
    scanf("%s", extension);

    // Create file info struct and populate with user input
    FileInfo file;
    strcpy(file.name, filename);
    strcpy(file.ext, extension);
    file.timestamp = getCurrentTimeStamp();

    // Open backup file for writing in binary mode
    char backupFileName[MAX_NAME_LEN + MAX_EXT_LEN + 16];
    sprintf(backupFileName, "%s-%ld.%s", file.name, file.timestamp, file.ext);
    FILE* backupFile = fopen(backupFileName, "wb");

    // Open original file for reading in binary mode
    char originalFileName[MAX_NAME_LEN + MAX_EXT_LEN + 1];
    sprintf(originalFileName, "%s.%s", file.name, file.ext);
    FILE* originalFile = fopen(originalFileName, "rb");

    // Copy data from original file to backup file
    if (originalFile == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    } else {
        char buffer[1024];
        size_t bytesRead;
        while ((bytesRead = fread(buffer, 1, sizeof(buffer), originalFile)) > 0) {
            fwrite(buffer, 1, bytesRead, backupFile);
        }
        printf("File backed up successfully!\n");
    }

    // Close both files
    fclose(originalFile);
    fclose(backupFile);

    return 0;
}