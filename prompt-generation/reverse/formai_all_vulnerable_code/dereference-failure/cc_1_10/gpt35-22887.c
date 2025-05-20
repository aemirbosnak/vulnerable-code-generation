//FormAI DATASET v1.0 Category: File Synchronizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

// Function to retrieve the file names in a directory
int getFilesInDirectory(char *path, char **files) {
    DIR *directory;
    struct dirent *entry;
    int count = 0;

    directory = opendir(path);
    if (directory == NULL) {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }

    // Loop through each file in the directory
    while ((entry = readdir(directory))) {
        if (entry->d_type == DT_REG) { // Regular file
            char *filename = malloc(strlen(entry->d_name) + 1); // Allocate space for filename
            strcpy(filename, entry->d_name); // Copy filename to allocated space
            files[count] = filename; // Add filename to array
            count++; // Increment file count
        }
    }

    closedir(directory);
    return count; // Return number of files found
}

// Function to sync files in two directories
void syncDirectories(char *sourceDir, char *destinationDir) {
    char *sourceFiles[100];
    char *destinationFiles[100];
    int sourceCount, destinationCount, i, j;

    sourceCount = getFilesInDirectory(sourceDir, sourceFiles);
    destinationCount = getFilesInDirectory(destinationDir, destinationFiles);

    // Loop through each file in the source directory
    for (i = 0; i < sourceCount; i++) {
        int found = 0;
        char *sourceFilePath = malloc(strlen(sourceDir) + strlen(sourceFiles[i]) + 2); // Allocate space for source filepath
        sprintf(sourceFilePath, "%s/%s", sourceDir, sourceFiles[i]); // Build source filepath
        
        // Loop through each file in the destination directory to look for matching file
        for (j = 0; j < destinationCount; j++) {
            char *destinationFilePath = malloc(strlen(destinationDir) + strlen(destinationFiles[j]) + 2); // Allocate space for destination filepath
            sprintf(destinationFilePath, "%s/%s", destinationDir, destinationFiles[j]); // Build destination filepath

            // If matching file is found, update destination file with source file
            if (strcmp(sourceFiles[i], destinationFiles[j]) == 0) {
                found = 1;
                printf("Updating %s\n", destinationFilePath);
                FILE *sourceFile = fopen(sourceFilePath, "r");
                FILE *destinationFile = fopen(destinationFilePath, "w");
                int c;
                while ((c = fgetc(sourceFile)) != EOF) {
                    fputc(c, destinationFile);
                }
                fclose(sourceFile);
                fclose(destinationFile);
            }
            free(destinationFilePath);
        }

        // If matching file is not found, copy source file to destination directory
        if (!found) {
            printf("Copying %s to %s\n", sourceFilePath, destinationDir);
            char *destinationFilePath = malloc(strlen(destinationDir) + strlen(sourceFiles[i]) + 2); // Allocate space for destination filepath
            sprintf(destinationFilePath, "%s/%s", destinationDir, sourceFiles[i]); // Build destination filepath
            FILE *sourceFile = fopen(sourceFilePath, "r");
            FILE *destinationFile = fopen(destinationFilePath, "w");
            int c;
            while ((c = fgetc(sourceFile)) != EOF) {
                fputc(c, destinationFile);
            }
            fclose(sourceFile);
            fclose(destinationFile);
            free(destinationFilePath);
        }

        free(sourceFilePath);
    }

    // Free allocated memory for filename arrays
    for (i = 0; i < sourceCount; i++) {
        free(sourceFiles[i]);
    }
    for (i = 0; i < destinationCount; i++) {
        free(destinationFiles[i]);
    }
}

int main() {
    syncDirectories("/home/user/source", "/home/user/destination"); // Example usage
    return 0;
}