//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 1024

void analyze_directory(const char *path, unsigned long *total_size, unsigned long *file_count, unsigned long *dir_count) {
    struct stat statbuf;
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char fullpath[MAX_PATH];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        if (stat(fullpath, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            (*dir_count)++;
            analyze_directory(fullpath, total_size, file_count, dir_count); // Recursive call for nested directories
        } else if (S_ISREG(statbuf.st_mode)) {
            (*file_count)++;
            *total_size += statbuf.st_size; // Accumulate size of files
        }
    }
    closedir(dir);
}

void print_analysis(const char *path, unsigned long total_size, unsigned long file_count, unsigned long dir_count) {
    printf("Directory: %s\n", path);
    printf("Total Size: %lu bytes\n", total_size);
    printf("Number of Files: %lu\n", file_count);
    printf("Number of Directories: %lu\n", dir_count);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned long total_size = 0;
    unsigned long file_count = 0;
    unsigned long dir_count = 0;

    // Start analyzing the directory
    analyze_directory(argv[1], &total_size, &file_count, &dir_count);

    // Print the summary of the analysis
    print_analysis(argv[1], total_size, file_count, dir_count);

    return EXIT_SUCCESS;
}