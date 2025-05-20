//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: intelligent
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

// Define the maximum number of files and directories to track
#define MAX_ENTRIES 10000

// Define the structure to store file and directory information
typedef struct {
    char *path;
    unsigned long size;
} Entry;

// Define the function to compare two entries by size
int compare_entries(const void *a, const void *b) {
    const Entry *entry1 = (const Entry *)a;
    const Entry *entry2 = (const Entry *)b;

    return (entry2->size - entry1->size);
}

// Define the function to print the entries in descending order of size
void print_entries(Entry *entries, int count) {
    // Sort the entries by size
    qsort(entries, count, sizeof(Entry), compare_entries);

    // Print the entries
    for (int i = 0; i < count; i++) {
        printf("%s: %lu bytes\n", entries[i].path, entries[i].size);
    }
}

// Define the function to scan a directory and add its contents to the entries array
int scan_directory(const char *path, Entry *entries, int *count) {
    // Open the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return -1;
    }

    // Iterate over the directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path of the entry
        char full_path[PATH_MAX];
        snprintf(full_path, PATH_MAX, "%s/%s", path, entry->d_name);

        // Get the size of the entry
        struct stat statbuf;
        if (stat(full_path, &statbuf) == -1) {
            continue;
        }

        // Add the entry to the entries array
        if (*count < MAX_ENTRIES) {
            entries[*count].path = strdup(full_path);
            entries[*count].size = statbuf.st_size;
            (*count)++;
        }

        // Recursively scan the entry if it is a directory
        if (S_ISDIR(statbuf.st_mode)) {
            scan_directory(full_path, entries, count);
        }
    }

    // Close the directory
    closedir(dir);

    return 0;
}

int main() {
    // Allocate memory for the entries array
    Entry entries[MAX_ENTRIES];

    // Initialize the count of entries
    int count = 0;

    // Scan the root directory
    scan_directory("/", entries, &count);

    // Print the entries in descending order of size
    print_entries(entries, count);

    // Free the memory allocated for the entries
    for (int i = 0; i < count; i++) {
        free(entries[i].path);
    }

    return 0;
}