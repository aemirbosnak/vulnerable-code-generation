//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void analyze_directory(char *path);

int main(int argc, char **argv) {
    char *path;

    if (argc > 1) {
        path = argv[1];
    } else {
        path = ".";
    }

    analyze_directory(path);

    return 0;
}

void analyze_directory(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stats;
    long total_size = 0;

    dir = opendir(path);

    if (dir) {
        while ((entry = readdir(dir)) != NULL) {
            char file_path[1024];

            snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);

            if (lstat(file_path, &file_stats) == 0 && S_ISREG(file_stats.st_mode)) {
                total_size += file_stats.st_size;
            } else if (lstat(file_path, &file_stats) == 0 && S_ISDIR(file_stats.st_mode)) {
                if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                    continue;
                }

                analyze_directory(file_path);
            }
        }

        closedir(dir);

        printf("Total size of %s is %ld bytes\n", path, total_size);
    } else {
        printf("Error: Could not open directory %s\n", path);
    }
}