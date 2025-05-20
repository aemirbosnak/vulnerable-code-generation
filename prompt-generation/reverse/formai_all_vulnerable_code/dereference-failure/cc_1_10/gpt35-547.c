//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

const char* getSize(unsigned long long size) {
    static char buffer[20];
    const char* units[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    int i;
    double sz = (double) size;
    for(i = 0; i < sizeof(units)/sizeof(units[0]) - 1 && sz >= 1024.0; i++) {
        sz /= 1024.0;
    }
    sprintf(buffer, "%.2f %s", sz, units[i]);
    return buffer;
}

unsigned long long getDirectorySize(const char* directory) {
    struct dirent *entry;
    unsigned long long size = 0;
    DIR* dir = opendir(directory);
    if (dir == NULL) {
        return 0;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[4096];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
            size += getDirectorySize(path);
        } else {
            struct stat statbuf;
            char path[4096];
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
            if (stat(path, &statbuf) != -1) {
                size += statbuf.st_size;
            }
        }
    }
    closedir(dir);
    return size;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    unsigned long long totalSize = getDirectorySize(argv[1]);
    printf("Total size of %s: %s\n", argv[1], getSize(totalSize));
    return 0;
}