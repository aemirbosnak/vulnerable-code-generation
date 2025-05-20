//FormAI DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define FILE_PATH_LEN 256

void backupFiles(char *sourcePath, char *destinationPath) {
    DIR *sourceDir;
    struct dirent *dirEntry;

    sourceDir = opendir(sourcePath);

    if (sourceDir) {
        while ((dirEntry = readdir(sourceDir)) != NULL) {
            if (dirEntry->d_type == DT_REG) { // DT_REG = File
                // Construct the file path for both the source and destination
                char sourceFilePath[FILE_PATH_LEN];
                char destinationFilePath[FILE_PATH_LEN];
                snprintf(sourceFilePath, FILE_PATH_LEN, "%s/%s", sourcePath, dirEntry->d_name);
                snprintf(destinationFilePath, FILE_PATH_LEN, "%s/%s", destinationPath, dirEntry->d_name);

                // Open both files
                FILE *sourceFile = fopen(sourceFilePath, "rb");
                FILE *destinationFile = fopen(destinationFilePath, "wb");

                // Copy contents of the source file to the destination file
                char buffer[1024];
                size_t readBytes;

                while ((readBytes = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
                    fwrite(buffer, 1, readBytes, destinationFile);
                }

                // Close files
                fclose(sourceFile);
                fclose(destinationFile);
            }
        }

        // Close directory stream
        closedir(sourceDir);
    } else {
        printf("Error opening directory: %s\n", sourcePath);
    }
}

int main(int argc, char *argv[]) {
    // Check if the arguments are correct
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Make sure the source directory exists
    DIR *sourceDir = opendir(argv[1]);

    if (!sourceDir) {
        printf("Error opening directory: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    closedir(sourceDir);

    // Make sure the destination directory exists
    DIR *destinationDir = opendir(argv[2]);

    if (!destinationDir) {
        printf("Error opening directory: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    closedir(destinationDir);

    // Backup files
    backupFiles(argv[1], argv[2]);

    printf("Backup completed successfully!\n");

    return 0;
}