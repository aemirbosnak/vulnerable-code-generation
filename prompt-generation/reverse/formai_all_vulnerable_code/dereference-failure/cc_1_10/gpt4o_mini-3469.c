//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

void copy_file(const char *src_file, const char *dest_file) {
    FILE *source, *dest;
    char buffer[BUFFER_SIZE];
    size_t bytes;

    source = fopen(src_file, "rb");
    if (!source) {
        perror("fopen source");
        exit(EXIT_FAILURE);
    }

    dest = fopen(dest_file, "wb");
    if (!dest) {
        fclose(source);
        perror("fopen dest");
        exit(EXIT_FAILURE);
    }

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(source);
    fclose(dest);
}

int file_exists(const char *file_path) {
    struct stat buffer;
    return (stat(file_path, &buffer) == 0);
}

int compare_files(const char *file1, const char *file2) {
    struct stat stat1, stat2;

    if (stat(file1, &stat1) == -1 || stat(file2, &stat2) == -1) {
        return 0; // If either file does not exist, return 0 (different)
    }

    return (stat1.st_mtime == stat2.st_mtime && stat1.st_size == stat2.st_size);
}

void sync_directory(const char *src_dir, const char *dest_dir) {
    struct dirent *entry;
    DIR *dp;
    char src_path[MAX_PATH], dest_path[MAX_PATH];

    dp = opendir(src_dir);
    if (!dp) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (file_exists(dest_path)) {
            if (!compare_files(src_path, dest_path)) {
                printf("Updating file: %s -> %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            } else {
                printf("File already up-to-date: %s\n", dest_path);
            }
        } else {
            printf("Copying new file: %s -> %s\n", src_path, dest_path);
            copy_file(src_path, dest_path);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sync_directory(argv[1], argv[2]);

    printf("Synchronization completed successfully!\n");
    return EXIT_SUCCESS;
}