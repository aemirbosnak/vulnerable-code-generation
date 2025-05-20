//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// function to calculate size of directory
long int dirSize(char *path) {
    struct dirent *entry;
    struct stat info;
    DIR *dir;

    long int size = 0;

    dir = opendir(path);
    if (!dir) {
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char newPath[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            snprintf(newPath, sizeof(newPath), "%s/%s", path, entry->d_name);
            size += dirSize(newPath);
        } else {
            char filePath[1024];
            snprintf(filePath, sizeof(filePath), "%s/%s", path, entry->d_name);
            stat(filePath, &info);
            size += info.st_size;
        }
    }

    closedir(dir);
    return size;
}

int main(int argc, char **argv) {
    char *path;

    if (argc < 2) {
        path = ".";
    } else {
        path = argv[1];
    }

    printf("Scanning path %s\n\n", path);

    long int size = dirSize(path);
    if (size == -1) {
        printf("Error: Could not scan path\n");
        return 1;
    }

    float sizeKB = size / 1024.0;
    float sizeMB = sizeKB / 1024.0;

    printf("Total size: %.2f MB\n", sizeMB);

    return 0;
}