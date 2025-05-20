//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void sync_files(const char *source_dir, const char *dest_dir);
void copy_file(const char *source_file, const char *dest_file);
int is_file_modified(const char *file1, const char *file2);
void ensure_directory(const char *dir);
void print_usage();

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];

    sync_files(source_dir, dest_dir);

    printf("Synchronization complete from '%s' to '%s'\n", source_dir, dest_dir);
    return EXIT_SUCCESS;
}

void sync_files(const char *source_dir, const char *dest_dir) {
    DIR *dir = opendir(source_dir);
    struct dirent *entry;

    ensure_directory(dest_dir);

    if (dir == NULL) {
        perror("Could not open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files and directories
        }

        char source_path[BUFFER_SIZE];
        char dest_path[BUFFER_SIZE];
        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        struct stat statbuf;
        if (stat(source_path, &statbuf) == -1) {
            perror("Stat failed");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            sync_files(source_path, dest_path);
        } else if (S_ISREG(statbuf.st_mode)) {
            if (!is_file_modified(source_path, dest_path)) {
                copy_file(source_path, dest_path);
            }
        }
    }

    closedir(dir);
}

void copy_file(const char *source_file, const char *dest_file) {
    FILE *source = fopen(source_file, "rb");
    FILE *dest = fopen(dest_file, "wb");

    if (source == NULL || dest == NULL) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) != 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(source);
    fclose(dest);
    printf("Copied: '%s' to '%s'\n", source_file, dest_file);
}

int is_file_modified(const char *file1, const char *file2) {
    struct stat stat1, stat2;

    if (stat(file1, &stat1) == -1) return 1; // Assume modified if stat fails
    if (stat(file2, &stat2) == -1) return 1; // Assume modified if dest file doesn't exist

    return stat1.st_mtime > stat2.st_mtime; // Check modification time
}

void ensure_directory(const char *dir) {
    struct stat st = {0};

    if (stat(dir, &st) == -1) {
        mkdir(dir, 0700); // Create directory if it does not exist
    }
}

void print_usage() {
    printf("Usage: file_sync <source_directory> <destination_directory>\n");
}