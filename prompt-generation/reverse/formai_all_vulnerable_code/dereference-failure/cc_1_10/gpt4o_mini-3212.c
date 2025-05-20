//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BACKUP_EXTENSION ".bak"

void print_usage(const char *program_name) {
    printf("Usage: %s <file_to_backup>\n", program_name);
}

void create_backup(const char *filename) {
    FILE *sourceFile;
    FILE *backupFile;
    char backupFilename[256];
    char ch;
    time_t now;
    struct tm *timeinfo;

    // Construct the backup filename with timestamp
    time(&now);
    timeinfo = localtime(&now);
    snprintf(backupFilename, sizeof(backupFilename), "%s_%04d%02d%02d_%02d%02d%02d%s", 
             filename, timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, 
             timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, BACKUP_EXTENSION);

    // Open the source file for reading
    sourceFile = fopen(filename, "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return;
    }

    // Open the backup file for writing
    backupFile = fopen(backupFilename, "w");
    if (backupFile == NULL) {
        perror("Error creating backup file");
        fclose(sourceFile);
        return;
    }

    // Reading from source and writing to backup
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, backupFile);
    }

    printf("Backup of '%s' created as '%s'\n", filename, backupFilename);

    // Close the files
    fclose(sourceFile);
    fclose(backupFile);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    create_backup(argv[1]);

    return EXIT_SUCCESS;
}