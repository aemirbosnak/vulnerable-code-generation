//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

// Function to calculate the size of a file
long long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    } else {
        return -1;
    }
}

// Function to print the size of a file in a human-readable format
void print_human_readable_size(long long size) {
    char units[] = "BKMGT";
    int i = 0;
    while (size >= 1024 && i < (sizeof(units) - 1)) {
        size /= 1024;
        i++;
    }
    printf("%lld%c ", size, units[i]);
}

// Function to analyze the disk space usage of a directory
void analyze_directory(const char *dirname) {
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", dirname);
        return;
    }

    struct dirent *entry;
    long long total_size = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char filepath[1024];
        snprintf(filepath, sizeof(filepath), "%s/%s", dirname, entry->d_name);

        struct stat st;
        if (stat(filepath, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                analyze_directory(filepath);
            } else if (S_ISREG(st.st_mode)) {
                total_size += st.st_size;
            }
        } else {
            fprintf(stderr, "Error getting file status for: %s\n", filepath);
        }
    }

    closedir(dir);

    printf("%s: ", dirname);
    print_human_readable_size(total_size);
    printf("\n");
}

int main() {
    analyze_directory("/");

    return 0;
}