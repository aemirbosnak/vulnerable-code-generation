//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>

long calculateFileSize(char*);
void diskSpaceAnalyzer(char*);

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: %s [directory path]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* path = argv[1];
    if(access(path, F_OK) != 0) {
        printf("Error: Directory does not exist.\n");
        exit(EXIT_FAILURE);
    }

    diskSpaceAnalyzer(path);
    return 0;
}

void diskSpaceAnalyzer(char* path) {
    DIR* dir = opendir(path);
    struct dirent* entry;
    struct stat fileStat;
    long totalSize = 0;

    printf("\nDirectory: %s\n\n", path);

    while((entry = readdir(dir)) != NULL) {
        char filePath[1024];
        snprintf(filePath, sizeof(filePath), "%s/%s", path, entry->d_name);

        if(lstat(filePath, &fileStat) == -1) {
            printf("Error: File stat could not be obtained. Ignoring %s", filePath);
            continue;
        }

        if(S_ISDIR(fileStat.st_mode)) {
            // This is a directory
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                // Ignore current and parent directory
                continue;
            }
            diskSpaceAnalyzer(filePath); // Recursive call
        }
        else {
            // This is a file
            long fileSize = calculateFileSize(filePath);
            printf("%-20ld %s\n", fileSize, filePath);
            totalSize += fileSize;
        }
    }

    closedir(dir);
    printf("\nTotal size: %ld bytes\n", totalSize);
}

long calculateFileSize(char* path) {
    struct stat fileStat;
    if(lstat(path, &fileStat) == -1) {
        printf("Error: File stat could not be obtained. Ignoring %s", path);
        return 0;
    }
    return fileStat.st_size;
}