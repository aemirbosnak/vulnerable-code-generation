//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

void print_usage() {
    printf("Usage: file_sync <source_directory> <destination_directory>\n");
    printf("Synchronize files from the source to the destination directory.\n");
}

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void sync_files(const char *src, const char *dest) {
    DIR *dir = opendir(src);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip the current directory and parent directory
        }

        char src_file_path[1024];
        char dest_file_path[1024];
        snprintf(src_file_path, sizeof(src_file_path), "%s/%s", src, entry->d_name);
        snprintf(dest_file_path, sizeof(dest_file_path), "%s/%s", dest, entry->d_name);

        if (is_directory(src_file_path)) {
            // Create destination directory if it doesn't exist
            mkdir(dest_file_path, 0755);
            sync_files(src_file_path, dest_file_path); // Recursive call for subdirectories
        } else {
            FILE *src_file = fopen(src_file_path, "rb");
            if (src_file == NULL) {
                perror("Failed to open source file");
                continue;
            }

            FILE *dest_file = fopen(dest_file_path, "wb");
            if (dest_file == NULL) {
                perror("Failed to open destination file");
                fclose(src_file);
                continue;
            }

            char buffer[8192];
            size_t bytes;

            while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) != 0) {
                fwrite(buffer, 1, bytes, dest_file);
            }

            fclose(src_file);
            fclose(dest_file);
            printf("Synchronized: %s to %s\n", src_file_path, dest_file_path);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    if (!is_directory(src_dir)) {
        fprintf(stderr, "Source path is not a directory: %s\n", src_dir);
        return EXIT_FAILURE;
    }

    if (!is_directory(dest_dir)) {
        fprintf(stderr, "Destination path is not a directory: %s\n", dest_dir);
        return EXIT_FAILURE;
    }

    sync_files(src_dir, dest_dir);
    printf("Synchronization complete!\n");

    return EXIT_SUCCESS;
}