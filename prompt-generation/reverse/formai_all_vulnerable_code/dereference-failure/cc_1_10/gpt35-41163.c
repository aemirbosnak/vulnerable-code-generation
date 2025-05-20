//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define KB 1024
#define MB 1024*KB

// function to recursively calculate disk space usage
unsigned long long calculateDiskSpaceUsage(char *path)
{
    DIR *dir;
    struct dirent *entry;
    unsigned long long totalSize = 0;

    dir = opendir(path);
    if (dir == NULL) {
        printf("Could not open directory: %s\n", path);
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char newPath[strlen(path) + strlen(entry->d_name) + 2];
            sprintf(newPath, "%s/%s", path, entry->d_name);
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                totalSize += calculateDiskSpaceUsage(newPath);
            }
        } else {
            char filePath[strlen(path) + strlen(entry->d_name) + 2];
            sprintf(filePath, "%s/%s", path, entry->d_name);
            FILE *file = fopen(filePath, "rb");
            if (file != NULL) {
                fseek(file, 0, SEEK_END);
                unsigned long long fileSize = ftell(file);
                fclose(file);
                totalSize += fileSize;
            }
        }
    }

    closedir(dir);

    return totalSize;
}

int main()
{
    printf("Welcome to the Medieval C Disk Space Analyzer!\n");
    printf("Enter the path to the directory you would like to analyze: ");
    char path[200];
    fgets(path, sizeof(path), stdin);
    path[strcspn(path, "\n")] = '\0'; // remove '\n' character from input string

    printf("Analyzing disk space usage...\n");

    unsigned long long totalSize = calculateDiskSpaceUsage(path);

    printf("Total disk space used by directory \"%s\": \n", path);

    if (totalSize >= MB) {
        printf("%llu MB\n", totalSize / MB);
    } else if (totalSize >= KB) {
        printf("%llu KB\n", totalSize / KB);
    } else {
        printf("%llu Bytes\n", totalSize);
    }

    return 0;
}