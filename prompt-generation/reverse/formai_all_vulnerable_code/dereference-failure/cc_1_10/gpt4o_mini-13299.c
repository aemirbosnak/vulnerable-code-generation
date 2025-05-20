//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <dirent.h>
#include <limits.h>

#define MAX_PATH 4096
#define KB 1024
#define MB (KB * KB)
#define GB (MB * KB)

void displayDiskUsage(const char *path);
void recursiveDiskUsage(const char *path, long long *totalSize);
void printHumanReadableSize(long long size);

int main(int argc, char *argv[]) {
    char *directoryPath;

    if (argc > 1) {
        directoryPath = argv[1];
    } else {
        directoryPath = "."; // default to current directory
    }

    printf("Analyzing disk usage for: %s\n", directoryPath);
    displayDiskUsage(directoryPath);

    return 0;
}

void displayDiskUsage(const char *path) {
    struct statvfs stat;
    if (statvfs(path, &stat) != 0) {
        perror("Error getting filesystem information");
        return;
    }

    long long totalSize = stat.f_blocks * stat.f_frsize; // Total size
    long long freeSize = stat.f_bfree * stat.f_frsize;   // Free space
    long long usedSize = totalSize - freeSize;            // Used space

    printf("Total Size: ");
    printHumanReadableSize(totalSize);
    printf("Free Size: ");
    printHumanReadableSize(freeSize);
    printf("Used Size: ");
    printHumanReadableSize(usedSize);

    long long dirSize = 0;
    recursiveDiskUsage(path, &dirSize);
    printf("Size of directory '%s': ", path);
    printHumanReadableSize(dirSize);
}

void recursiveDiskUsage(const char *path, long long *totalSize) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    char fullPath[MAX_PATH];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip the special entries
        }

        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // It's a directory, recurse into it
            recursiveDiskUsage(fullPath, totalSize);
        } else {
            // It's a file, accumulate its size
            FILE *file = fopen(fullPath, "rb");
            if (file) {
                fseek(file, 0, SEEK_END);
                long long fileSize = ftell(file);
                *totalSize += fileSize;
                fclose(file);
            } else {
                perror("Error opening file");
            }
        }
    }
    closedir(dir);
}

void printHumanReadableSize(long long size) {
    if (size >= GB) {
        printf("%.2f GB\n", (double)size / GB);
    } else if (size >= MB) {
        printf("%.2f MB\n", (double)size / MB);
    } else if (size >= KB) {
        printf("%.2f KB\n", (double)size / KB);
    } else {
        printf("%lld Bytes\n", size);
    }
}