//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

void print_usage() {
    printf("Usage: disk_space_analyzer <directory_path>\n");
}

long get_directory_size(const char *path) {
    long total_size = 0;
    struct dirent *entry;
    struct stat statbuf;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("Failed to open directory");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the '.' and '..' entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        if (stat(full_path, &statbuf) == -1) {
            perror("Failed to get file stats");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            long dir_size = get_directory_size(full_path);
            if (dir_size != -1) {
                total_size += dir_size;
            }
        } else {
            total_size += statbuf.st_size;
        }
    }

    closedir(dir);
    return total_size;
}

void analyze_disk_space(const char *path) {
    long total_size = get_directory_size(path);
    
    if (total_size != -1) {
        printf("Total disk usage for directory '%s': %ld bytes\n", path, total_size);
    } else {
        printf("Error calculating size for directory '%s'.\n", path);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *directory_path = argv[1];
    analyze_disk_space(directory_path);
    
    return EXIT_SUCCESS;
}