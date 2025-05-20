//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        fprintf(stderr, "Error opening source file: %s\n", source);
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        fprintf(stderr, "Error opening destination file: %s\n", destination);
        fclose(src);
        return;
    }

    char buffer[BUFSIZ];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) != 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    printf("Copied: %s -> %s\n", source, destination);
}

int file_exists(const char *file_path) {
    struct stat buffer;
    return (stat(file_path, &buffer) == 0);
}

void sync_files(const char *source_dir, const char *dest_dir) {
    DIR *dir = opendir(source_dir);
    if (dir == NULL) {
        fprintf(stderr, "Error opening source directory: %s\n", source_dir);
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the '.' and '..' entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[MAX_PATH];
        char dest_path[MAX_PATH];

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (!file_exists(dest_path)) {
            copy_file(source_path, dest_path);
        } else {
            printf("File already exists, skipping: %s\n", dest_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];

    sync_files(source_dir, dest_dir);

    return EXIT_SUCCESS;
}