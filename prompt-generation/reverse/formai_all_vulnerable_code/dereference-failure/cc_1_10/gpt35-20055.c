//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void analyzeDirectory(char *path, long long *totalSpace);

int main() {
    long long totalSpace = 0;
    char basePath[100];
    printf("Enter the path to analyze: ");
    scanf("%s", basePath);

    analyzeDirectory(basePath, &totalSpace);

    printf("Total space used: %lld bytes\n", totalSpace);

    return 0;
}

void analyzeDirectory(char *path, long long *totalSpace) {
    DIR *directory = opendir(path);
    if(directory == NULL) {
        printf("Error opening directory: %s\n", path);
        return;
    }

    struct dirent *dirEntry;
    while((dirEntry = readdir(directory)) != NULL) {
        char entryPath[100];
        sprintf(entryPath, "%s/%s", path, dirEntry->d_name);

        if(dirEntry->d_type == DT_REG) {
            FILE *file = fopen(entryPath, "rb");
            if(file == NULL) {
                printf("Error opening file: %s\n", entryPath);
                continue;
            }

            fseek(file, 0L, SEEK_END);
            long long fileSize = ftell(file);
            *totalSpace += fileSize;

            fclose(file);
        }
        else if(dirEntry->d_type == DT_DIR && strcmp(dirEntry->d_name, ".") && strcmp(dirEntry->d_name, "..")) {
            analyzeDirectory(entryPath, totalSpace);
        }
    }

    closedir(directory);
}