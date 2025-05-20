//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

long long int totalSize = 0;

void analyzeDirectory(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    if ((dir = opendir(path)) == NULL) {
        fprintf(stderr, "Failed to open directory: %s\n", path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char subpath[MAX_PATH];
        snprintf(subpath, MAX_PATH, "%s/%s", path, entry->d_name);
        if (lstat(subpath, &statbuf) == -1) {
            fprintf(stderr, "Failed to get information about %s\n", subpath);
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            analyzeDirectory(subpath);
        } else {
            totalSize += statbuf.st_size;
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    analyzeDirectory(argv[1]);

    printf("Total size: %lld bytes\n", totalSize);

    return 0;
}