//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

void analyze_directory(const char *path, long long *total_size, int indent);
void print_size(long long size);
void display_usage_menu();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage_menu();
        return EXIT_FAILURE;
    }

    char *path = argv[1];
    struct stat path_stat;

    if (stat(path, &path_stat) != 0) {
        perror("Error reading the directory");
        return EXIT_FAILURE;
    }

    if (!S_ISDIR(path_stat.st_mode)) {
        fprintf(stderr, "The provided path is not a directory.\n");
        return EXIT_FAILURE;
    }

    long long total_size = 0;
    printf("Analyzing directory: %s\n", path);
    analyze_directory(path, &total_size, 0);
    printf("\nTotal size used: ");
    print_size(total_size);
    printf("\n");

    return EXIT_SUCCESS;
}

void analyze_directory(const char *path, long long *total_size, int indent) {
    DIR *dir;
    struct dirent *entry;
    struct stat entry_stat;
    char sub_path[MAX_PATH];

    if ((dir = opendir(path)) == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip the special entries
        }

        snprintf(sub_path, sizeof(sub_path), "%s/%s", path, entry->d_name);

        if (stat(sub_path, &entry_stat) == 0) {
            // If it's a directory, recurse into it
            if (S_ISDIR(entry_stat.st_mode)) {
                printf("%*s[%s] (directory)\n", indent, "", entry->d_name);
                long long dir_size = 0;
                analyze_directory(sub_path, &dir_size, indent + 2);
                *total_size += dir_size;
                printf("%*sTotal size of [%s]: ", indent + 2, "", entry->d_name);
                print_size(dir_size);
                printf("\n");
            } else {
                // If it's a file, print its size
                printf("%*s%s (file) - ", indent, "", entry->d_name);
                long long file_size = entry_stat.st_size;
                *total_size += file_size;
                print_size(file_size);
                printf("\n");
            }
        } else {
            perror("Error getting file status");
        }
    }

    closedir(dir);
}

void print_size(long long size) {
    const char *units[] = { "B", "KB", "MB", "GB", "TB" };
    int unit_index = 0;

    while (size > 1024 && unit_index < 4) {
        size /= 1024;
        unit_index++;
    }

    printf("%lld %s", size, units[unit_index]);
}

void display_usage_menu() {
    printf("Usage: ./disk_space_analyzer <directory_path>\n");
    printf("Provide a valid path to a directory to analyze disk space usage.\n");
}