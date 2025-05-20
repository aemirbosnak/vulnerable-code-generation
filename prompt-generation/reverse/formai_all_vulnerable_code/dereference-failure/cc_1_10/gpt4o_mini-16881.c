//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void displayInstructions() {
    printf("Welcome to the File Backup System!\n");
    printf("Instructions:\n");
    printf("1. Enter the source directory path to backup files from.\n");
    printf("2. Enter the destination directory path to store backup files.\n");
    printf("3. The program will copy all files from the source to the destination directory.\n");
    printf("4. The backup will preserve file names and maintain the directory structure.\n");
}

int isDirectory(const char *path) {
    struct stat pathStat;
    stat(path, &pathStat);
    return S_ISDIR(pathStat.st_mode);
}

void createBackup(const char *source, const char *destination) {
    struct dirent *entry;
    DIR *dp = opendir(source);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char sourcePath[BUFFER_SIZE];
        char destPath[BUFFER_SIZE];

        snprintf(sourcePath, sizeof(sourcePath), "%s/%s", source, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destination, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Create the new directory in the destination
            mkdir(destPath, 0700);
            // Recursive backup for the directory
            createBackup(sourcePath, destPath);
        } else if (entry->d_type == DT_REG) {
            FILE *srcFile = fopen(sourcePath, "rb");
            FILE *destFile = fopen(destPath, "wb");

            if (srcFile == NULL || destFile == NULL) {
                perror("File operation failed");
                if (srcFile) fclose(srcFile);
                if (destFile) fclose(destFile);
                return;
            }

            char buffer[BUFFER_SIZE];
            size_t bytes;

            while ((bytes = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0) {
                fwrite(buffer, 1, bytes, destFile);
            }

            fclose(srcFile);
            fclose(destFile);
        }
    }
    closedir(dp);
    printf("Backup for directory '%s' is complete!\n", source);
}

int main() {
    displayInstructions();

    char source[BUFFER_SIZE];
    char destination[BUFFER_SIZE];

    printf("Enter source directory path: ");
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = 0; // Remove the newline character

    printf("Enter destination directory path: ");
    fgets(destination, sizeof(destination), stdin);
    destination[strcspn(destination, "\n")] = 0; // Remove the newline character

    if (!isDirectory(source)) {
        fprintf(stderr, "Error: Source path is not a directory or doesn't exist!\n");
        return EXIT_FAILURE;
    }

    mkdir(destination, 0755); // Create destination directory if it doesn't exist

    createBackup(source, destination);

    return EXIT_SUCCESS;
}