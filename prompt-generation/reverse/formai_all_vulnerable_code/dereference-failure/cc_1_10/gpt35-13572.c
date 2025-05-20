//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// function to calculate directory size
long long int calcDirSize(char *dirPath)
{
    DIR *directory = opendir(dirPath);
    struct dirent *entry;
    struct stat statbuf;
    long long int dirSize = 0;

    if (directory == NULL) {
        printf("Error opening directory at path '%s'\n", dirPath);
        return -1;
    }

    // iterate over files and directories in the given directory path
    while ((entry = readdir(directory)) != NULL) {
        char childPath[1000];
        sprintf(childPath, "%s/%s", dirPath, entry->d_name);
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        if (stat(childPath, &statbuf) == -1) {
            printf("Error getting file stats for file '%s'\n", childPath);
            continue;
        }
        if (S_ISDIR(statbuf.st_mode)) {
            // if directory, recursively calculate directory size
            dirSize += calcDirSize(childPath);
        } else {
            // if file, add file size to directory size
            dirSize += statbuf.st_size;
        }
    }

    closedir(directory);
    return dirSize;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: %s <directory path>\n", argv[0]);
        return -1;
    }

    char *dirPath = argv[1];
    printf("Calculating size of directory at path '%s'\n", dirPath);

    // calculate directory size
    long long int dirSize = calcDirSize(dirPath);

    if (dirSize == -1) {
        return -1;
    }

    // print results
    printf("Total size of directory at path '%s' is %lld bytes.\n", dirPath, dirSize);

    return 0;
}