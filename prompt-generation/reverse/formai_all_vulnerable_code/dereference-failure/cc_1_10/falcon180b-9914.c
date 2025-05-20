//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long size;
} FileInfo;

void getDirSize(const char *path, unsigned long long *totalSize) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", path);
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char subPath[MAX_PATH];
            snprintf(subPath, MAX_PATH, "%s/%s", path, ent->d_name);
            getDirSize(subPath, totalSize);
        } else {
            FileInfo fileInfo;
            snprintf(fileInfo.path, MAX_PATH, "%s/%s", path, ent->d_name);
            struct statvfs statInfo;
            if (statvfs(fileInfo.path, &statInfo) == 0) {
                fileInfo.size = statInfo.f_blocks * statInfo.f_frsize;
                *totalSize += fileInfo.size;
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    unsigned long long totalSize = 0;
    getDirSize(argv[1], &totalSize);

    printf("Total size of '%s': %llu bytes\n", argv[1], totalSize);

    return 0;
}