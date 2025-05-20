//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

void print_usage(const char *prog_name) {
    printf("Usage: %s <source_folder> <destination_folder>\n", prog_name);
}

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

int copy_file(const char *src_path, const char *dest_path) {
    FILE *src_file = fopen(src_path, "rb");
    if (!src_file) {
        perror("Error opening source file");
        return -1;
    }

    FILE *dest_file = fopen(dest_path, "wb");
    if (!dest_file) {
        perror("Error opening destination file");
        fclose(src_file);
        return -1;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    return 0;
}

void sync_folders(const char *src_folder, const char *dest_folder) {
    DIR *dir = opendir(src_folder);
    if (!dir) {
        perror("Could not open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[MAX_PATH_LENGTH];
        char dest_path[MAX_PATH_LENGTH];

        snprintf(src_path, sizeof(src_path), "%s/%s", src_folder, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_folder, entry->d_name);

        if (is_directory(src_path)) {
            mkdir(dest_path, 0755); // Create directory with 755 permissions
            sync_folders(src_path, dest_path); // Recursive sync
        } else {
            struct stat src_stat, dest_stat;
            int exists = (stat(dest_path, &dest_stat) == 0);
            stat(src_path, &src_stat);

            // Compare modification times
            if (!exists || difftime(src_stat.st_mtime, dest_stat.st_mtime) > 0) {
                printf("Copying file: %s -> %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source = argv[1];
    const char *destination = argv[2];

    // Check if source folder exists
    if (!is_directory(source)) {
        fprintf(stderr, "Source folder does not exist or is not a directory.\n");
        return EXIT_FAILURE;
    }

    // Create destination folder if it doesn't exist
    if (!is_directory(destination)) {
        if (mkdir(destination, 0755) != 0) {
            perror("Error creating destination directory");
            return EXIT_FAILURE;
        }
    }

    sync_folders(source, destination);
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}