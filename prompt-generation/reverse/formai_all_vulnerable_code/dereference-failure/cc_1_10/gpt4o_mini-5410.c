//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define MAX_LINE_LENGTH 256

void print_usage(const char* prog_name) {
    printf("Usage: %s [directory] [age_in_days]\n", prog_name);
    printf("  - directory: The directory to clean.\n");
    printf("  - age_in_days: Files older than this will be deleted.\n");
}

int is_file_old(const char* path, int age_in_days) {
    struct stat file_stat;
    if (stat(path, &file_stat) != 0) {
        perror("Failed to get file status");
        return 0; // False, file is not old
    }
    time_t current_time = time(NULL);
    double seconds_in_a_day = 86400; // 60 * 60 * 24
    // Check if the file was last modified more than `age_in_days` ago
    return difftime(current_time, file_stat.st_mtime) > (age_in_days * seconds_in_a_day);
}

void clean_directory(const char* dir_path, int age_in_days) {
    struct dirent* entry;
    DIR* dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_LINE_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_REG) { // If it's a regular file
            if (is_file_old(full_path, age_in_days)) {
                printf("Deleting old file: %s\n", full_path);
                if (unlink(full_path) != 0) {
                    perror("Failed to delete file");
                }
            }
        } else if (entry->d_type == DT_DIR) { // If it's a directory, recurse
            clean_directory(full_path, age_in_days);
        }
    }
    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char* dir_path = argv[1];
    int age_in_days = atoi(argv[2]);

    if (age_in_days < 1) {
        fprintf(stderr, "Age in days must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    clean_directory(dir_path, age_in_days);
    return EXIT_SUCCESS;
}