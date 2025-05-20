//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256

// Function to get the total disk space
long long get_total_disk_space(const char* path) {
    struct statvfs buf;
    if (statvfs(path, &buf) == -1) {
        printf("Error getting disk space for %s\n", path);
        exit(1);
    }
    return buf.f_blocks * buf.f_frsize;
}

// Function to get the total number of files and directories
int get_total_files_and_dirs(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory %s\n", path);
        exit(1);
    }
    int count = 0;
    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            count++;
        }
    }
    closedir(dir);
    return count;
}

// Function to print the disk space usage for a given directory
void print_disk_space_usage(const char* path) {
    long long total_space = get_total_disk_space(path);
    int total_files_and_dirs = get_total_files_and_dirs(path);
    printf("Disk space usage for %s:\n", path);
    printf("Total space: %lld bytes\n", total_space);
    printf("Total files and directories: %d\n", total_files_and_dirs);
}

// Function to print the disk space usage for all subdirectories
void print_disk_space_usage_recursive(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory %s\n", path);
        exit(1);
    }
    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            char subdir_path[MAX_FILE_NAME_LENGTH];
            strcpy(subdir_path, path);
            strcat(subdir_path, "/");
            strcat(subdir_path, entry->d_name);
            print_disk_space_usage_recursive(subdir_path);
        }
    }
    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }
    char path[MAX_FILE_NAME_LENGTH];
    strcpy(path, argv[1]);
    if (path[strlen(path) - 1]!= '/') {
        strcat(path, "/");
    }
    print_disk_space_usage(path);
    print_disk_space_usage_recursive(path);
    return 0;
}