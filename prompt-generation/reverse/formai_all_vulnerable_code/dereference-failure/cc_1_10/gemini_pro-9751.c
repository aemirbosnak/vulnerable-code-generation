//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

// Function to get the file size in bytes
long long get_file_size(const char *path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        return st.st_size;
    } else {
        return -1;
    }
}

// Function to iterate over the files and directories in a directory and calculate the total size
long long dir_size(const char *path) {
    long long total_size = 0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return -1;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (entry->d_type == DT_DIR) {
            total_size += dir_size(full_path);
        } else {
            total_size += get_file_size(full_path);
        }
    }
    closedir(dir);
    return total_size;
}

int main() {
    // Get the current working directory
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        return EXIT_FAILURE;
    }

    // Calculate the total size of the current working directory
    long long total_size = dir_size(cwd);
    if (total_size == -1) {
        return EXIT_FAILURE;
    }

    // Print the total size in bytes and human-readable format
    printf("Total size: %lld bytes\n", total_size);
    double size_mb = (double)total_size / (1024 * 1024);
    printf("Total size: %.2f MB\n", size_mb);
    double size_gb = size_mb / 1024;
    printf("Total size: %.2f GB\n", size_gb);

    return EXIT_SUCCESS;
}