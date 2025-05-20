//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

// Struct to hold information about each file/folder
struct file_info {
    char *name;
    off_t size;
};

// Function to recursively get file information for a given folder
void get_file_info(char *folder_path, struct file_info **info, int *num_files) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char path[1024];

    // Open directory
    dir = opendir(folder_path);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", folder_path);
        return;
    }

    // Loop through directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Create full path to this entry
        snprintf(path, sizeof(path), "%s/%s", folder_path, entry->d_name);

        // Get file information
        if (lstat(path, &file_stat) < 0) {
            printf("Error getting file information: %s\n", path);
            continue;
        }

        // If this is a directory, recursively get file info for it
        if (S_ISDIR(file_stat.st_mode)) {
            get_file_info(path, info, num_files);
        }
        // If this is a file, add its info to the array
        else if (S_ISREG(file_stat.st_mode)) {
            *info = realloc(*info, (*num_files + 1) * sizeof(struct file_info));
            (*info)[*num_files].name = strdup(path);
            (*info)[*num_files].size = file_stat.st_size;
            (*num_files)++;
        }
    }

    // Close directory
    closedir(dir);
}

int compare_file_sizes(const void *a, const void *b) {
    struct file_info *file_info_a = (struct file_info *)a;
    struct file_info *file_info_b = (struct file_info *)b;

    if (file_info_a->size < file_info_b->size) {
        return 1;
    } else if (file_info_a->size > file_info_b->size) {
        return -1;
    } else {
        return 0;
    }
}

int main(int argc, char **argv) {
    // Get path to directory to analyze from command line argument
    if (argc != 2) {
        printf("Usage: %s [path]\n", argv[0]);
        return 1;
    }
    char *folder_path = argv[1];

    // Get file information for directory
    struct file_info *info = NULL;
    int num_files = 0;
    get_file_info(folder_path, &info, &num_files);

    // Sort file information by size (largest first)
    qsort(info, num_files, sizeof(struct file_info), compare_file_sizes);

    // Print out file information
    printf("Disk space usage for %s:\n\n", folder_path);
    printf("%-60s %10s\n", "File Name", "File Size");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < num_files; i++) {
        printf("%-60s %10ld bytes\n", info[i].name, info[i].size);
    }

    // Free memory used by file information
    for (int i = 0; i < num_files; i++) {
        free(info[i].name);
    }
    free(info);

    return 0;
}