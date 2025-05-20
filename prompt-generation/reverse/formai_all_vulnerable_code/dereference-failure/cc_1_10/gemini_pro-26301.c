//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

// Function to calculate the size of a file or directory
long long get_size(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        perror("stat");
        return -1;
    }
    return statbuf.st_size;
}

// Function to recursively calculate the size of a directory
long long get_dir_size(const char *path) {
    DIR *dir;
    struct dirent *entry;
    long long size = 0;

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char *new_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
            strcpy(new_path, path);
            strcat(new_path, "/");
            strcat(new_path, entry->d_name);

            if (entry->d_type == DT_DIR) {
                size += get_dir_size(new_path);
            } else {
                size += get_size(new_path);
            }

            free(new_path);
        }
    }

    closedir(dir);
    return size;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long long size = get_dir_size(argv[1]);
    if (size == -1) {
        perror("get_dir_size");
        return EXIT_FAILURE;
    }

    printf("Size of %s: %lld bytes\n", argv[1], size);
    return EXIT_SUCCESS;
}