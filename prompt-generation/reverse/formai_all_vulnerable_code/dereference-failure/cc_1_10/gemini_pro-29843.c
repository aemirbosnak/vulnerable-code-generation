//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    int files;
    int directories;
    long size;
} DiskUsage;

DiskUsage analyzeDiskSpace(const char *path) {
    DiskUsage usage = {0, 0, 0};

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return usage;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }

        char fullPath[strlen(path) + strlen(entry->d_name) + 2];
        sprintf(fullPath, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (lstat(fullPath, &statbuf) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            usage.directories++;
            usage = analyzeDiskSpace(fullPath);
        } else {
            usage.files++;
            usage.size += statbuf.st_size;
        }
    }

    closedir(dir);

    return usage;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dir>\n", argv[0]);
        return 1;
    }

    DiskUsage usage = analyzeDiskSpace(argv[1]);

    printf("Files: %d\n", usage.files);
    printf("Directories: %d\n", usage.directories);
    printf("Size: %ld bytes\n", usage.size);

    return 0;
}