//FormAI DATASET v1.0 Category: File Synchronizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH_LENGTH 2048
#define MAX_CONFIG_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256
#define BUFFER_SIZE 4096

// Function to synchronize two directories
void syncDirectories(char *srcPath, char *destPath) {
    DIR *srcDir = opendir(srcPath);
    DIR *destDir = opendir(destPath);

    struct dirent *srcDirent;
    struct dirent *destDirent;

    // Traverse source directory
    while ((srcDirent = readdir(srcDir)) != NULL) {
        char srcName[MAX_FILE_NAME_LENGTH];
        char srcPathComplete[MAX_PATH_LENGTH];
        char destPathComplete[MAX_PATH_LENGTH];

        strcpy(srcName, srcDirent->d_name);

        if (strcmp(srcName, ".") == 0 || strcmp(srcName, "..") == 0) {
            continue;
        }

        sprintf(srcPathComplete, "%s/%s", srcPath, srcName);
        sprintf(destPathComplete, "%s/%s", destPath, srcName);

        struct stat srcStat;
        struct stat destStat;

        int srcStatErr = stat(srcPathComplete, &srcStat);

        if (srcStatErr == -1) {
            perror("Error occurred while getting src file stats.");
            continue;
        }

        int fileFound = 0;

        // Traverse destination directory to see if file already exists
        while ((destDirent = readdir(destDir)) != NULL) {
            char destName[MAX_FILE_NAME_LENGTH];

            strcpy(destName, destDirent->d_name);

            if (strcmp(destName, ".") == 0 || strcmp(destName, "..") == 0) {
                continue;
            }

            if (strcmp(srcName, destName) == 0) {
                fileFound = 1;

                sprintf(destPathComplete, "%s/%s", destPath, destName);
                int destStatErr = stat(destPathComplete, &destStat);

                if (destStatErr == -1) {
                    perror("Error occurred while getting dest file stats.");
                    continue;
                }

                if (srcStat.st_mtime > destStat.st_mtime) {
                    FILE *srcFile = fopen(srcPathComplete, "r");
                    FILE *destFile = fopen(destPathComplete, "w");

                    char buffer[BUFFER_SIZE];

                    while (fgets(buffer, BUFFER_SIZE, srcFile)) {
                        fputs(buffer, destFile);
                    }

                    printf("%s updated successfully.\n", srcName);

                    fclose(srcFile);
                    fclose(destFile);
                }

                break;
            }
        }

        // If file not found in dest folder, create it
        if (!fileFound) {
            FILE *srcFile = fopen(srcPathComplete, "r");
            FILE *destFile = fopen(destPathComplete, "w");

            char buffer[BUFFER_SIZE];

            while (fgets(buffer, BUFFER_SIZE, srcFile)) {
                fputs(buffer, destFile);
            }

            printf("%s created successfully.\n", srcName);

            fclose(srcFile);
            fclose(destFile);
        }

        rewinddir(destDir);
    }

    closedir(srcDir);
    closedir(destDir);

    printf("Sync operation completed.\n");
}

int main(int argc, char *argv[]) {
    // Checking for correct usage
    if (argc != 3) {
        printf("Usage: ./sync [source directory] [destination directory]\n");
        exit(0);
    }

    char *srcPath = argv[1];
    char *destPath = argv[2];

    syncDirectories(srcPath, destPath);

    return 0;
}