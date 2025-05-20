//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void printSize(double size);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    DIR *dir = opendir(argv[1]);

    if (!dir) {
        printf("Error opening directory %s!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    struct stat file_stats;
    double total_size = 0;

    while ((entry = readdir(dir))) {
        char path[512];
        snprintf(path, sizeof path, "%s/%s", argv[1], entry->d_name);

        if (stat(path, &file_stats) == -1) {
            printf("Error getting information for file %s!\n", entry->d_name);
            continue;
        }

        if (S_ISREG(file_stats.st_mode)) {
            printf("%s - ", entry->d_name);
            printSize(file_stats.st_size);
            printf("\n");

            total_size += file_stats.st_size;
        } else if (S_ISDIR(file_stats.st_mode)) {
            if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) {
                continue;
            }

            printf("Analyzing directory %s\n", path);
            double dir_size = 0;

            DIR *subdir = opendir(path);

            if (!subdir) {
                printf("Error opening directory %s!\n", path);
                continue;
            }

            struct dirent *subentry;
            struct stat subfile_stats;

            while ((subentry = readdir(subdir))) {
                char subpath[512];
                snprintf(subpath, sizeof subpath, "%s/%s", path, subentry->d_name);

                if (stat(subpath, &subfile_stats) == -1) {
                    printf("Error getting information for file %s!\n", subentry->d_name);
                    continue;
                }

                if (S_ISREG(subfile_stats.st_mode)) {
                    dir_size += subfile_stats.st_size;
                }
            }

            closedir(subdir);

            printf("%s - ", path);
            printSize(dir_size);
            printf("\n");

            total_size += dir_size;
        }
    }

    closedir(dir);

    printf("Total size of directory %s is ", argv[1]);
    printSize(total_size);
    printf("\n");

    return 0;
}

void printSize(double size) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit = 0;

    while (size > 1024) {
        size /= 1024;
        unit++;
    }

    printf("%.2f %s", size, units[unit]);
}