//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Function to get the size of a file in bytes
long long get_file_size(const char* file_name) {
    struct stat stat_buf;
    if (stat(file_name, &stat_buf) == 0) {
        return stat_buf.st_size;
    }
    return -1;
}

// Function to get the size of a directory in bytes
long long get_directory_size(const char* dir_name) {
    long long total_size = 0;
    DIR* dir = opendir(dir_name);
    if (dir == NULL) {
        return -1;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char* path = malloc(strlen(dir_name) + strlen(entry->d_name) + 2);
        strcpy(path, dir_name);
        strcat(path, "/");
        strcat(path, entry->d_name);
        struct stat stat_buf;
        if (stat(path, &stat_buf) == 0) {
            if (S_ISDIR(stat_buf.st_mode)) {
                total_size += get_directory_size(path);
            } else {
                total_size += stat_buf.st_size;
            }
        }
        free(path);
    }
    closedir(dir);
    return total_size;
}

// Function to print the size of a file or directory in a human-readable format
void print_size(long long size) {
    if (size < 1024) {
        printf("%lld bytes\n", size);
    } else if (size < 1024 * 1024) {
        printf("%.2f KB\n", (double)size / 1024);
    } else if (size < 1024 * 1024 * 1024) {
        printf("%.2f MB\n", (double)size / (1024 * 1024));
    } else {
        printf("%.2f GB\n", (double)size / (1024 * 1024 * 1024));
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    char* path = argv[1];

    struct stat stat_buf;
    if (stat(path, &stat_buf) != 0) {
        fprintf(stderr, "Error: could not stat '%s'\n", path);
        return 1;
    }

    if (S_ISDIR(stat_buf.st_mode)) {
        long long size = get_directory_size(path);
        if (size == -1) {
            fprintf(stderr, "Error: could not get size of '%s'\n", path);
            return 1;
        }
        printf("Size of '%s': ", path);
        print_size(size);
    } else {
        long long size = get_file_size(path);
        if (size == -1) {
            fprintf(stderr, "Error: could not get size of '%s'\n", path);
            return 1;
        }
        printf("Size of '%s': ", path);
        print_size(size);
    }

    return 0;
}