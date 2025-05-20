//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Define some constants
#define KB 1024
#define MB (KB * 1024)
#define GB (MB * 1024)
#define TB (GB * 1024)

// Define a struct to store the disk usage information
typedef struct {
    char *path;
    long long size;
} disk_usage;

// Function to compare two disk_usage structs by size
int compare_disk_usage(const void *a, const void *b) {
    const disk_usage *ua = (const disk_usage *)a;
    const disk_usage *ub = (const disk_usage *)b;

    return ub->size - ua->size;
}

// Function to get the disk usage of a directory
long long get_disk_usage(const char *path) {
    long long size = 0;
    DIR *dir;
    struct dirent *entry;
    char fullpath[256];

    // Open the directory
    dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return -1;
    }

    // Iterate over the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path to the entry
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        // Get the size of the entry
        struct stat st;
        if (lstat(fullpath, &st) == -1) {
            perror("lstat");
            return -1;
        }

        // Add the size of the entry to the total size
        size += st.st_size;
    }

    // Close the directory
    closedir(dir);

    // Return the total size
    return size;
}

// Function to print the disk usage information
void print_disk_usage(const disk_usage *usage, int num_usage) {
    // Sort the usage information by size
    qsort(usage, num_usage, sizeof(disk_usage), compare_disk_usage);

    // Print the usage information
    for (int i = 0; i < num_usage; i++) {
        printf("%s: %.2f GB\n", usage[i].path, (double)usage[i].size / GB);
    }
}

int main(int argc, char *argv[]) {
    // Get the path to the directory to analyze
    char *path;
    if (argc == 2) {
        path = argv[1];
    } else {
        path = ".";
    }

    // Get the disk usage of the directory
    long long size = get_disk_usage(path);
    if (size == -1) {
        return EXIT_FAILURE;
    }

    // Allocate memory for the usage information
    disk_usage *usage = malloc(sizeof(disk_usage));
    if (!usage) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Store the usage information
    usage->path = strdup(path);
    usage->size = size;

    // Print the usage information
    print_disk_usage(usage, 1);

    // Free the memory
    free(usage->path);
    free(usage);

    return EXIT_SUCCESS;
}