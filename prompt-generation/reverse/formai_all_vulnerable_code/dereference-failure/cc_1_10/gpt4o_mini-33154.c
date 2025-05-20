//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

// Function to print the size in a human-readable format
void print_size(long size) {
    const char *sizes[] = { "B", "KB", "MB", "GB", "TB" };
    int i;
    
    for (i = 0; size >= 1024 && i < 4; i++) {
        size /= 1024;
    }
    printf("%ld %s\n", size, sizes[i]);
}

// Function to calculate total size of files in a directory
long calculate_directory_size(const char *path) {
    struct stat st;
    long total_size = 0;
    
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') { // skip hidden files
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
            if (stat(full_path, &st) == 0) {
                if (S_ISDIR(st.st_mode)) {
                    long dir_size = calculate_directory_size(full_path);
                    if (dir_size >= 0) {
                        total_size += dir_size;
                    }
                } else {
                    total_size += st.st_size;
                }
            }
        }
    }
    closedir(dir);
    return total_size;
}

// Function to analyze disk usage
void analyze_disk_usage(const char *path) {
    long total_size = calculate_directory_size(path);
    if (total_size >= 0) {
        printf("Total size of '%s': ", path);
        print_size(total_size);
    } else {
        printf("Could not calculate size for '%s'\n", path);
    }
}

// Function to get user inputs safely
void get_user_input(char *buffer, size_t size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

// Main function
int main() {
    char path[1024];

    printf("Welcome to C Disk Space Analyzer!\n");
    printf("Please enter the directory path (e.g., /mnt/c): ");
    
    get_user_input(path, sizeof(path));
    
    analyze_disk_usage(path);
    
    printf("Thank you for using C Disk Space Analyzer!\n");
    return 0;
}