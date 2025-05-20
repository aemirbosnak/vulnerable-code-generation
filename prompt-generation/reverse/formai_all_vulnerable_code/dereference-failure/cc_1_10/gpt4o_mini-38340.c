//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BLOCK_SIZE 1024

void analyze_directory(const char *path, long long *total_size, int level);
void display_size(long long size);
void print_indent(int level);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct stat path_stat;
    if (stat(argv[1], &path_stat) != 0 || !S_ISDIR(path_stat.st_mode)) {
        fprintf(stderr, "Invalid directory: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    long long total_size = 0;
    printf("Analyzing directory: %s\n\n", argv[1]);
    analyze_directory(argv[1], &total_size, 0);

    printf("\nTotal disk usage of '%s': ", argv[1]);
    display_size(total_size);
    printf("\n");
    
    return EXIT_SUCCESS;
}

void analyze_directory(const char *path, long long *total_size, int level) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        struct stat entry_stat;
        if (stat(full_path, &entry_stat) != 0) {
            perror(full_path);
            continue;
        }

        print_indent(level);
        printf("%s -> ", entry->d_name);
        if (S_ISDIR(entry_stat.st_mode)) {
            printf("Directory\n");
            long long dir_size = 0;
            analyze_directory(full_path, &dir_size, level + 1);
            *total_size += dir_size;
            printf("Size of '%s': ", full_path);
            display_size(dir_size);
            printf("\n");
        } else {
            printf("File\n");
            *total_size += entry_stat.st_size;
            printf("Size of '%s': ", full_path);
            display_size(entry_stat.st_size);
            printf("\n");
        }
    }
    
    closedir(dir);
}

void display_size(long long size) {
    if (size < BLOCK_SIZE) {
        printf("%lld B", size);
    } else if (size < BLOCK_SIZE * BLOCK_SIZE) {
        printf("%.2f KB", (double)size / BLOCK_SIZE);
    } else if (size < BLOCK_SIZE * BLOCK_SIZE * BLOCK_SIZE) {
        printf("%.2f MB", (double)size / (BLOCK_SIZE * BLOCK_SIZE));
    } else {
        printf("%.2f GB", (double)size / (BLOCK_SIZE * BLOCK_SIZE * BLOCK_SIZE));
    }
}

void print_indent(int level) {
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
}