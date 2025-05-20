//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024

void analyze_directory(const char *path, long long *total_size);
void print_usage_report(const char *directory, long long size);
void filter_and_report(const char *directory, long long size);

int main() {
    // Start of our analysis from a base directory
    const char *base_directory = ".";
    long long total_size = 0;

    printf("Turing's Disk Space Analyzer\n");
    printf("Calculating sizes...\n");

    // Analyze the base directory
    analyze_directory(base_directory, &total_size);
    
    printf("\nTotal space used in '%s': %lld bytes\n", base_directory, total_size);
    
    return 0;
}

void analyze_directory(const char *path, long long *total_size) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char full_path[MAX_PATH];

    // Attempt to open the directory
    if ((dir = opendir(path)) != NULL) {
        // Read each entry in the directory
        while ((entry = readdir(dir)) != NULL) {
            // Skip the current and parent directory symbols
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // Construct full path to the file/directory
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

            // Get information about the file/directory
            if (stat(full_path, &statbuf) == 0) {
                // Check if it's a directory or a file
                if (S_ISDIR(statbuf.st_mode)) {
                    // Recursive call for directories
                    long long dir_size = 0;
                    analyze_directory(full_path, &dir_size);
                    *total_size += dir_size;
                    print_usage_report(full_path, dir_size);
                } else {
                    // Accumulate size for regular files
                    *total_size += statbuf.st_size;
                }
            } else {
                perror("Could not retrieve file statistics");
            }
        }
        closedir(dir);
    } else {
        perror("Could not open directory");
    }
}

void print_usage_report(const char *directory, long long size) {
    printf("Directory: %s consumes %lld bytes\n", directory, size);
}

void filter_and_report(const char *directory, long long size) {
    // This function can be implemented to filter reports based on file types or other criteria
}