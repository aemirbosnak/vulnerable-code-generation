//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define BUFFER_SIZE 1024

// Function to get the current date and time
char* getCurrentDateTime() {
    time_t now = time(0);
    struct tm* tm = localtime(&now);
    char* dateTime = malloc(30);
    strftime(dateTime, 30, "%Y-%m-%d %H:%M:%S", tm);
    return dateTime;
}

// Function to print the disk space usage in a human-readable format
void printDiskSpaceUsage(char* path, struct statvfs* stat) {
    double totalSpace = stat->f_blocks * stat->f_frsize;
    double usedSpace = (stat->f_blocks - stat->f_bfree) * stat->f_frsize;
    double freeSpace = stat->f_bfree * stat->f_frsize;

    printf("Disk space usage for %s:\n", path);
    printf("Total space: %.2f GB\n", totalSpace / (1024.0 * 1024.0));
    printf("Used space: %.2f GB\n", usedSpace / (1024.0 * 1024.0));
    printf("Free space: %.2f GB\n", freeSpace / (1024.0 * 1024.0));
}

// Function to get the disk space usage for a directory
void getDiskSpaceUsage(char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Could not open directory %s\n", path);
        exit(1);
    }

    struct statvfs stat;
    if (statvfs(path, &stat) == -1) {
        printf("Error: Could not get disk space usage for %s\n", path);
        exit(1);
    }

    printDiskSpaceUsage(path, &stat);

    closedir(dir);
}

// Function to get the disk space usage for all subdirectories in a directory
void getSubdirectoryDiskSpaceUsage(char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Could not open directory %s\n", path);
        exit(1);
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        char subdirPath[strlen(path) + strlen(ent->d_name) + 2];
        sprintf(subdirPath, "%s/%s", path, ent->d_name);

        if (ent->d_type == DT_DIR) {
            getDiskSpaceUsage(subdirPath);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        exit(1);
    }

    char* directory = argv[1];
    getSubdirectoryDiskSpaceUsage(directory);

    return 0;
}