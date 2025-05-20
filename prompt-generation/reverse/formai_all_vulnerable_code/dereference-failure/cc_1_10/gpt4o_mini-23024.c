//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_DIRS 2048

typedef struct {
    char path[MAX_PATH];
    long total_size;
} DirectoryData;

void analyze_directory(const char *dir_path, DirectoryData *dir_data, int *dir_count) {
    struct stat statbuf;
    DIR *dir;
    struct dirent *entry;
    char full_path[MAX_PATH];
    long dir_size = 0;

    if ((dir = opendir(dir_path)) == NULL) {
        perror("opendir failed");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

            if (stat(full_path, &statbuf) == -1) {
                perror("stat failed");
                continue;
            }

            // If the entry is a directory, analyze it recursively.
            if (S_ISDIR(statbuf.st_mode)) {
                analyze_directory(full_path, dir_data, dir_count);
            } else {
                // Add file size to the current directory size
                dir_size += statbuf.st_size;
            }
        }
    }
    closedir(dir);

    // Store total size for current directory
    if (*dir_count < MAX_DIRS) {
        strncpy(dir_data[*dir_count].path, dir_path, MAX_PATH);
        dir_data[*dir_count].total_size = dir_size;
        (*dir_count)++;
    }
}

void print_usage(DirectoryData *dir_data, int dir_count) {
    printf("Directory Size Analysis:\n");
    printf("%-50s %10s\n", "Directory Path", "Size (Bytes)");

    // Print the sizes of each directory
    for (int i = 0; i < dir_count; i++) {
        printf("%-50s %10ld\n", dir_data[i].path, dir_data[i].total_size);
    }
}

int main(int argc, char *argv[]) {
    DirectoryData dir_data[MAX_DIRS];
    int dir_count = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Start analyzing from the provided directory
    analyze_directory(argv[1], dir_data, &dir_count);

    // Print out the collected directory sizes
    print_usage(dir_data, dir_count);

    return EXIT_SUCCESS;
}