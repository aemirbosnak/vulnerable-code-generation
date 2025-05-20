//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define FILENAME_LENGTH 256

void print_usage() {
    printf("Usage: file_sync <source_directory> <destination_directory>\n");
}

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void copy_file(const char *source, const char *destination) {
    FILE *src, *dest;
    char buffer[BUFFER_SIZE];
    size_t bytes;

    src = fopen(source, "rb");
    if (src == NULL) {
        perror("Failed to open source file");
        return;
    }

    dest = fopen(destination, "wb");
    if (dest == NULL) {
        perror("Failed to open destination file");
        fclose(src);
        return;
    }

    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, sizeof(char), bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

void sync_directories(const char *source_dir, const char *destination_dir) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(source_dir)) == NULL) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[FILENAME_LENGTH], destination_path[FILENAME_LENGTH];
        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(destination_path, sizeof(destination_path), "%s/%s", destination_dir, entry->d_name);

        if (is_directory(source_path)) {
            // Create directory
            mkdir(destination_path, 0777);
            // Recursively sync sub-directory
            sync_directories(source_path, destination_path);
        } else {
            // Copy the file
            copy_file(source_path, destination_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *destination_dir = argv[2];

    if (!is_directory(source_dir)) {
        fprintf(stderr, "Source path is not a valid directory: %s\n", source_dir);
        return EXIT_FAILURE;
    }

    if (!is_directory(destination_dir)) {
        fprintf(stderr, "Destination path is not a valid directory: %s\n", destination_dir);
        return EXIT_FAILURE;
    }

    sync_directories(source_dir, destination_dir);
    printf("Synchronization completed from %s to %s\n", source_dir, destination_dir);

    return EXIT_SUCCESS;
}