//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define THRESHOLD_SIZE 104857600 // 100 MB

void check_memory_usage(const char *path);
void analyze_directory(const char *path, const char *base_path);
void report_alert(const char *file_path, long long size);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *directory = argv[1];
    struct stat st;

    if (stat(directory, &st) == -1) {
        perror("Error accessing directory");
        exit(EXIT_FAILURE);
    }

    if (!S_ISDIR(st.st_mode)) {
        fprintf(stderr, "The provided path is not a directory.\n");
        exit(EXIT_FAILURE);
    }

    printf("Analyzing disk space usage for directory: %s\n", directory);
    check_memory_usage(directory);
    
    return EXIT_SUCCESS;
}

void check_memory_usage(const char *path) {
    analyze_directory(path, path);
}

void analyze_directory(const char *path, const char *base_path) {
    DIR *dir;
    struct dirent *entry;
    char full_path[MAX_PATH_LENGTH];
    struct stat st;

    if ((dir = opendir(path)) == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &st) == -1) {
            perror("Error accessing file");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            analyze_directory(full_path, base_path);
        } else {
            long long size = st.st_size;
            printf("File: %s | Size: %lld bytes\n", full_path, size);
            if (size > THRESHOLD_SIZE) {
                report_alert(full_path, size);
            }
        }
    }

    if (closedir(dir) == -1) {
        perror("Error closing directory");
    }
}

void report_alert(const char *file_path, long long size) {
    printf("ALERT! The file '%s' exceeds the threshold size with a size of %lld bytes!\n", file_path, size);
    
    // Additional paranoia check: log the alert to a file
    FILE *log_file = fopen("disk_space_alert.log", "a");
    if (log_file) {
        fprintf(log_file, "ALERT! %s | Size: %lld bytes\n", file_path, size);
        fclose(log_file);
    } else {
        perror("Error logging to alert file");
    }
}