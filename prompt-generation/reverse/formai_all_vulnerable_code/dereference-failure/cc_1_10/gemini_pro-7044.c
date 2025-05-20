//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 4096

// Global variables
long long total_size = 0;
char longest_file[256] = "";
long long longest_file_size = 0;

// Function to check if a file is a directory
int is_directory(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == 0) {
        return S_ISDIR(statbuf.st_mode);
    } else {
        return 0;
    }
}

// Function to get the size of a file or directory
long long get_file_size(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == 0) {
        if (S_ISDIR(statbuf.st_mode)) {
            // If it's a directory, recursively get the size of all files in it
            long long total_size = 0;
            DIR *dir = opendir(path);
            struct dirent *entry;
            while ((entry = readdir(dir)) != NULL) {
                if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                    continue;
                }
                char new_path[256];
                sprintf(new_path, "%s/%s", path, entry->d_name);
                total_size += get_file_size(new_path);
            }
            closedir(dir);
            return total_size;
        } else {
            // If it's a file, return its size
            return statbuf.st_size;
        }
    } else {
        // If stat() failed, return -1
        return -1;
    }
}

// Function to get the longest file name
void get_longest_file(const char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char new_path[256];
        sprintf(new_path, "%s/%s", path, entry->d_name);
        if (is_directory(new_path)) {
            get_longest_file(new_path);
        } else {
            long long file_size = get_file_size(new_path);
            if (file_size > longest_file_size) {
                longest_file_size = file_size;
                strcpy(longest_file, new_path);
            }
        }
    }
    closedir(dir);
}

// Function to print the results
void print_results() {
    printf("Total size: %lld bytes\n", total_size);
    printf("Longest file: %s (size: %lld bytes)\n", longest_file, longest_file_size);
}

int main() {
    // Get the starting path from the user
    char path[256];
    printf("Enter the starting path: ");
    scanf("%s", path);

    // Get the total size of the files and directories in the path
    total_size = get_file_size(path);

    // Get the longest file name in the path
    get_longest_file(path);

    // Print the results
    print_results();

    return 0;
}