//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void copy_file(const char *source, const char *destination) {
    FILE *src, *dest;
    char buffer[BUFFER_SIZE];
    size_t n;

    src = fopen(source, "rb");
    if (src == NULL) {
        perror("Source file error");
        return;
    }

    dest = fopen(destination, "wb");
    if (dest == NULL) {
        perror("Destination file error");
        fclose(src);
        return;
    }

    while ((n = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, n, dest);
    }

    fclose(src);
    fclose(dest);
    printf("Copied '%s' to '%s'\n", source, destination);
}

int files_are_identical(const char *file1, const char *file2) {
    struct stat stat1, stat2;
    
    if (stat(file1, &stat1) == -1 || stat(file2, &stat2) == -1) {
        return 0; // If stat fails, treat files as different
    }

    return (stat1.st_size == stat2.st_size && stat1.st_mtime == stat2.st_mtime);
}

void sync_directory(const char *source_dir, const char *dest_dir) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(source_dir);
    if (dir == NULL) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') // Skip . and ..
            continue;

        char source_path[PATH_MAX];
        char dest_path[PATH_MAX];

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        struct stat stat_buf;
        if (stat(source_path, &stat_buf) == -1) {
            perror("Failed to stat source file");
            continue;
        }

        if (S_ISDIR(stat_buf.st_mode)) {
            // It's a directory, sync recursively
            mkdir(dest_path, 0755);
            sync_directory(source_path, dest_path);
        } else {
            // It's a file, sync it
            if (access(dest_path, F_OK) == -1 || !files_are_identical(source_path, dest_path)) {
                copy_file(source_path, dest_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    // Check if source directory exists
    struct stat sb;
    if (stat(source_directory, &sb) == -1 || !S_ISDIR(sb.st_mode)) {
        perror("Source directory does not exist or is not a directory");
        return EXIT_FAILURE;
    }

    // Create destination directory if it doesn't exist
    if (stat(destination_directory, &sb) == -1) {
        if (mkdir(destination_directory, 0755) == -1) {
            perror("Failed to create destination directory");
            return EXIT_FAILURE;
        }
        printf("Created destination directory: '%s'\n", destination_directory);
    }

    // Start the synchronization process
    printf("Starting synchronization from '%s' to '%s'...\n", source_directory, destination_directory);
    sync_directory(source_directory, destination_directory);
    printf("Synchronization complete!\n");

    return EXIT_SUCCESS;
}