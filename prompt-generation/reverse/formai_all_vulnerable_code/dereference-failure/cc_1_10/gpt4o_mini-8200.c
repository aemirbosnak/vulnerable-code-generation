//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

void get_directory_size(const char *dir_path, long long *total_size);
void analyze_directory(const char *dir_path);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct stat stat_buf;
    if (stat(argv[1], &stat_buf) != 0) {
        perror("stat");
        return EXIT_FAILURE;
    }

    if (!S_ISDIR(stat_buf.st_mode)) {
        fprintf(stderr, "Error: %s is not a directory.\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("Analyzing disk space for directory: %s\n", argv[1]);
    analyze_directory(argv[1]);

    return EXIT_SUCCESS;
}

void analyze_directory(const char *dir_path) {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH];
    long long total_size = 0;

    if ((dir = opendir(dir_path)) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files and current/parent directories
        }

        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
        struct stat stat_buf;

        if (stat(path, &stat_buf) == 0) {
            if (S_ISDIR(stat_buf.st_mode)) {
                long long directory_size = 0;
                get_directory_size(path, &directory_size);
                printf("Directory: %s | Size: %lld bytes\n", path, directory_size);
                total_size += directory_size;
            } else {
                printf("File: %s | Size: %lld bytes\n", path, stat_buf.st_size);
                total_size += stat_buf.st_size;
            }
        } else {
            perror("stat");
        }
    }
    
    closedir(dir);
    printf("Total size in '%s': %lld bytes\n", dir_path, total_size);
}

void get_directory_size(const char *dir_path, long long *total_size) {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH];

    if ((dir = opendir(dir_path)) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files and current/parent directories
        }

        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
        struct stat stat_buf;

        if (stat(path, &stat_buf) == 0) {
            if (S_ISDIR(stat_buf.st_mode)) {
                long long directory_size = 0;
                get_directory_size(path, &directory_size);
                *total_size += directory_size;
            } else {
                *total_size += stat_buf.st_size;
            }
        } else {
            perror("stat");
        }
    }
    
    closedir(dir);
}