//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 1024

void copy_file(const char *src, const char *dest) {
    FILE *source, *destination;
    char buffer[1024];
    size_t bytes;

    source = fopen(src, "rb");
    if (source == NULL) {
        perror("Error opening source file");
        return;
    }

    destination = fopen(dest, "wb");
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return;
    }

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

int file_exists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

int is_modified(const char *src, const char *dest) {
    struct stat src_stat, dest_stat;
    if (stat(src, &src_stat) != 0 || stat(dest, &dest_stat) != 0) {
        return 1; // Treat as modified if the destination doesn't exist
    }
    return difftime(src_stat.st_mtime, dest_stat.st_mtime) > 0;
}

void sync_files(const char *src_dir, const char *dest_dir) {
    DIR *dir;
    struct dirent *entry;
    char src_path[MAX_PATH_LEN];
    char dest_path[MAX_PATH_LEN];

    if ((dir = opendir(src_dir)) == NULL) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        // If the file is new or modified, copy it
        if (!file_exists(dest_path) || is_modified(src_path, dest_path)) {
            copy_file(src_path, dest_path);
            printf("Copied: %s to %s\n", src_path, dest_path);
        }
    }

    closedir(dir);
}

void print_usage() {
    printf("Usage: file_sync <source_directory> <destination_directory>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    sync_files(src_dir, dest_dir);

    return EXIT_SUCCESS;
}