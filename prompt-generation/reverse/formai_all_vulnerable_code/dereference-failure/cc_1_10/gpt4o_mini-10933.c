//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 1024

long int get_directory_size(const char *dir_path);
void print_disk_usage(const char *base_path, int indent);
void handle_error(const char *message);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct stat path_stat;
    if (stat(argv[1], &path_stat) != 0) {
        handle_error("Failed to get directory status");
    }

    if (!S_ISDIR(path_stat.st_mode)) {
        fprintf(stderr, "Error: Provided path is not a directory\n");
        return EXIT_FAILURE;
    }

    printf("Analyzing disk usage for directory: %s\n", argv[1]);
    print_disk_usage(argv[1], 0);

    return EXIT_SUCCESS;
}

void print_disk_usage(const char *base_path, int indent) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(base_path))) {
        handle_error("Failed to open directory");
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directory entries
        }

        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", base_path, entry->d_name);

        struct stat entry_stat;
        if (stat(full_path, &entry_stat) != 0) {
            handle_error("Failed to get entry status");
        }

        if (S_ISDIR(entry_stat.st_mode)) {
            long int dir_size = get_directory_size(full_path);
            printf("%*s[DIR] %s (Size: %ld bytes)\n", indent, "", entry->d_name, dir_size);
            print_disk_usage(full_path, indent + 4); // Recursively print subdirectory
        } else {
            printf("%*s[FILE] %s (Size: %ld bytes)\n", indent, "", entry->d_name, entry_stat.st_size);
        }
    }

    closedir(dir);
}

long int get_directory_size(const char *dir_path) {
    long int total_size = 0;
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(dir_path))) {
        handle_error("Failed to open directory for size calculation");
        return total_size;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directory entries
        }

        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        struct stat entry_stat;
        if (stat(full_path, &entry_stat) != 0) {
            handle_error("Failed to get entry status for size calculation");
            continue;
        }

        if (S_ISDIR(entry_stat.st_mode)) {
            total_size += get_directory_size(full_path); // Add subdirectory size recursively
        } else {
            total_size += entry_stat.st_size; // Add file size
        }
    }

    closedir(dir);
    return total_size;
}

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}