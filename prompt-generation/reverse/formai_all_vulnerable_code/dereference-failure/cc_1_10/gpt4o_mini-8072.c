//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void synchronize_files(const char *src, const char *dest) {
    DIR *src_dir = opendir(src);
    if (src_dir == NULL) {
        perror("Failed to open source directory");
        return;
    }

    struct dirent *entry;
    struct stat src_file_stat, dest_file_stat;
    char src_file_path[PATH_MAX];
    char dest_file_path[PATH_MAX];

    while ((entry = readdir(src_dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // skip hidden files and directories
        }

        snprintf(src_file_path, sizeof(src_file_path), "%s/%s", src, entry->d_name);
        snprintf(dest_file_path, sizeof(dest_file_path), "%s/%s", dest, entry->d_name);

        if (stat(src_file_path, &src_file_stat) != 0) {
            perror("Stat failed for source file");
            continue;
        }

        // Check if the destination file exists
        if (stat(dest_file_path, &dest_file_stat) != 0) {
            // Destination file does not exist, copy it
            printf("Copying new file: %s -> %s\n", src_file_path, dest_file_path);
            FILE *src_file = fopen(src_file_path, "rb");
            FILE *dest_file = fopen(dest_file_path, "wb");
            if (src_file && dest_file) {
                char buffer[BUFFER_SIZE];
                size_t n;
                while ((n = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                    fwrite(buffer, 1, n, dest_file);
                }
            }
            fclose(src_file);
            fclose(dest_file);
        } else {
            // Destination file exists, compare modification times
            if (difftime(src_file_stat.st_mtime, dest_file_stat.st_mtime) > 0) {
                printf("Updating file: %s -> %s\n", src_file_path, dest_file_path);
                FILE *src_file = fopen(src_file_path, "rb");
                FILE *dest_file = fopen(dest_file_path, "wb");
                if (src_file && dest_file) {
                    char buffer[BUFFER_SIZE];
                    size_t n;
                    while ((n = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                        fwrite(buffer, 1, n, dest_file);
                    }
                }
                fclose(src_file);
                fclose(dest_file);
            }
        }
    }
    closedir(src_dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_directory = argv[1];
    const char *dest_directory = argv[2];

    struct stat st;
    // Check if source directory exists
    if (stat(src_directory, &st) != 0 || !S_ISDIR(st.st_mode)) {
        fprintf(stderr, "Source directory does not exist: %s\n", src_directory);
        return EXIT_FAILURE;
    }

    // Create destination directory if it doesn't exist
    if (stat(dest_directory, &st) != 0) {
        if (mkdir(dest_directory, 0755) != 0) {
            perror("Failed to create destination directory");
            return EXIT_FAILURE;
        }
    }

    synchronize_files(src_directory, dest_directory);
    printf("Synchronization completed!\n");

    return EXIT_SUCCESS;
}