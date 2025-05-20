//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BYTES_IN_GB 1000000000

long long total_size = 0;
char path[10000];

void traverse_dir(char *dir_path) {
    struct dirent *dp;
    DIR *dir = opendir(dir_path);

    if (!dir) {
        printf("Error: Directory not found.\n");
        return;
    }

    while ((dp = readdir(dir)) != NULL) {
        if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
            continue;

        struct stat file_stat;

        char filepath[1000];
        sprintf(filepath, "%s/%s", dir_path, dp->d_name);

        if (stat(filepath, &file_stat) == -1)
            continue;

        if (S_ISDIR(file_stat.st_mode))
            traverse_dir(filepath);
        else
            total_size += (long long)file_stat.st_size;
    }

    closedir(dir);
}

int main() {
    printf("Welcome to the C Disk Space Analyzer.\n");
    printf("Enter the filepath to analyze:\n");

    fgets(path, sizeof(path), stdin);
    path[strcspn(path, "\r\n")] = 0;

    traverse_dir(path);

    printf("\nTotal Size of '%s' is: %lld Bytes\n", path, total_size);

    float size_in_gb = (float)total_size / BYTES_IN_GB;
    if (size_in_gb > 1)
        printf("%.2f GB\n", size_in_gb);
    else
        printf("%.2f MB\n", (float)total_size / 1000000);

    return 0;
}