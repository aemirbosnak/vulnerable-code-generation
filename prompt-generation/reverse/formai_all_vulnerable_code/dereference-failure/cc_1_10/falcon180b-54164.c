//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *path;
    unsigned long long size;
} FileInfo;

void traverseDirectory(const char *path, void (*callback)(FileInfo *)) {
    DIR *dir = opendir(path);
    if (!dir) {
        fprintf(stderr, "Error: Failed to open directory '%s'\n", path);
        return;
    }

    char buffer[BUFFER_SIZE];
    while ((struct dirent *)readdir(dir)!= NULL) {
        FileInfo info;
        memset(&info, 0, sizeof(info));

        if (strcmp(buffer, ".") == 0 || strcmp(buffer, "..") == 0) {
            continue;
        }

        info.path = strdup(path);
        strcat(info.path, "/");
        strcat(info.path, buffer);

        struct stat st;
        if (stat(info.path, &st) == -1) {
            fprintf(stderr, "Error: Failed to get file info for '%s'\n", info.path);
            free(info.path);
            continue;
        }

        info.size = st.st_size;
        callback(&info);
        free(info.path);
    }

    closedir(dir);
}

void printFileInfo(FileInfo *info) {
    printf("%-40s %10llu bytes\n", info->path, info->size);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char *dirPath = argv[1];
    traverseDirectory(dirPath, printFileInfo);

    return 0;
}