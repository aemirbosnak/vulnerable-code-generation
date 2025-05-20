//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define PATH_MAX 4096
#define FILE_NAME_MAX 256
#define BUFFER_SIZE 1024

void analyze_directory(const char *dir_path, long long *total_size, long long *file_count) {
    struct dirent *entry;
    struct stat file_stat;
    
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char path[PATH_MAX];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;  // Skip the special entries
        }

        if (stat(path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            analyze_directory(path, total_size, file_count);  // Recurse into subdirectory
        } else {
            *total_size += file_stat.st_size;  // Size accumulation
            (*file_count)++;  // Count files
        }
    }
    closedir(dir);
}

void print_analysis(const char *dir_path, long long total_size, long long file_count) {
    printf("******** Disk Space Analysis ********\n");
    printf("Directory: %s\n", dir_path);
    printf("Total files: %lld\n", file_count);
    printf("Total size: %lld bytes\n", total_size);
    printf("*************************************\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dir_path = argv[1];
    long long total_size = 0;
    long long file_count = 0;

    analyze_directory(dir_path, &total_size, &file_count);
    print_analysis(dir_path, total_size, file_count);

    return EXIT_SUCCESS;
}