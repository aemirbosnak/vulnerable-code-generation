//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: accurate
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

long long total_size = 0;

void analyze_directory(const char *path, int depth) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Could not open directory %s\n", path);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            char *new_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
            sprintf(new_path, "%s/%s", path, entry->d_name);
            analyze_directory(new_path, depth + 1);
            free(new_path);
        } else {
            struct stat stat_buf;
            char *file_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
            sprintf(file_path, "%s/%s", path, entry->d_name);
            if (stat(file_path, &stat_buf) == 0) {
                total_size += stat_buf.st_size;
            } else {
                printf("Error: Could not get file stats for %s\n", file_path);
            }
            free(file_path);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1], 0);

    printf("Total size: %lld bytes\n", total_size);

    return 0;
}