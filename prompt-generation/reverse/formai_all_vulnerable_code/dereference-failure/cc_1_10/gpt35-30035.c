//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Function to calculate the total disk space used by a directory and its subdirectories
long long calculateDiskSpace(char *directoryPath) {
    long long totalSpace = 0;
    DIR *dir = opendir(directoryPath); // open directory
    struct stat fileStat;
    struct dirent *entry;
    char subPath[1024];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) { // ignore parent directories
            sprintf(subPath, "%s/%s", directoryPath, entry->d_name); // construct subdirectory path
            if (lstat(subPath, &fileStat) == 0) {
                if (S_ISREG(fileStat.st_mode)) { // regular file
                    totalSpace += fileStat.st_size;
                }
                else if (S_ISDIR(fileStat.st_mode)) { // subdirectory
                    totalSpace += calculateDiskSpace(subPath); // recursively calculate disk space of subdirectory
                }
            }
        }
    }
    closedir(dir); // close directory
    return totalSpace;
}

// Function to print the usage instructions
void printUsage() {
    printf("Usage: disk_space_analyzer [directory_path]\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printUsage(); // print usage instructions if no command line argument is provided
        return 0;
    }
    char *directoryPath = argv[1];
    struct stat dirStat;
    if (lstat(directoryPath, &dirStat) == 0) {
        if (S_ISDIR(dirStat.st_mode)) {
            long long totalSpace = calculateDiskSpace(directoryPath);
            printf("Total disk space used by %s and its subdirectories: %lld bytes\n", directoryPath, totalSpace);
            return 0;
        }
        else {
            printf("%s is not a directory.\n", directoryPath);
            return 1;
        }
    }
    else {
        printf("Error: Cannot access %s.\n", directoryPath);
        return 1;
    }
}