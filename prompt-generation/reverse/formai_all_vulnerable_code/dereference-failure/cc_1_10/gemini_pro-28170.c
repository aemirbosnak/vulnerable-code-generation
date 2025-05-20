//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>

// Function to get the file size
long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0)
        return st.st_size;
    return -1;
}

// Function to get the directory size
long get_directory_size(const char *dirname) {
    DIR *dir;
    struct dirent *entry;
    long size = 0;

    dir = opendir(dirname);
    if (dir == NULL)
        return -1;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

        if (entry->d_type == DT_DIR)
            size += get_directory_size(path);
        else
            size += get_file_size(path);
    }

    closedir(dir);

    return size;
}

// Function to print the directory tree
void print_directory_tree(const char *dirname, int depth) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dirname);
    if (dir == NULL)
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

        if (entry->d_type == DT_DIR) {
            printf("%*s%s\n", depth, "", path);
            print_directory_tree(path, depth + 1);
        } else {
            long size = get_file_size(path);
            printf("%*s%s (%ld bytes)\n", depth, "", path, size);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long size = get_directory_size(argv[1]);
    if (size == -1) {
        printf("Error: Could not get the size of the directory.\n");
        return EXIT_FAILURE;
    }

    printf("Directory %s size: %ld bytes\n", argv[1], size);
    print_directory_tree(argv[1], 0);

    return EXIT_SUCCESS;
}