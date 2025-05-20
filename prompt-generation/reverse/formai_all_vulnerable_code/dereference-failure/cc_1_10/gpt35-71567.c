//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

long long calculate_directory_size(char *path);

int main() {
    long long size = calculate_directory_size(".");
    printf("Size of current directory: %lld bytes\n", size);
    return 0;
}

long long calculate_directory_size(char *path) {
    struct dirent *dir;
    DIR *d = opendir(path);
    if (d == NULL) {
        fprintf(stderr, "Cannot open directory\n");
        exit(EXIT_FAILURE);
    }

    long long total_size = 0;
    char new_path[1024];
    while ((dir = readdir(d)) != NULL) {
        // Ignore the "." and ".." folders
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
            continue;
        }

        // Create the new path by concatenating the directory and the file/folder name
        snprintf(new_path, sizeof(new_path), "%s/%s", path, dir->d_name);

        // Get the file/folder information
        struct stat st;
        if (stat(new_path, &st) == -1) {
            continue;
        }

        // If it's a file, add its size to the total
        if (S_ISREG(st.st_mode)) {
            total_size += st.st_size;
        }
        // If it's a directory, recursively calculate its size and add it to the total
        else if (S_ISDIR(st.st_mode)) {
            total_size += calculate_directory_size(new_path);
        }
    }

    closedir(d);
    return total_size;
}