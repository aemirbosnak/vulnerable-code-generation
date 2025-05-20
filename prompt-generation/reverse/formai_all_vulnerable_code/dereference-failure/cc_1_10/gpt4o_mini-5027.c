//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 512
#define BUFFER_SIZE 1024

// Function prototypes
void backupFile(const char *srcPath, const char *destPath);
void createBackupDirectory(const char *backupDir);
void copyFilesFromDirectory(const char *srcDir, const char *destDir);
void displayBackupStatus(const char *srcDir, const char *destDir);
int isFile(const char *path);

// Main function
int main() {
    char sourceDir[MAX_PATH_LENGTH], backupDir[MAX_PATH_LENGTH];

    printf("Enter the source directory: ");
    fgets(sourceDir, MAX_PATH_LENGTH, stdin);
    sourceDir[strcspn(sourceDir, "\n")] = 0;  // Remove newline character

    printf("Enter the backup directory: ");
    fgets(backupDir, MAX_PATH_LENGTH, stdin);
    backupDir[strcspn(backupDir, "\n")] = 0;  // Remove newline character

    createBackupDirectory(backupDir); // Create the backup directory if it doesn't exist
    copyFilesFromDirectory(sourceDir, backupDir); // Start copying files
    displayBackupStatus(sourceDir, backupDir); // Display backup status

    return 0;
}

// Function to backup an individual file
void backupFile(const char *srcPath, const char *destPath) {
    FILE *srcFile = fopen(srcPath, "rb");
    if (!srcFile) {
        perror("Error opening source file");
        return;
    }

    FILE *destFile = fopen(destPath, "wb");
    if (!destFile) {
        perror("Error creating backup file");
        fclose(srcFile);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Copying the contents from srcFile to destFile
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    printf("Backed up: %s -> %s\n", srcPath, destPath);
    fclose(srcFile);
    fclose(destFile);
}

// Function to create the backup directory
void createBackupDirectory(const char *backupDir) {
    struct stat st = {0};
    if (stat(backupDir, &st) == -1) {
        if (mkdir(backupDir, 0700) == 0) {
            printf("Backup directory created: %s\n", backupDir);
        } else {
            perror("Failed to create backup directory");
        }
    }
}

// Function to copy files from the source directory to the destination directory
void copyFilesFromDirectory(const char *srcDir, const char *destDir) {
    DIR *dir = opendir(srcDir);
    struct dirent *entry;

    if (!dir) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char srcFile[MAX_PATH_LENGTH], destFile[MAX_PATH_LENGTH];
            snprintf(srcFile, sizeof(srcFile), "%s/%s", srcDir, entry->d_name);
            snprintf(destFile, sizeof(destFile), "%s/%s", destDir, entry->d_name);
            
            if (isFile(srcFile)) {
                backupFile(srcFile, destFile); // Backup the individual file
            }
        }
    }
    closedir(dir);
}

// Function to check if a path is a file
int isFile(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

// Function to display the backup status (number of files)
void displayBackupStatus(const char *srcDir, const char *destDir) {
    DIR *src = opendir(srcDir);
    DIR *dest = opendir(destDir);
    struct dirent *entry;
    int srcCount = 0, destCount = 0;

    if (src) {
        while ((entry = readdir(src)) != NULL) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                srcCount++;
            }
        }
        closedir(src);
    }

    if (dest) {
        while ((entry = readdir(dest)) != NULL) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                destCount++;
            }
        }
        closedir(dest);
    }

    printf("Files in source directory: %d\n", srcCount);
    printf("Files backed up to destination directory: %d\n", destCount);
}