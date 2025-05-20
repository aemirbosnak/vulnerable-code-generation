//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to convert size from bytes to human-readable format
void format_size(long int size, char *buf) {
    char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int i = 0;
    while (size > 1024) {
        size /= 1024;
        i++;
    }
    sprintf(buf, "%ld %s", size, units[i]);
}

// Function to iterate recursively through directories and analyze disk space usage
long int analyze_disk_usage(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    long int total_size = 0;
    char full_path[512];
    char size_buf[16];
    dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Cannot open directory %s\n", path);
        return 0;
    }
    while ((entry = readdir(dir)) != NULL) {
        // Ignore . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        // Construct full path of file or directory
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (lstat(full_path, &file_info) != 0) {
            printf("Error: Cannot get information for %s\n", full_path);
            continue;
        }
        if (S_ISDIR(file_info.st_mode)) {
            // Recursive call for subdirectories
            total_size += analyze_disk_usage(full_path);
        } else {
            // Add size of file
            total_size += file_info.st_size;
        }
        // Print file or directory information
        format_size(file_info.st_size, size_buf);
        printf("%s\t%s\n", size_buf, full_path);
    }
    closedir(dir);
    return total_size;
}

int main(int argc, char *argv[]) {
    char path[512];
    long int total_size;
    if (argc < 2) {
        // Default path is current directory
        snprintf(path, sizeof(path), ".");
    } else {
        snprintf(path, sizeof(path), "%s", argv[1]);
    }
    printf("Disk usage information for %s:\n", path);
    total_size = analyze_disk_usage(path);
    char size_buf[16];
    format_size(total_size, size_buf);
    printf("Total disk usage: %s\n", size_buf);
    return 0;
}