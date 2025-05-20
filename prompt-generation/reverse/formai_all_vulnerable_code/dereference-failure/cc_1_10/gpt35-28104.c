//FormAI DATASET v1.0 Category: File Synchronizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Function declarations
void syncFiles(char *sourcePath, char *destinationPath);
int fileExists(char *path);
int isDirectory(char *path);
void copyFile(char *sourcePath, char *destinationPath);
void createDirs(char *path);

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
        return 1;
    }

    syncFiles(argv[1], argv[2]);

    printf("Files have been synchronized successfully!\n");

    return 0;
}

void syncFiles(char *sourcePath, char *destinationPath) {
    DIR *sourceDir, *destinationDir;
    struct dirent *sourceDP, *destinationDP;
    char sourceFilePath[1000], destinationFilePath[1000];

    sourceDir = opendir(sourcePath);
    destinationDir = opendir(destinationPath);

    // Create destination directory if it doesn't exist
    if (destinationDir == NULL) {
        createDirs(destinationPath);
        destinationDir = opendir(destinationPath);
    }

    // Synchronize files from the source directory
    while ((sourceDP = readdir(sourceDir)) != NULL) {
        if (strcmp(sourceDP->d_name, ".") != 0 && strcmp(sourceDP->d_name, "..") != 0) {
            sprintf(sourceFilePath, "%s/%s", sourcePath, sourceDP->d_name);
            sprintf(destinationFilePath, "%s/%s", destinationPath, sourceDP->d_name);

            if (fileExists(destinationFilePath)) {
                // If file exists in both source and destination directories, compare their modification times
                struct stat sourceStat, destinationStat;
                stat(sourceFilePath, &sourceStat);
                stat(destinationFilePath, &destinationStat);

                if (difftime(sourceStat.st_mtime, destinationStat.st_mtime) > 0) {
                    // If source file is more recent, copy it to destination directory
                    copyFile(sourceFilePath, destinationFilePath);
                }
            } else {
                // If file doesn't exist in destination directory, copy it from source directory
                copyFile(sourceFilePath, destinationFilePath);
            }

            if (isDirectory(sourceFilePath)) {
                // Recursively synchronize files from subdirectories
                syncFiles(sourceFilePath, destinationFilePath);
            }
        }
    }
}

int fileExists(char *path) {
    struct stat fileStat;
    if (stat(path, &fileStat) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int isDirectory(char *path) {
    struct stat fileStat;
    if (stat(path, &fileStat) == 0 && S_ISDIR(fileStat.st_mode)) {
        return 1;
    } else {
        return 0;
    }
}

void copyFile(char *sourcePath, char *destinationPath) {
    FILE *sourceFile, *destinationFile;
    char buffer[1000];
    size_t bytes;

    sourceFile = fopen(sourcePath, "rb");
    destinationFile = fopen(destinationPath, "wb");

    while ((bytes = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytes, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);
}

void createDirs(char *path) {
    char subDir[1000], currentPath[1000] = "";
    int i;

    for (i = 0; i < strlen(path); i++) {
        if (path[i] == '/') {
            sprintf(subDir, "%s%s", currentPath, "/");
            strcat(currentPath, subDir);
            mkdir(currentPath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        } else {
            sprintf(subDir, "%c", path[i]);
            strcat(currentPath, subDir);
        }
    }
}