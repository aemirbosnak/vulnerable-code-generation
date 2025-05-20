//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define BUFFER_SIZE 1024
#define TIMESTAMP_SIZE 20

// Function to get the current timestamp
void getCurrentTimestamp(char *timestamp) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(timestamp, TIMESTAMP_SIZE, "%Y-%m-%d_%H-%M-%S", t);
}

// Function to copy files from source to destination
int copyFile(const char *src, const char *dest) {
    FILE *sourceFile = fopen(src, "rb");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return -1;
    }

    FILE *destFile = fopen(dest, "wb");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);
    return 0;
}

// Function to create a backup directory
int createBackupDir(const char *baseDir, const char *backupDir) {
    char command[256];
    snprintf(command, sizeof(command), "mkdir -p %s", backupDir);
    return system(command);
}

// Function to backup files from source directory to backup directory
void backupFiles(const char *srcDir, const char *backupDir) {
    struct dirent *entry;
    DIR *dp = opendir(srcDir);
    if (dp == NULL) {
        perror("Error opening source directory");
        return;
    }

    char srcFilePath[PATH_MAX];
    char backupFilePath[PATH_MAX];
    
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Check if it's a regular file
            snprintf(srcFilePath, sizeof(srcFilePath), "%s/%s", srcDir, entry->d_name);
            snprintf(backupFilePath, sizeof(backupFilePath), "%s/%s", backupDir, entry->d_name);
            if (copyFile(srcFilePath, backupFilePath) == 0) {
                printf("Backed up '%s' to '%s'\n", srcFilePath, backupFilePath);
            }
        }
    }
    closedir(dp);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <source_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char backupDir[256];
    char timestamp[TIMESTAMP_SIZE];
    getCurrentTimestamp(timestamp);
    snprintf(backupDir, sizeof(backupDir), "backup_%s", timestamp);

    if (createBackupDir(".", backupDir) != 0) {
        fprintf(stderr, "Failed to create backup directory: %s\n", backupDir);
        return EXIT_FAILURE;
    }

    backupFiles(argv[1], backupDir);
    printf("Backup completed successfully.\n");

    return EXIT_SUCCESS;
}