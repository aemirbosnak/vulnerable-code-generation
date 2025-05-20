//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

/* Function to determine the size of a file */
long int findSize(char *fileName) {
    FILE *fp = fopen(fileName, "r");
    if (!fp) {
        perror("Unable to open file");
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    long int totalSize = ftell(fp);
    fclose(fp);
    return totalSize;
}

/* Function to determine the disk space used in a directory */
long int calculateDiskSpace(char *directory) {
    DIR *dir = opendir(directory);
    if (!dir) {
        perror("Unable to open directory");
        return -1;
    }
    
    struct dirent *entry;
    long int totalSpace = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        /* Construct the path to the file/directory */
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

        /* Use stat to determine if it is a directory or file */
        struct stat fileStat;
        if (stat(path, &fileStat) < 0) {
            continue;
        }
        if (S_ISDIR(fileStat.st_mode)) {
            totalSpace += calculateDiskSpace(path); /* Recursive call for subdirectories */
        } else {
            totalSpace += findSize(path);
        }
    }
    closedir(dir);
    return totalSpace;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return -1;
    }
    long int totalSpace = calculateDiskSpace(argv[1]);
    if (totalSpace > 0) {
        printf("The total disk space used in %s is %ld bytes.\n", argv[1], totalSpace);
    } else {
        printf("Unable to calculate disk space usage.\n");
    }
    return 0;
}