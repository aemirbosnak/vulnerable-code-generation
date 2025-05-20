//FormAI DATASET v1.0 Category: File Synchronizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Function to check if directory exists
int isDirExists(const char *path) {
    struct stat info;
    if (stat(path, &info) != 0) {
        return 0;
    }
    else if (info.st_mode & S_IFDIR) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to recursively copy files from source to destination directory
void copyDirectory(char *source, char *destination) {
    DIR *dir;
    struct dirent *entry;
    char sourcePath[256], destPath[256];

    if (!(dir = opendir(source))) {
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            sprintf(sourcePath, "%s/%s", source, entry->d_name);
            sprintf(destPath, "%s/%s", destination, entry->d_name);
            if (!isDirExists(destPath)) {
                mkdir(destPath, 0777); // Create directory if it doesn't exist
            }
            copyDirectory(sourcePath, destPath);
        } else {
            sprintf(sourcePath, "%s/%s", source, entry->d_name);
            sprintf(destPath, "%s/%s", destination, entry->d_name);
            FILE *srcFile = fopen(sourcePath, "r");
            FILE *destFile = fopen(destPath, "w");
            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), srcFile)) {
                fputs(buffer, destFile);
            }
            fclose(srcFile);
            fclose(destFile);
        }
    }
}

int main() {
    char sourcePath[256], destPath[256];

    printf("Enter source directory path: ");
    scanf("%s", sourcePath);

    printf("Enter destination directory path: ");
    scanf("%s", destPath);

    DIR *sourceDir = opendir(sourcePath);
    DIR *destDir = opendir(destPath);

    if (!sourceDir) {
        printf("Source directory does not exist!\n");
        return 1;
    }
    if (!destDir) {
        mkdir(destPath, 0777);
    }
    closedir(sourceDir);
    closedir(destDir);

    printf("Copying files from %s to %s ...\n", sourcePath, destPath);
    copyDirectory(sourcePath, destPath);
    printf("Done.\n");

    return 0;
}