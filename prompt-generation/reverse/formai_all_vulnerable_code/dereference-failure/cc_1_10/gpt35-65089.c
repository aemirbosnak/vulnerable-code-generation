//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH_LENGTH 255

// function to calculate the total size of a directory
long int dir_size(char* path) {
    long int size = 0;
    DIR* dirp = opendir(path);
    struct dirent* dp; 
    struct stat file_stat;

    while ((dp = readdir(dirp)) != NULL) {     
        char fpath[MAX_PATH_LENGTH];
        snprintf(fpath, MAX_PATH_LENGTH, "%s/%s", path, dp->d_name);

        if (stat(fpath, &file_stat) == -1) {
            printf("Error opening file\n");
            continue;
        }

        if (S_ISREG(file_stat.st_mode)) {
            size += file_stat.st_size;
        }
        else if (S_ISDIR(file_stat.st_mode)) {
            if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
                continue;
            }
            size += dir_size(fpath);
        }
    }

    closedir(dirp);
    return size;
}

int main() {
    char path[MAX_PATH_LENGTH];
    printf("Enter the path to the directory you wish to analyze: ");
    scanf("%s", path);

    long int dir_size_bytes = dir_size(path);

    printf("Total size of directory %s: %ld bytes\n", path, dir_size_bytes);

    return 0;
}