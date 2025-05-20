//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

void analyze_directory(const char *path, long long *total_size) {
    struct stat file_stat;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries '.' and '..'
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char full_path[512];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &file_stat) == 0) {
            if (S_ISDIR(file_stat.st_mode)) {
                // Recursively analyze the directory
                analyze_directory(full_path, total_size);
            } else {
                // Accumulate the file size
                *total_size += file_stat.st_size;
            }
        } else {
            perror("Could not get file status");
        }
    }

    closedir(dir);
}

void print_size(long long size) {
    const char *sizes[] = {"B", "KB", "MB", "GB", "TB"};
    int i = 0;
    double formatted_size = size;

    while (formatted_size >= 1024 && i < 4) {
        formatted_size /= 1024;
        i++;
    }

    printf("Total size used: %.2f %s\n", formatted_size, sizes[i]);
}

int main(int argc, char **argv) {
    long long total_size = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1], &total_size);
    print_size(total_size);

    return 0;
}