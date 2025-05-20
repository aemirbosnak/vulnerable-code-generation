//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_NAME_LENGTH 256

void print_welcome_message() {
    printf("====================================\n");
    printf("     🌌 Disk Space Analyzer 🌌\n");
    printf("====================================\n");
    printf("Discover the wonders of your disk space!\n");
}

long get_directory_size(const char *dir_path) {
    struct stat st;
    long total_size = 0;
    DIR *dir = opendir(dir_path);
    struct dirent *entry;

    if (!dir) {
        perror("Unable to open directory");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        char path[MAX_PATH_LENGTH];
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
            if (stat(path, &st) == 0) {
                if (S_ISDIR(st.st_mode)) {
                    total_size += get_directory_size(path); // Recursion for subdirectories
                } else {
                    total_size += st.st_size; // Accumulate file size
                }
            }
        }
    }
    closedir(dir);
    return total_size;
}

void print_size(long size) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit_index = 0;
    double display_size = size;

    while (display_size >= 1024 && unit_index < 4) {
        display_size /= 1024;
        unit_index++;
    }
    
    printf("Total Size: %.2f %s\n", display_size, units[unit_index]);
}

void analyze_disk_space(const char *path) {
    printf("\n📁 Analyzing: %s\n", path);
    long total_size = get_directory_size(path);
    if (total_size >= 0) {
        printf("🚀 Analyzing complete - Here's what we found:\n");
        print_size(total_size);
    } else {
        printf("🔍 Failed to analyze the directory.\n");
    }
}

int main(int argc, char *argv[]) {
    print_welcome_message();

    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyze_disk_space(argv[1]);

    printf("\n====================================\n");
    printf("     🌻 Thank you for using Disk Space Analyzer 🌻\n");
    printf("====================================\n");
    
    return EXIT_SUCCESS;
}