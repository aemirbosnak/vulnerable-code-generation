//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void analyze_dir(char *dir);
void analyze_file(char *file_path);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: ./disk-analyzer <directory>\n");
        return 1;
    }

    char *dir = argv[1];
    struct stat st;

    // Check if directory exists
    if (stat(dir, &st) == -1) {
        printf("Error: Could not open directory '%s'\n", dir);
        return 1;
    }

    // Check if directory is actually a directory and not a file
    if (!S_ISDIR(st.st_mode)) {
        printf("Error: '%s' is not a directory\n", dir);
        return 1;
    }

    // Analyze the directory
    analyze_dir(dir);

    return 0;
}

void analyze_dir(char *dir) {
    DIR *d = opendir(dir);
    struct dirent *dir_entry;
    char path[1024];

    while ((dir_entry = readdir(d)) != NULL) {
        // Skip ".", ".." and hidden files/directories
        if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0 || dir_entry->d_name[0] == '.') {
            continue;
        }

        snprintf(path, 1024, "%s/%s", dir, dir_entry->d_name);

        // If it's a directory, analyze it recursively
        if (dir_entry->d_type == DT_DIR) {
            analyze_dir(path);
        }

        // If it's a file, analyze it
        if (dir_entry->d_type == DT_REG) {
            analyze_file(path);
        }
    }

    closedir(d);
}

void analyze_file(char *file_path) {
    struct stat st;
    if (stat(file_path, &st) == -1) {
        printf("Error: Could not open file '%s'\n", file_path);
        return;
    }

    // Print file path and size
    printf("%s - Size: %ld bytes\n", file_path, st.st_size);
}