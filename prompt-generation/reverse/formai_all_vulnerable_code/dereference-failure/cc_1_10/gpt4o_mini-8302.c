//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

void analyze_directory(const char *path, long *total_size);
void print_size(long size);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    long total_size = 0;
    analyze_directory(argv[1], &total_size);
    
    printf("Total Disk Space Used in '%s': ", argv[1]);
    print_size(total_size);
    
    return EXIT_SUCCESS;
}

void analyze_directory(const char *path, long *total_size) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dp = opendir(path);
    
    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }
    
    while ((entry = readdir(dp)) != NULL) {
        // Skip the special entries '.' and '..'
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        if (stat(full_path, &file_stat) == 0) {
            if (S_ISDIR(file_stat.st_mode)) {
                analyze_directory(full_path, total_size); // Recursive call for directories
            }
            *total_size += file_stat.st_size; // Accumulate the size
        } else {
            perror("Failed to get file status");
        }
    }

    closedir(dp);
}

void print_size(long size) {
    const char *units[] = { "B", "KB", "MB", "GB", "TB" };
    int unit_index = 0;

    double size_in_units = size;
    while (size_in_units >= 1024 && unit_index < 4) {
        size_in_units /= 1024;
        unit_index++;
    }
    
    printf("%.2f %s\n", size_in_units, units[unit_index]);
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <directory_path>\n", program_name);
    fprintf(stderr, "Analyzes disk space used by all files and subdirectories.\n");
}