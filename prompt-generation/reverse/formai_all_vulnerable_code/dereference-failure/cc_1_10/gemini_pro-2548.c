//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to get the size of a file
long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    } else {
        return -1;
    }
}

// Function to get the total size of a directory
long get_dir_size(const char *dirname) {
    DIR *dir;
    struct dirent *entry;
    long size = 0;

    dir = opendir(dirname);
    if (dir == NULL) {
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *path = malloc(strlen(dirname) + strlen(entry->d_name) + 2);
        sprintf(path, "%s/%s", dirname, entry->d_name);

        struct stat st;
        if (stat(path, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                size += get_dir_size(path);
            } else {
                size += st.st_size;
            }
        }

        free(path);
    }

    closedir(dir);

    return size;
}

// Function to print the size of a file or directory
void print_size(const char *path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
            long size = get_dir_size(path);
            if (size >= 0) {
                printf("%s: %ld bytes\n", path, size);
            } else {
                printf("%s: Error getting size\n", path);
            }
        } else {
            long size = get_file_size(path);
            if (size >= 0) {
                printf("%s: %ld bytes\n", path, size);
            } else {
                printf("%s: Error getting size\n", path);
            }
        }
    } else {
        printf("%s: Error getting size\n", path);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    // Print the size of the specified path
    print_size(argv[1]);

    return 0;
}