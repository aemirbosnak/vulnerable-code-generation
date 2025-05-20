//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LEN 4096
#define MAX_FILENAME_LEN 256

int is_directory(char* path) {
    struct stat buf;
    if (stat(path, &buf) == -1) {
        fprintf(stderr, "Error: Failed to get file stats for %s\n", path);
        exit(1);
    }
    return S_ISDIR(buf.st_mode);
}

long long int get_directory_size(char* path) {
    long long int size = 0;
    struct dirent *entry;
    DIR *dir = opendir(path);
    if (!dir) {
        fprintf(stderr, "Error: Failed to open directory %s\n", path);
        exit(1);
    }
    while ((entry = readdir(dir))) {
        if (entry->d_name[0] == '.') {
            continue;
        }
        char new_path[MAX_PATH_LEN];
        snprintf(new_path, MAX_PATH_LEN, "%s/%s", path, entry->d_name);
        if (is_directory(new_path)) {
            size += get_directory_size(new_path);
        } else {
            struct stat buf;
            if (stat(new_path, &buf) == -1) {
                fprintf(stderr, "Error: Failed to get file stats for %s\n", new_path);
                exit(1);
            }
            size += buf.st_size;
        }
    }
    closedir(dir);
    return size;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s directory_name\n", argv[0]);
        exit(1);
    }
    char path[MAX_PATH_LEN];
    snprintf(path, MAX_PATH_LEN, "%s", argv[1]);
    long long int total_size = get_directory_size(path);
    printf("Total size of directory %s: %lld bytes\n", path, total_size);
    return 0;
}