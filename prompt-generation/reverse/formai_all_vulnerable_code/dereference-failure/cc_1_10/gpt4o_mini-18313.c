//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

void analyze_directory(const char *path, long *total_size, int *file_count) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current directory and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        if (stat(full_path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISREG(file_stat.st_mode)) {
            *total_size += file_stat.st_size;  // Accumulate file sizes
            (*file_count)++;                    // Increment file count
        } else if (S_ISDIR(file_stat.st_mode)) {
            // Recursively analyze subdirectory
            analyze_directory(full_path, total_size, file_count);
        }
    }
    closedir(dir);
}

void print_size_distribution(long total_size, int file_count) {
    printf("\n=== Size Distribution ===\n");
    printf("Total Size: %ld bytes\n", total_size);
    printf("Total Files: %d\n", file_count);
    printf("Average File Size: %.2f bytes\n", file_count > 0 ? (double)total_size / file_count : 0.0);

    // Example size brackets: files <1KB, 1KB to 1MB, 1MB to 10MB, >10MB
    printf("\n=== Size Bracket Distribution ===\n");
    printf("Size < 1 KB: %d\n", (total_size < 1024) ? 1 : 0);
    printf("Size 1 KB - 1 MB: %d\n", (total_size >= 1024 && total_size < 1024*1024) ? 1 : 0);
    printf("Size 1 MB - 10 MB: %d\n", (total_size >= 1024*1024 && total_size < 10*1024*1024) ? 1 : 0);
    printf("Size > 10 MB: %d\n", (total_size >= 10*1024*1024) ? 1 : 0);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *path = argv[1];
    long total_size = 0;
    int file_count = 0;

    analyze_directory(path, &total_size, &file_count);
    print_size_distribution(total_size, file_count);

    return EXIT_SUCCESS;
}