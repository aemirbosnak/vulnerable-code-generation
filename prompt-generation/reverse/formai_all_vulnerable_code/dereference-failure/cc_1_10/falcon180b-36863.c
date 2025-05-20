//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 256

typedef struct {
    char path[MAX_PATH];
    double size;
} DirEntry;

void readDir(const char* path, void(*callback)(DirEntry*)) {
    DIR* dir = opendir(path);
    if (!dir) {
        fprintf(stderr, "Error: could not open directory '%s'\n", path);
        exit(1);
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        char fullPath[MAX_PATH];
        snprintf(fullPath, MAX_PATH, "%s/%s", path, ent->d_name);

        DirEntry entry = {
           .path = fullPath,
           .size = 0
        };

        statvfs(fullPath, &entry.size);
        callback(&entry);
    }

    closedir(dir);
}

void printDirEntry(DirEntry* entry) {
    printf("%-40s %.2f MB\n", entry->path, entry->size / (1024.0 * 1024.0));
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char path[MAX_PATH];
    snprintf(path, MAX_PATH, "%s", argv[1]);

    readDir(path, printDirEntry);

    return 0;
}