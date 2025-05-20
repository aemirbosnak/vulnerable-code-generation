//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 256

void analyze_directory(const char *dir_path);
void print_disk_usage(const char *path, struct stat *file_stat, long *total_size, long *total_files);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    struct stat dir_stat;
    if (stat(argv[1], &dir_stat) != 0) {
        perror("Error accessing the directory");
        return EXIT_FAILURE;
    }
    
    if (!S_ISDIR(dir_stat.st_mode)) {
        fprintf(stderr, "%s is not a directory.\n", argv[1]);
        return EXIT_FAILURE;
    }

    analyze_directory(argv[1]);
    return EXIT_SUCCESS;
}

void analyze_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    struct dirent *entry;
    long total_size = 0;
    long total_files = 0;

    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        struct stat file_stat;
        if (stat(full_path, &file_stat) == 0) {
            print_disk_usage(full_path, &file_stat, &total_size, &total_files);
        } else {
            perror("Could not retrieve file stats");
        }
    }

    closedir(dir);

    printf("Total Files: %ld\n", total_files);
    printf("Total Disk Space Used: %ld bytes\n", total_size);
}

void print_disk_usage(const char *path, struct stat *file_stat, long *total_size, long *total_files) {
    if (S_ISREG(file_stat->st_mode)) { // Regular file
        printf("File: %s | Size: %ld bytes\n", path, file_stat->st_size);
        *total_size += file_stat->st_size;
        (*total_files)++;
    } else if (S_ISDIR(file_stat->st_mode)) { // Directory
        printf("Directory: %s\n", path);
    }
}

void print_usage(const char *program_name) {
    printf("Usage: %s <directory_path>\n", program_name);
    printf("Analyze disk space usage in the specified directory.\n");
}