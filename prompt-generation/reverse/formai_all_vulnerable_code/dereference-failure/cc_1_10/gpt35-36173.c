//FormAI DATASET v1.0 Category: File Backup System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BACKUP_FILENAME_LENGTH 200
#define BUFFER_SIZE 1000

// function declarations
void backupFile(char* filename);

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the name of the file to backup: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);

    // remove trailing newline character
    filename[strcspn(filename, "\n")] = '\0';

    backupFile(filename);

    return 0;
}

// function definition
void backupFile(char* filename) {
    // get current time to use as suffix for backup filename
    time_t rawtime;
    struct tm* timeinfo;
    char timestamp[20];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", timeinfo);

    // create backup filename
    char backupFilename[MAX_BACKUP_FILENAME_LENGTH];
    strcpy(backupFilename, filename);
    strcat(backupFilename, "_backup_");
    strcat(backupFilename, timestamp);

    // open files for reading and writing
    FILE* file = fopen(filename, "r");
    FILE* backupFile = fopen(backupFilename, "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    if (backupFile == NULL) {
        printf("Error creating backup file.\n");
        exit(1);
    }

    // read data from file into buffer and write to backup file
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        fwrite(buffer, 1, bytesRead, backupFile);
    }

    // close files
    fclose(file);
    fclose(backupFile);

    printf("Backup saved to \"%s\"\n", backupFilename);
}