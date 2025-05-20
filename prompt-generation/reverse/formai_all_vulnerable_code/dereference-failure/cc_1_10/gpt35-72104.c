//FormAI DATASET v1.0 Category: File Backup System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void displayUsage() {
    printf("Usage: backup [source_file] [destination_file]\n");
}

int main(int argc, char** argv) {
    if (argc != 3) {
        displayUsage();
        return 1;
    }

    char* sourceFilename = argv[1];
    char* destinationFilename = argv[2];
    char* backupFilename = malloc(sizeof(char) * (MAX_FILENAME_LENGTH + 5)); // +5 for ".bak\0"

    if (backupFilename == NULL) {
        printf("Error: Failed to allocate memory for backup filename.\n");
        return 1;
    }

    // Create backup filename with .bak extension
    if (strlen(destinationFilename) > MAX_FILENAME_LENGTH) {
        printf("Error: Destination filename is too long.\n");
        free(backupFilename);
        return 1;
    }
    strcpy(backupFilename, destinationFilename);
    strcat(backupFilename, ".bak");

    FILE* sourceFile = fopen(sourceFilename, "rb");
    if (sourceFile == NULL) {
        printf("Error: Failed to open source file for reading.\n");
        free(backupFilename);
        return 1;
    }

    FILE* backupFile = fopen(backupFilename, "wb");
    if (backupFile == NULL) {
        printf("Error: Failed to open backup file for writing.\n");
        fclose(sourceFile);
        free(backupFilename);
        return 1;
    }

    // Copy contents of source file to backup file
    int bufferLength = 1024;
    char* buffer = malloc(sizeof(char) * bufferLength);

    if (buffer == NULL) {
        printf("Error: Failed to allocate memory for buffer.\n");
        fclose(sourceFile);
        fclose(backupFile);
        free(backupFilename);
        return 1;
    }

    size_t bytesRead;
    while ((bytesRead = fread(buffer, sizeof(char), bufferLength, sourceFile)) > 0) {
        size_t bytesWritten = fwrite(buffer, sizeof(char), bytesRead, backupFile);
        if (bytesWritten < bytesRead) {
            printf("Error: Failed to write all data to backup file.\n");
            fclose(sourceFile);
            fclose(backupFile);
            free(backupFilename);
            free(buffer);
            return 1;
        }
    }

    fclose(sourceFile);
    fclose(backupFile);
    free(backupFilename);
    free(buffer);

    printf("Backup successful.\n");
    return 0;
}