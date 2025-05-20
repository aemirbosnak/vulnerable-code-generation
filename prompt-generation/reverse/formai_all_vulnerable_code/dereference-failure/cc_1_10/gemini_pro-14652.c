//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>

#define MAX_PATH 1024

typedef struct {
    char *path;
    unsigned long long size;
} file_t;

// Compares two file_t structures by size
int compare_files(const void *a, const void *b) {
    file_t *fa = (file_t *)a;
    file_t *fb = (file_t *)b;

    return fb->size - fa->size;
}

// Recursively traverses a directory and calculates the size of each file
unsigned long long get_directory_size(char *path) {
    struct dirent *entry;
    DIR *dir = opendir(path);
    unsigned long long size = 0;

    if (dir == NULL) {
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        snprintf(full_path, MAX_PATH, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (lstat(full_path, &statbuf) != 0) {
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            size += get_directory_size(full_path);
        } else if (S_ISREG(statbuf.st_mode)) {
            size += statbuf.st_size;
        }
    }

    closedir(dir);

    return size;
}

// Analyzes the disk space usage of a directory and its subdirectories
void analyze_disk_space(char *path) {
    // Initialize an array of file_t structures
    file_t files[10000];
    int num_files = 0;

    // Recursively traverse the directory and calculate the size of each file
    unsigned long long total_size = get_directory_size(path);

    // Iterate over the files and store them in the array
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        snprintf(full_path, MAX_PATH, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (lstat(full_path, &statbuf) != 0) {
            continue;
        }

        if (S_ISREG(statbuf.st_mode)) {
            files[num_files].path = strdup(full_path);
            files[num_files].size = statbuf.st_size;
            num_files++;
        }
    }

    closedir(dir);

    // Sort the files by size
    qsort(files, num_files, sizeof(file_t), compare_files);

    // Print the results
    printf("Total size: %llu bytes\n", total_size);
    printf("Largest files:\n");
    for (int i = 0; i < 10; i++) {
        if (i >= num_files) {
            break;
        }
        printf("%s: %llu bytes\n", files[i].path, files[i].size);
    }

    // Free the allocated memory
    for (int i = 0; i < num_files; i++) {
        free(files[i].path);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_disk_space(argv[1]);

    return 0;
}