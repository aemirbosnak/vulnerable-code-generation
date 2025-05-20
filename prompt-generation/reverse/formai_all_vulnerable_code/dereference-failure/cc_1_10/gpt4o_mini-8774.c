//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void analyze_directory(const char *path, long long *total_size, long long *directory_count, long long *file_count);
void print_summary(const char *path, long long total_size, long long directory_count, long long file_count);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    long long total_size = 0;
    long long directory_count = 0;
    long long file_count = 0;

    analyze_directory(argv[1], &total_size, &directory_count, &file_count);
    print_summary(argv[1], total_size, directory_count, file_count);

    return 0;
}

void analyze_directory(const char *path, long long *total_size, long long *directory_count, long long *file_count) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char full_path[MAX_PATH];

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // skip '.' and '..'
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (lstat(full_path, &statbuf) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            (*directory_count)++;
            analyze_directory(full_path, total_size, directory_count, file_count);
        } else {
            (*file_count)++;
            *total_size += statbuf.st_size;
        }
    }

    closedir(dir);
}

void print_summary(const char *path, long long total_size, long long directory_count, long long file_count) {
    printf("Summary for directory: %s\n", path);
    printf("Total Size: %lld bytes\n", total_size);
    printf("Number of files: %lld\n", file_count);
    printf("Number of directories: %lld\n", directory_count);
}