//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define KB 1024
#define MB (KB * 1024)
#define GB (MB * 1024)

void displaySize(size_t size, char *unit) {
    if (size < KB) {
        sprintf(unit, "B");
    } else if (size >= KB && size < MB) {
        size /= KB;
        sprintf(unit, "KB");
    } else if (size >= MB && size < GB) {
        size /= MB;
        sprintf(unit, "MB");
    } else if (size >= GB) {
        size /= GB;
        sprintf(unit, "GB");
    }
    printf("%lu %s", size, unit);
}

size_t getDirectorySize(const char *path) {
    size_t size = 0;
    DIR *dir;
    struct dirent *entry;
    struct stat info;
    char filePath[FILENAME_MAX];

    if ((dir = opendir(path)) == NULL) {
        fprintf(stderr, "Cannot open directory %s\n", path);
        return size;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            sprintf(filePath, "%s/%s", path, entry->d_name);

            if (stat(filePath, &info) == 0) {
                if (S_ISDIR(info.st_mode)) {
                    size += getDirectorySize(filePath);
                } else {
                    size += info.st_size;
                }
            } else {
                fprintf(stderr, "Cannot get file %s information.\n", filePath);
                return size;
            }
        }
    }

    closedir(dir);
    return size;
}

int main(int argc, char *argv[]) {
    char unit[3] = {'\0'};
    size_t totalSize = 0;

    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        printf("Size of %s: ", argv[i]);
        totalSize = getDirectorySize(argv[i]);
        displaySize(totalSize, unit);
        printf("\n");
    }

    return EXIT_SUCCESS;
}