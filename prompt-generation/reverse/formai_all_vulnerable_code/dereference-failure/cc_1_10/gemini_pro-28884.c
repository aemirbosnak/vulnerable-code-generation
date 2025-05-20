//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define KILOBYTE 1024
#define MEGABYTE (KILOBYTE * 1024)
#define GIGABYTE (MEGABYTE * 1024)

typedef struct {
    long long size;
    char name[256];
} FileInfo;

int compareFiles(const void *a, const void *b) {
    FileInfo *fa = (FileInfo *)a;
    FileInfo *fb = (FileInfo *)b;
    return fb->size - fa->size;
}

void printDiskUsage(const char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    long long totalSize = 0;
    long long largestSize = 0;
    char largestFile[256] = {0};

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        char filePath[512];
        snprintf(filePath, sizeof(filePath), "%s/%s", path, entry->d_name);

        struct stat fileStat;
        if (stat(filePath, &fileStat) != 0) {
            perror("stat");
            continue;
        }

        // Check if it's a file
        if (S_ISREG(fileStat.st_mode)) {
            totalSize += fileStat.st_size;
            if (fileStat.st_size > largestSize) {
                largestSize = fileStat.st_size;
                strcpy(largestFile, entry->d_name);
            }
        }
    }

    closedir(dir);

    // Convert to human-readable units
    double totalSizeMB = (double)totalSize / MEGABYTE;
    double largestSizeMB = (double)largestSize / MEGABYTE;

    // Print the disk usage
    printf("Disk usage for %s:\n", path);
    printf("Total size: %.2f MB\n", totalSizeMB);
    printf("Largest file: %s (%.2f MB)\n", largestFile, largestSizeMB);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printDiskUsage(argv[1]);

    return EXIT_SUCCESS;
}