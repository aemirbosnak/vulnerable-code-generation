//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void copy_file(const char *src_file, const char *dest_file) {
    FILE *source = fopen(src_file, "rb");
    FILE *destination = fopen(dest_file, "wb");

    if (source == NULL || destination == NULL) {
        fprintf(stderr, "Error opening files.\n");
        return;
    }

    char buffer[BUFSIZ];
    size_t bytes;

    while ((bytes = fread(buffer, 1, BUFSIZ, source)) != 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
}

int file_exists(const char *file_path) {
    struct stat buffer;
    return (stat(file_path, &buffer) == 0);
}

int files_are_identical(const char *file1, const char *file2) {
    struct stat stat1, stat2;

    if (stat(file1, &stat1) != 0 || stat(file2, &stat2) != 0) {
        return 0;
    }

    return (stat1.st_size == stat2.st_size && stat1.st_mtim.tv_sec == stat2.st_mtim.tv_sec);
}

void sync_directory(const char *src_dir, const char *dest_dir) {
    struct dirent *entry;
    DIR *dp = opendir(src_dir);

    if (dp == NULL) {
        fprintf(stderr, "Error opening source directory: %s\n", src_dir);
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files and current/parent directory
        }

        char src_file[MAX_PATH];
        char dest_file[MAX_PATH];

        snprintf(src_file, sizeof(src_file), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_file, sizeof(dest_file), "%s/%s", dest_dir, entry->d_name);

        if (!file_exists(dest_file) || !files_are_identical(src_file, dest_file)) {
            printf("Copying %s to %s\n", src_file, dest_file);
            copy_file(src_file, dest_file);
        } else {
            printf("File %s is up-to-date.\n", dest_file);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    sync_directory(src_dir, dest_dir);
    printf("Directory synchronization completed.\n");

    return EXIT_SUCCESS;
}