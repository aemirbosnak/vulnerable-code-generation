//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

// Function to recursively calculate the total size of files in the directory
long long calculate_directory_size(const char *directory, int *file_count) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    long long total_size = 0;

    if ((dir = opendir(directory)) == NULL) {
        perror("Unable to open directory");
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", directory, entry->d_name);
        
        if (stat(full_path, &file_info) == -1) {
            perror("Unable to get file information");
            continue;
        }

        // Check if it is a regular file
        if (S_ISREG(file_info.st_mode)) {
            total_size += file_info.st_size;
            (*file_count)++;
        } 
        // Check if it is a directory
        else if (S_ISDIR(file_info.st_mode)) {
            int sub_file_count = 0;
            long long subdir_size = calculate_directory_size(full_path, &sub_file_count);
            total_size += subdir_size;
            (*file_count) += sub_file_count;

            printf("Directory: %s, Size: %lld bytes, Files: %d\n", full_path, subdir_size, sub_file_count);
        }
    }

    closedir(dir);
    return total_size;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *target_directory = argv[1];
    int total_file_count = 0;
    
    long long total_size = calculate_directory_size(target_directory, &total_file_count);
    
    printf("Total size of '%s': %lld bytes across %d files\n", target_directory, total_size, total_file_count);

    return EXIT_SUCCESS;
}