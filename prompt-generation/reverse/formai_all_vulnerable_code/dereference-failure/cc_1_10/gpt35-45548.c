//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int isDirectory(char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

long long getFolderSize(char *path) {
    long long totalSize = 0;
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(path)) == NULL) {
        perror("Error: Failed to open directory.");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        char fullPath[1024];

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        strcpy(fullPath, path);
        strcat(fullPath, "/");
        strcat(fullPath, entry->d_name);

        if (isDirectory(fullPath)) {
            totalSize += getFolderSize(fullPath);
        } else {
            struct stat st;
            if (stat(fullPath, &st) == 0) {
                totalSize += st.st_size;
            }
        }
    }

    closedir(dir);
    return totalSize;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./c-disk-space-analyzer <directory-path>\n");
        return 1;
    }

    long long totalSize = getFolderSize(argv[1]);

    if (totalSize == -1) {
        return 1;
    }

    printf("Total size of directory %s is %lld bytes.\n", argv[1], totalSize);
    return 0;
}