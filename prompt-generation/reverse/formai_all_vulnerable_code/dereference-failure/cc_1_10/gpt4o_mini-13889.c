//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024

long get_directory_size(const char *path);
void analyze_disk_space(const char *path);
void print_human_readable_size(long size);

int main(int argc, char *argv[]) {
    // Start by celebrating the user's journey into disk space analysis.
    printf("Welcome to the Peaceful Disk Space Analyzer!\n");
    
    // Check if the user provided a path; if not, use the current directory.
    const char *path = (argc > 1) ? argv[1] : ".";
    printf("Analyzing disk space for: %s\n", path);

    // Let the analysis begin!
    analyze_disk_space(path);

    return 0;
}

void analyze_disk_space(const char *path) {
    // Breathe deeply; let's gather the information.
    long total_size = get_directory_size(path);
    printf("Total disk space used in '%s': ", path);
    print_human_readable_size(total_size);
    printf("\n");
}

long get_directory_size(const char *path) {
    long total_size = 0;
    struct dirent *entry;
    struct stat statbuf;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        printf("Unable to open directory: %s\n", path);
        return 0;
    }

    // Peaceful exploration through the directory entries.
    while ((entry = readdir(dp)) != NULL) {
        // Forego the special directories "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        // Gather and process stats for each file and directory.
        if (stat(full_path, &statbuf) == -1) {
            printf("Unable to get stats for: %s\n", full_path);
            continue;
        }

        // If it's a directory, dive deeper, otherwise, accumulate the size.
        if (S_ISDIR(statbuf.st_mode)) {
            total_size += get_directory_size(full_path);
        } else {
            total_size += statbuf.st_size;
        }
    }

    closedir(dp);
    return total_size;
}

void print_human_readable_size(long size) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit_index = 0;

    // Gently transform the size into a more relatable format.
    while (size >= 1024 && unit_index < 4) {
        size /= 1024;
        unit_index++;
    }

    // Print the size with one decimal place and its unit of measurement.
    printf("%.1f %s", size, units[unit_index]);
}