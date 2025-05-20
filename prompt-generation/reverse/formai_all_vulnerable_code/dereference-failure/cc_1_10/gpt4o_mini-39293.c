//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

void print_usage(const char *program_name) {
    printf("Usage: %s <source_dir> <destination_dir>\n", program_name);
}

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

int file_exists(const char *filepath) {
    struct stat buffer;
    return (stat(filepath, &buffer) == 0);
}

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");

    if (src == NULL || dest == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t n;

    while ((n = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, n, dest);
    }

    fclose(src);
    fclose(dest);
}

void sync_files(const char *source_dir, const char *destination_dir) {
    struct dirent *entry;
    DIR *dp = opendir(source_dir);

    if (dp == NULL) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Ignore . and ..
        }

        char src_path[PATH_MAX];
        char dest_path[PATH_MAX];
        snprintf(src_path, sizeof(src_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", destination_dir, entry->d_name);

        if (is_directory(src_path)) {
            if (!file_exists(dest_path)) {
                mkdir(dest_path, 0755); // Create destination directory if it doesn't exist
            }
            sync_files(src_path, dest_path); // Recursive call for directories
        } else {
            if (!file_exists(dest_path) || (access(src_path, R_OK) == 0 && access(dest_path, W_OK) == 0)) {
                struct stat src_stat, dest_stat;

                stat(src_path, &src_stat);
                stat(dest_path, &dest_stat);

                // Check if source file is newer than destination file
                if (difftime(src_stat.st_mtime, dest_stat.st_mtime) > 0 || !file_exists(dest_path)) {
                    printf("Copying %s to %s\n", src_path, dest_path);
                    copy_file(src_path, dest_path);
                }
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *destination_dir = argv[2];

    if (!is_directory(source_dir)) {
        fprintf(stderr, "Source directory does not exist or is not a directory: %s\n", source_dir);
        return EXIT_FAILURE;
    }

    if (!is_directory(destination_dir)) {
        fprintf(stderr, "Destination directory does not exist or is not a directory: %s\n", destination_dir);
        return EXIT_FAILURE;
    }

    sync_files(source_dir, destination_dir);
    printf("Synchronization completed.\n");

    return EXIT_SUCCESS;
}