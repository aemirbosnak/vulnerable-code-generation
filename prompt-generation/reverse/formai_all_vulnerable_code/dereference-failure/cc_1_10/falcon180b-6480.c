//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LEN 1024

// Function to print the disk usage statistics
void print_usage_stats(char *path, unsigned long long total_size) {
    printf("Disk usage statistics for %s:\n", path);
    printf("Total size: %llu bytes\n", total_size);
}

// Function to traverse the directory and calculate the total size
unsigned long long traverse_dir(char *path, unsigned long long *total_size) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Could not open directory %s\n", path);
        return 0;
    }

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        char full_path[MAX_PATH_LEN];
        sprintf(full_path, "%s/%s", path, ent->d_name);

        struct stat st;
        stat(full_path, &st);

        if (S_ISDIR(st.st_mode)) {
            unsigned long long dir_size = 0;
            traverse_dir(full_path, &dir_size);
            *total_size += dir_size;
        } else {
            *total_size += st.st_size;
        }
    }

    closedir(dir);
    return *total_size;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s directory_path\n", argv[0]);
        return 1;
    }

    char path[MAX_PATH_LEN];
    strcpy(path, argv[1]);

    unsigned long long total_size = 0;
    traverse_dir(path, &total_size);

    print_usage_stats(path, total_size);

    return 0;
}