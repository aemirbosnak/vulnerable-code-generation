//FormAI DATASET v1.0 Category: File Synchronizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

// Function to check if a file exists
int fileExists(char *fileName) {
    FILE *file = fopen(fileName, "r");

    if (file) {
        fclose(file);
        return 1;
    } else {
        return 0;
    }
}

// Function to get the modification time of a file
time_t getModifiedTime(char *fileName) {
    struct stat attrib;
    stat(fileName, &attrib);
    return attrib.st_mtime;
}

// Function to copy a file
void copyFile(char *srcFile, char *destFile) {
    FILE *src = fopen(srcFile, "rb");
    FILE *dest = fopen(destFile, "wb");
    char buffer[1024];

    if (src == NULL) {
        printf("Error opening source file");
        exit(EXIT_FAILURE);
    }

    if (dest == NULL) {
        printf("Error opening destination file");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof buffer, src)) {
        fprintf(dest, "%s", buffer);
    }

    fclose(src);
    fclose(dest);
}

// Function to synchronize two folders
void syncFolders(char *srcFolder, char *destFolder) {
    DIR *dir;
    struct dirent *ent;
    char srcPath[256], destPath[256];
    time_t srcModTime, destModTime;

    if ((dir = opendir(srcFolder)) == NULL) {
        printf("Error opening source folder");
        exit(EXIT_FAILURE);
    }

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
            // Build source and destination paths
            sprintf(srcPath, "%s/%s", srcFolder, ent->d_name);
            sprintf(destPath, "%s/%s", destFolder, ent->d_name);

            // Check if file exists in destination folder
            if (!fileExists(destPath)) {
                // File does not exist in destination folder, copy it over
                copyFile(srcPath, destPath);
                printf("%s copied to %s\n", srcPath, destPath);
            } else {
                // File exists in destination folder, compare modification times
                srcModTime = getModifiedTime(srcPath);
                destModTime = getModifiedTime(destPath);

                if (difftime(srcModTime, destModTime) > 0) {
                    // Source file is newer, copy it over
                    copyFile(srcPath, destPath);
                    printf("%s updated in %s\n", ent->d_name, destFolder);
                }
            }
        }
    }

    closedir(dir);
}

// Main function
int main() {
    char *srcFolder = "./src";
    char *destFolder = "./dest";
    syncFolders(srcFolder, destFolder);
    return 0;
}