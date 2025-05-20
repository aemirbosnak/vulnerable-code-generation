//FormAI DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void synchronize(char* source, char* destination) {
    DIR* dir;
    struct dirent* dirent;
    char* sourcePath;
    char* destinationPath;
    
    // Open directory
    dir = opendir(source);
    if(dir == NULL) {
        printf("Error opening directory: %s\n", source);
        return;
    }

    // Iterate through directory
    while((dirent = readdir(dir)) != NULL) {
        // Ignore current and parent directory
        if(strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        // Construct source and destination paths
        sourcePath = malloc(strlen(source) + strlen(dirent->d_name) + 2);
        sprintf(sourcePath, "%s/%s", source, dirent->d_name);
        destinationPath = malloc(strlen(destination) + strlen(dirent->d_name) + 2);
        sprintf(destinationPath, "%s/%s", destination, dirent->d_name);

        // Check if file exists in destination directory
        FILE* destinationFile = fopen(destinationPath, "r");
        if(destinationFile == NULL) {
            // File does not exist in destination directory, copy from source directory
            FILE* sourceFile = fopen(sourcePath, "r");
            if(sourceFile == NULL) {
                printf("Error copying file: %s\n", sourcePath);
            } else {
                FILE* destinationFile = fopen(destinationPath, "w");
                if(destinationFile == NULL) {
                    printf("Error creating file: %s\n", destinationPath);
                } else {
                    int byte;
                    while((byte = fgetc(sourceFile)) != EOF) {
                        fputc(byte, destinationFile);
                    }
                    printf("Copied file: %s to %s\n", sourcePath, destinationPath);
                    fclose(destinationFile);
                }
                fclose(sourceFile);
            }
        } else {
            fclose(destinationFile);
        }

        // Free memory
        free(sourcePath);
        free(destinationPath);
    }

    // Close directory
    closedir(dir);
}

int main() {
    // Synchronize files
    synchronize("source_directory", "destination_directory");

    return 0;
}