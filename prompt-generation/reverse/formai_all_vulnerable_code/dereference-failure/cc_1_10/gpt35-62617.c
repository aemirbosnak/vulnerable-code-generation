//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

struct DiskStatus {
    char name[256];
    unsigned long long totalSize;
    unsigned long long freeSize;
};

void analyzeDiskSpace(const char* path, struct DiskStatus* status)
{
    struct statvfs fs_stat;

    if (statvfs(path, &fs_stat) == -1) {
        sprintf(status->name, "%s", path);
        status->totalSize = 0;
        status->freeSize = 0;
        return;
    }

    sprintf(status->name, "%s", path);
    status->totalSize = (unsigned long long) fs_stat.f_frsize * fs_stat.f_blocks;
    status->freeSize = (unsigned long long) fs_stat.f_frsize * fs_stat.f_bfree;
}

void printDiskStatus(const struct DiskStatus* status)
{
    if (status->totalSize == 0) {
        printf("Error: could not analyze disk space for %s\n", status->name);
    } else {
        double usedPercentage = ((double) status->totalSize - (double) status->freeSize) / (double) status->totalSize * 100.0;
        printf("%s\n", status->name);
        printf("Total size: %llu bytes\n", status->totalSize);
        printf("Free size: %llu bytes\n", status->freeSize);
        printf("Used: %.1f%%\n", usedPercentage);
    }
}

void analyzeAllDiskSpace(const char* path)
{
    DIR* dir;
    struct dirent* entry;
    struct DiskStatus status;

    if ((dir = opendir(path)) == NULL) {
        printf("Could not open directory %s\n", path);
        return;
    }

    printf("Disk space analysis for directory: %s\n", path);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // ignore hidden files
        }
        char subpath[512];
        sprintf(subpath, "%s/%s", path, entry->d_name);
        analyzeDiskSpace(subpath, &status);
        printDiskStatus(&status);
        printf("\n");
    }
    closedir(dir);
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        exit(1);
    }
    analyzeAllDiskSpace(argv[1]);
    return 0;
}