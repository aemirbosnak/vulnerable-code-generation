//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

// This function converts bytes to human-readable format
void humanReadable(double sizeInBytes, char* buffer, int bufferSize) {
    const char* units[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    double convertedSize = sizeInBytes;
    int unitIndex = 0;
    while(convertedSize >= 1024 && unitIndex < (sizeof(units)/sizeof(const char*)) - 1) {
        convertedSize /= 1024;
        unitIndex++;
    }
    sprintf(buffer, "%.2f %s", convertedSize, units[unitIndex]);
}

int main() {
    struct statvfs fsStats;
    char drivePath[256];

    // Get the path of the C disk drive
    printf("Enter the path of the C disk drive: ");
    scanf("%s", drivePath);

    // Get the stats for the file system of the C disk drive
    if(statvfs(drivePath, &fsStats) != 0) {
        printf("Error: couldn't get file system stats\n");
        return 1;
    }

    // Compute the total, used, and free disk space and print them out
    double totalSpace = (double)fsStats.f_frsize * fsStats.f_blocks;
    double freeSpace = (double)fsStats.f_frsize * fsStats.f_bfree;
    double usedSpace = totalSpace - freeSpace;
    char totalSpaceStr[64], freeSpaceStr[64], usedSpaceStr[64];
    humanReadable(totalSpace, totalSpaceStr, sizeof(totalSpaceStr));
    humanReadable(freeSpace, freeSpaceStr, sizeof(freeSpaceStr));
    humanReadable(usedSpace, usedSpaceStr, sizeof(usedSpaceStr));

    printf("Total space: %s\n", totalSpaceStr);
    printf("Free space: %s\n", freeSpaceStr);
    printf("Used space: %s\n", usedSpaceStr);

    // Get the directories occupying the most disk space
    DIR* dir = opendir(drivePath);
    if(dir == NULL) {
        printf("Error: couldn't open directory\n");
        return 1;
    }

    double maxDirSize = 0;
    char maxDirPath[256];
    struct dirent* entry;
    while((entry = readdir(dir)) != NULL) {
        if(entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..")) {
            char fullPath[256];
            sprintf(fullPath, "%s/%s", drivePath, entry->d_name);

            struct statvfs fs;
            if(statvfs(fullPath, &fs) == 0) {
                double dirSize = (double)fs.f_frsize * (fs.f_blocks - fs.f_bfree);
                if(dirSize > maxDirSize) {
                    maxDirSize = dirSize;
                    strcpy(maxDirPath, fullPath);
                }
            }
        }
    }
    closedir(dir);

    // Print out the directory with the most disk space
    if(maxDirSize > 0) {
        char maxDirSizeStr[64];
        humanReadable(maxDirSize, maxDirSizeStr, sizeof(maxDirSizeStr));
        printf("\nDirectory occupying the most space: %s (%s)\n", maxDirPath, maxDirSizeStr);
    }

    return 0;
}