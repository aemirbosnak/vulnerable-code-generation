//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_PATH_LENGTH 1024

// Function to create a backup of a file
int backupFile(char *sourcePath, char *backupPath) {
    // Open the source file for reading
    FILE *sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return -1;
    }

    // Open the backup file for writing
    FILE *backupFile = fopen(backupPath, "w");
    if (backupFile == NULL) {
        perror("Error opening backup file");
        fclose(sourceFile);
        return -1;
    }

    // Copy the contents of the source file to the backup file
    int c;
    while ((c = fgetc(sourceFile)) != EOF) {
        fputc(c, backupFile);
    }

    // Close both files
    fclose(sourceFile);
    fclose(backupFile);

    return 0;
}

// Function to create a backup of a directory
int backupDirectory(char *sourcePath, char *backupPath) {
    // Create the backup directory if it doesn't exist
    if (mkdir(backupPath, 0777) != 0) {
        perror("Error creating backup directory");
        return -1;
    }

    // Open the source directory for reading
    DIR *sourceDir = opendir(sourcePath);
    if (sourceDir == NULL) {
        perror("Error opening source directory");
        return -1;
    }

    // Read each file in the source directory
    struct dirent *dirent;
    while ((dirent = readdir(sourceDir)) != NULL) {
        // Skip the "." and ".." directories
        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        // Get the full path of the source file
        char sourceFilePath[MAX_PATH_LENGTH];
        snprintf(sourceFilePath, MAX_PATH_LENGTH, "%s/%s", sourcePath, dirent->d_name);

        // Get the full path of the backup file
        char backupFilePath[MAX_PATH_LENGTH];
        snprintf(backupFilePath, MAX_PATH_LENGTH, "%s/%s", backupPath, dirent->d_name);

        // Determine the type of file
        struct stat fileStat;
        if (stat(sourceFilePath, &fileStat) != 0) {
            perror("Error getting file stat");
            closedir(sourceDir);
            return -1;
        }

        // If the file is a regular file, copy it to the backup file
        if (S_ISREG(fileStat.st_mode)) {
            if (backupFile(sourceFilePath, backupFilePath) != 0) {
                closedir(sourceDir);
                return -1;
            }
        }
        // If the file is a directory, recursively copy it to the backup directory
        else if (S_ISDIR(fileStat.st_mode)) {
            if (backupDirectory(sourceFilePath, backupFilePath) != 0) {
                closedir(sourceDir);
                return -1;
            }
        }
        // If the file is of an unknown type, skip it
        else {
            printf("Unknown file type: %s\n", dirent->d_name);
        }
    }

    // Close the source directory
    closedir(sourceDir);

    return 0;
}

int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Usage: %s <source path> <backup path>\n", argv[0]);
        return -1;
    }

    // Get the source path and the backup path
    char *sourcePath = argv[1];
    char *backupPath = argv[2];

    // Create a backup of the source file or directory
    if (backupDirectory(sourcePath, backupPath) != 0) {
        return -1;
    }

    return 0;
}