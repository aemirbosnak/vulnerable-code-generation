//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void analyze_directory(const char *dir_path, long *total_size, int *file_count) {
    struct dirent *entry;
    struct stat statbuf;
    DIR *directory = opendir(dir_path);

    if (directory == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip the current and parent directory entries
        }

        if (stat(full_path, &statbuf) == -1) {
            perror("Unable to get file stats");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // It's a directory; recursively analyze its contents
            analyze_directory(full_path, total_size, file_count);
        } else {
            // It's a file; count it and add its size
            *total_size += statbuf.st_size;
            (*file_count)++;
        }
    }

    closedir(directory);
}

void display_results(long total_size, int file_count) {
    printf("Total Files Analyzed: %d\n", file_count);
    printf("Total Disk Space Used: %.2f MB\n", total_size / (1024.0 * 1024.0));
    printf("Total Disk Space Used: %.2f GB\n", total_size / (1024.0 * 1024.0 * 1024.0));
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *input_path = argv[1];
    long total_size = 0;
    int file_count = 0;

    printf("Analyzing directory: %s\n", input_path);
    analyze_directory(input_path, &total_size, &file_count);
    
    display_results(total_size, file_count);

    return EXIT_SUCCESS;
}