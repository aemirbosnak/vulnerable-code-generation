//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

void analyzeDirectory(const char* path);
void analyzeFile(const char* path);

void analyzeDirectory(const char* path)
{
    int totalSize = 0;
    DIR* directory = opendir(path);
    struct dirent* dirContent;

    if (!directory) {
        printf("Cannot open directory: %s\n", path);
        return;
    }

    while ((dirContent = readdir(directory)) != NULL) {
        if (strcmp(dirContent->d_name, ".") == 0 || strcmp(dirContent->d_name, "..") == 0) {
            continue;
        }
        char newPath[BUFFER_SIZE];
        snprintf(newPath, BUFFER_SIZE, "%s/%s", path, dirContent->d_name);

        if (dirContent->d_type == DT_DIR) {
            analyzeDirectory(newPath);
        } else {
            totalSize += dirContent->d_reclen;
            analyzeFile(newPath);
        }
    }

    printf("Directory %s contains %d bytes\n", path, totalSize);

    closedir(directory);
}

void analyzeFile(const char* path)
{
    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Cannot open file: %s\n", path);
        return;
    }
    long fileSize;

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    fclose(file);

    printf("File %s has %ld bytes\n", path, fileSize);
}

int main()
{
    analyzeDirectory(".");
    return 0;
}