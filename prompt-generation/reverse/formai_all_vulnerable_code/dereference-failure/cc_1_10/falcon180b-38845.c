//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_DEPTH 100

typedef struct {
    char path[MAX_DEPTH];
    unsigned long long size;
} DirEntry;

void addDirEntry(DirEntry *dirEntry, const char *path, unsigned long long size) {
    strncpy(dirEntry->path, path, MAX_DEPTH - 1);
    dirEntry->path[MAX_DEPTH - 1] = '\0';
    dirEntry->size += size;
}

void analyzeDir(const char *path, int depth) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    DirEntry rootEntry = { { 0 }, 0 };
    DirEntry *currentEntry = &rootEntry;

    struct dirent *dirent;
    while ((dirent = readdir(dir))!= NULL) {
        if (dirent->d_type == DT_DIR) {
            char childPath[MAX_DEPTH];
            snprintf(childPath, MAX_DEPTH, "%s/%s", path, dirent->d_name);
            analyzeDir(childPath, depth + 1);
        } else {
            struct stat statBuf;
            snprintf(currentEntry->path + strlen(currentEntry->path), MAX_DEPTH - strlen(currentEntry->path), "/%s", dirent->d_name);
            if (stat(currentEntry->path, &statBuf) == 0) {
                currentEntry->size += statBuf.st_size;
            }
        }
    }

    closedir(dir);

    if (depth == 0) {
        printf("Total size of %s: %llu bytes\n", path, rootEntry.size);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyzeDir(argv[1], 0);

    return 0;
}