//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH_LEN 1024

void analyze_directory(char *path);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [path]\n", argv[0]);
        exit(1);
    }

    analyze_directory(argv[1]);

    return 0;
}

void analyze_directory(char *path) {
    DIR *dirp = opendir(path);

    if (dirp == NULL) {
        printf("Failed to open directory: %s\n", path);
        exit(1);
    }

    struct dirent *direntp;
    struct stat statbuf;
    char new_path[MAX_PATH_LEN];

    while ((direntp = readdir(dirp)) != NULL) {
        if (strcmp(direntp->d_name, ".") == 0 || strcmp(direntp->d_name, "..") == 0) {
            continue;
        }

        sprintf(new_path, "%s/%s", path, direntp->d_name);

        if (lstat(new_path, &statbuf) < 0) {
            printf("Failed to stat file: %s\n", new_path);
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(new_path);
        } else {
            printf("%s - %ld bytes\n", new_path, statbuf.st_size);
        }
    }

    closedir(dirp);
}