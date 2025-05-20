//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 256

// Function to convert file size from bytes to human-readable format
void convertSize(unsigned long long size, char* convertedSize) {
    const char* SIZES[] = {"B", "KB", "MB", "GB", "TB"};
    int div = 0;
    double doubleSize = (double)size;
    while (doubleSize >= 1024 && div < (sizeof(SIZES) / sizeof(SIZES[0])) - 1) {
        div++;
        doubleSize /= 1024.0;
    }
    sprintf(convertedSize, "%.2f %s", doubleSize, SIZES[div]);
}

// Function to get the size of the directory
unsigned long long getDirectorySize(char* path) {
    unsigned long long totalSize = 0;
    DIR* dir = opendir(path);
    if (dir != NULL) {
        struct dirent* entry;
        while ((entry = readdir(dir)) != NULL) {
            struct stat fileInfo;
            char filePath[MAX_PATH_LENGTH];
            snprintf(filePath, sizeof(filePath), "%s/%s", path, entry->d_name);
            if (stat(filePath, &fileInfo) == 0 && S_ISREG(fileInfo.st_mode)) {
                totalSize += fileInfo.st_size;
            } else if (stat(filePath, &fileInfo) == 0 && S_ISDIR(fileInfo.st_mode)) {
                if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                    totalSize += getDirectorySize(filePath);
                }
            }
        }
        closedir(dir);
    }
    return totalSize;
}

int main() {
    char directoryPath[MAX_PATH_LENGTH];
    printf("Welcome to CyberDiskSpaceAnalyzer!\n");
    printf("Please enter the path of the directory you want to analyze: ");
    fgets(directoryPath, sizeof(directoryPath), stdin);
    directoryPath[strcspn(directoryPath, "\n")] = '\0'; // Remove newline character
    printf("Analyzing directory: %s\n", directoryPath);
    printf("Calculating size...\n");
    unsigned long long size = getDirectorySize(directoryPath);
    printf("Total size of directory: ");
    char convertedSize[20];
    convertSize(size, convertedSize);
    printf("%s\n", convertedSize);
    printf("Thank you for using CyberDiskSpaceAnalyzer!\n");
    return 0;
}