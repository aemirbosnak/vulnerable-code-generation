//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

// Function prototype
void analyze_directory(const char *directory_path, long long *total_size, int level);
void print_size(long long size);
void print_spaces(int level);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    long long total_size = 0;
    analyze_directory(argv[1], &total_size, 0);
    
    printf("Total used space in '%s': ", argv[1]);
    print_size(total_size);
    printf("\n");

    return EXIT_SUCCESS;
}

void analyze_directory(const char *directory_path, long long *total_size, int level) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if (!(dir = opendir(directory_path))) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the entries for '.' and '..'
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", directory_path, entry->d_name);

        if (stat(full_path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        // If it's a directory, analyze recursively
        if (S_ISDIR(file_stat.st_mode)) {
            long long dir_size = 0;
            printf("%*sDirectory: %s\n", level * 4, "", full_path);
            analyze_directory(full_path, &dir_size, level + 1);
            *total_size += dir_size;
            printf("%*sTotal size of '%s': ", (level + 1) * 4, "", full_path);
            print_size(dir_size);
            printf("\n");
        } else {
            // Add to total size
            *total_size += file_stat.st_size;
            printf("%*sFile: %s - ", level * 4, "", full_path);
            print_size(file_stat.st_size);
            printf("\n");
        }
    }

    closedir(dir);
}

void print_size(long long size) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit_index = 0;

    double size_double = (double)size;
    while (size_double >= 1024 && unit_index < 4) {
        size_double /= 1024;
        unit_index++;
    }

    printf("%.2f %s", size_double, units[unit_index]);
}

void print_spaces(int level) {
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
}