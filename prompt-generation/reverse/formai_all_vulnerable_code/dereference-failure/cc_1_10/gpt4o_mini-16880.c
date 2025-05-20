//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <dirent.h>
#include <string.h>

void display_usage(const char *path) {
    struct statvfs stat;

    // Get filesystem statistics
    if (statvfs(path, &stat) != 0) {
        perror("statvfs error");
        return;
    }

    unsigned long total = stat.f_blocks * stat.f_frsize;
    unsigned long free = stat.f_bfree * stat.f_frsize;
    unsigned long used = total - free;

    printf("Disk Usage for %s:\n", path);
    printf("Total: %lu bytes\n", total);
    printf("Used: %lu bytes\n", used);
    printf("Free: %lu bytes\n", free);
    printf("Used (%%): %.2f%%\n", (double)used / total * 100);
}

void analyze_directory(const char *dir_name) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("\nContents of directory: %s\n", dir_name);
    
    while ((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dp);
}

void traverse_directory(const char *dir_name) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }
    
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char path[1024];
                snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
                
                printf("Traversing directory: %s\n", path);
                analyze_directory(path);
                traverse_directory(path);
            }
        } else {
            printf("File: %s/%s\n", dir_name, entry->d_name);
        }
    }
    
    closedir(dp);
}

int main(int argc, char *argv[]) {
    // Check for command line argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *directory_path = argv[1];
    printf("Analyzing disk space...\n");
    
    // Display the disk usage of the specified directory
    display_usage(directory_path);

    // Traverse and analyze the contents of the specified directory
    traverse_directory(directory_path);
    
    printf("\nDisk space analysis completed.\n");
    return 0;
}