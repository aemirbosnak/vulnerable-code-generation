//FormAI DATASET v1.0 Category: File Synchronizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void synchronize(char *src_dir, char *dest_dir);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [source_directory] [destination_directory]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    synchronize(argv[1], argv[2]);

    return EXIT_SUCCESS;
}

// Recursively synchronizes files from src_dir to dest_dir
void synchronize(char *src_dir, char *dest_dir) {
    DIR *src_dp, *dest_dp;
    struct dirent *src_entry, *dest_entry;
    struct stat src_stat, dest_stat;
    char src_path[256], dest_path[256];

    // Open source directory
    if ((src_dp = opendir(src_dir)) == NULL) {
        fprintf(stderr, "Could not open source directory %s\n", src_dir);
        exit(EXIT_FAILURE);
    }

    // Open destination directory
    if ((dest_dp = opendir(dest_dir)) == NULL) {
        if (mkdir(dest_dir, 0777) == -1) {
            fprintf(stderr, "Could not create destination directory %s\n", dest_dir);
            exit(EXIT_FAILURE);
        }
        dest_dp = opendir(dest_dir);
    }

    // Synchronize each file in source directory
    while ((src_entry = readdir(src_dp)) != NULL) {
        // Skip . and .. directories
        if (strcmp(src_entry->d_name, ".") == 0 || strcmp(src_entry->d_name, "..") == 0)
            continue;

        // Get source file path
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, src_entry->d_name);

        // Get destination file path
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, src_entry->d_name);

        // Get source and destination file stats
        stat(src_path, &src_stat);
        stat(dest_path, &dest_stat);

        if (S_ISDIR(src_stat.st_mode)) {
            // Recursively synchronize directories
            synchronize(src_path, dest_path);
        } else if (S_ISREG(src_stat.st_mode)) {
            // If source file is newer than destination file, copy it over
            if (src_stat.st_mtime > dest_stat.st_mtime || dest_stat.st_size != src_stat.st_size) {
                FILE *src_file = fopen(src_path, "rb");
                FILE *dest_file = fopen(dest_path, "wb");

                if (!src_file) {
                    fprintf(stderr, "Could not open source file %s\n", src_path);
                    exit(EXIT_FAILURE);
                }

                if (!dest_file) {
                    fprintf(stderr, "Could not open destination file %s\n", dest_path);
                    exit(EXIT_FAILURE);
                }

                char buffer[1024];
                size_t size;

                while ((size = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                    fwrite(buffer, 1, size, dest_file);
                }

                fclose(src_file);
                fclose(dest_file);

                printf("Copied %s to %s\n", src_path, dest_path);
            }
        }
    }

    closedir(src_dp);
    closedir(dest_dp);
}