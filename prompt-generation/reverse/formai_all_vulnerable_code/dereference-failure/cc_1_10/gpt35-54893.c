//FormAI DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Function to synchronize two directories
void syncDirectories(const char* sourceDir, const char* destDir) {
    // Open the directories
    DIR* source = opendir(sourceDir);
    DIR* dest = opendir(destDir);

    if(source == NULL || dest == NULL) {
        printf("Unable to open directories.\n");
        return;
    }

    // Read the contents of the source directory
    struct dirent* entry;
    while((entry = readdir(source)) != NULL) {
        // Ignore . and .. directories
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the path to the source file
        char* sourceFilePath = malloc(sizeof(char) * (strlen(sourceDir) + strlen(entry->d_name) + 2));
        sprintf(sourceFilePath, "%s/%s", sourceDir, entry->d_name);

        // Get the file stats
        struct stat sourceStats;
        if(stat(sourceFilePath, &sourceStats) != 0) {
            printf("Unable to get file stats for %s.\n", sourceFilePath);
            free(sourceFilePath);
            continue;
        }

        // If the entry is a directory, create it in the destination if it doesn't already exist and recurse
        if(S_ISDIR(sourceStats.st_mode)) {
            // Construct the path to the destination directory
            char* destDirPath = malloc(sizeof(char) * (strlen(destDir) + strlen(sourceFilePath + strlen(sourceDir)) + 2));
            sprintf(destDirPath, "%s/%s", destDir, sourceFilePath + strlen(sourceDir));

            // If the destination directory doesn't exist, create it
            if(opendir(destDirPath) == NULL) {
                mkdir(destDirPath, sourceStats.st_mode);
            }

            // Recurse
            syncDirectories(sourceFilePath, destDirPath);

            // Free memory
            free(destDirPath);
        }
        // If the entry is a file, copy it to the destination if it doesn't already exist or if it's different
        else if(S_ISREG(sourceStats.st_mode)) {
            // Construct the path to the destination file
            char* destFilePath = malloc(sizeof(char) * (strlen(destDir) + strlen(sourceFilePath + strlen(sourceDir)) + 2));
            sprintf(destFilePath, "%s/%s", destDir, sourceFilePath + strlen(sourceDir));

            // If the destination file doesn't exist or if it's different, copy it
            int sourceFd = open(sourceFilePath, O_RDONLY);
            int destFd = open(destFilePath, O_WRONLY | O_CREAT | O_TRUNC, sourceStats.st_mode);
            if(sourceFd == -1 || destFd == -1) {
                printf("Unable to open file: %s.\n", sourceFilePath);
                free(sourceFilePath);
                free(destFilePath);
                continue;
            }

            // Read and write the file
            ssize_t bytesRead;
            char buffer[1024];
            while((bytesRead = read(sourceFd, buffer, 1024)) > 0) {
                if(write(destFd, buffer, bytesRead) != bytesRead) {
                    printf("Error copying file: %s.\n", sourceFilePath);
                    break;
                }
            }

            // Close the file descriptors
            close(sourceFd);
            close(destFd);

            // Free memory
            free(destFilePath);
        }

        // Free memory
        free(sourceFilePath);
    }

    // Close the directories
    closedir(source);
    closedir(dest);
}

int main(int argc, char* argv[]) {
    // Make sure the correct number of arguments are passed
    if(argc != 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Synchronize the directories
    syncDirectories(argv[1], argv[2]);

    return EXIT_SUCCESS;
}