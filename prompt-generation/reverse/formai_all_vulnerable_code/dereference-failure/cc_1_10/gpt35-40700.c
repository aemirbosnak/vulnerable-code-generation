//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define MAXDIRSIZE 1000

long long int calculateDirectorySize(char *directoryPath);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please provide the directory path as an argument.\n");
        exit(0);
    }

    char *directoryPath = argv[1];

    long long int size = calculateDirectorySize(directoryPath);

    printf("The size of the directory %s is %lld bytes.\n", directoryPath, size);

    return 0;
}

long long int calculateDirectorySize(char *directoryPath) {
    DIR *directory = opendir(directoryPath);

    if (directory == NULL) {
        printf("Could not open directory %s.\n", directoryPath);
        return 0;
    }

    struct dirent *entry = readdir(directory);
    char path[MAXDIRSIZE];
    long long int size = 0;

    while (entry) {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(path, sizeof(path), "%s/%s", directoryPath, entry->d_name);
            size += calculateDirectorySize(path);
        } else {
            snprintf(path, sizeof(path), "%s/%s", directoryPath, entry->d_name);
            struct stat fileStat;
            if (stat(path, &fileStat) == 0) {
                size += fileStat.st_size;
            }
        }

        entry = readdir(directory);
    }

    closedir(directory);

    return size;
}