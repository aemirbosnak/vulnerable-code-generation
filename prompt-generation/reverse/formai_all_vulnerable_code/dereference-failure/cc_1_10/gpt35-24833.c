//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define KB 1024
#define MB (KB * 1024)
#define GB (MB * 1024)
#define TB (GB * 1024)

// Function to convert byte size to human readable format
void format_size(unsigned long long n, char *buffer) {
    if (n < KB) {
        sprintf(buffer, "%lld bytes", n);
    } else if (n < MB) {
        sprintf(buffer, "%.2f KB", (double) n / KB);
    } else if (n < GB) {
        sprintf(buffer, "%.2f MB", (double) n / MB);
    } else if (n < TB) {
        sprintf(buffer, "%.2f GB", (double) n / GB);
    } else {
        sprintf(buffer, "%.2f TB", (double) n / TB);
    }
}

// Function to print the usage of each directory recursively
void analyze_directory(const char *directory, unsigned long long *total_size, bool print) {
    struct dirent *entry;
    struct stat st;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        perror("opendir");
        exit(1);
    }

    // Print directory path if print is true
    if (print) {
        printf("\n%s:\n", directory);
    }

    while ((entry = readdir(dp))) {
        // Ignore current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Build the path to the file or directory
        char path[1024];
        sprintf(path, "%s/%s", directory, entry->d_name);

        // Get the stats of the file or directory
        if (stat(path, &st) != 0) {
            perror("stat");
            exit(1);
        }

        // If it's a directory, analyze it recursively
        if (S_ISDIR(st.st_mode)) {
            analyze_directory(path, total_size, print);
        } else {
            // Add the size to the total size
            *total_size += st.st_size;

            // Print the size and filename if print is true
            if (print) {
                char size_buffer[32];
                format_size(st.st_size, size_buffer);
                printf("\t%s\t%s\n", size_buffer, entry->d_name);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s directory_path\n", argv[0]);
        exit(1);
    }

    char *directory = argv[1];

    printf("Analyzing disk space usage...\n");

    unsigned long long total_size = 0;

    analyze_directory(directory, &total_size, true);

    char size_buffer[32];
    format_size(total_size, size_buffer);
    printf("\nTotal Size: %s\n", size_buffer);

    return 0;
}