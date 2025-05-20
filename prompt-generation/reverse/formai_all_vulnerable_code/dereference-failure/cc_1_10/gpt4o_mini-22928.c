//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 8192

void sync_files(const char *source_dir, const char *dest_dir);
void copy_file(const char *source_file, const char *dest_file);
int is_file_modified(const char *source_file, const char *dest_file);
void sync_directory(const char *source_dir, const char *dest_dir);
int is_directory(const char *path);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sync_files(argv[1], argv[2]);

    return EXIT_SUCCESS;
}

void sync_files(const char *source_dir, const char *dest_dir) {
    struct stat st;
    if (stat(source_dir, &st) != 0 || !is_directory(source_dir)) {
        fprintf(stderr, "Source directory %s is not valid\n", source_dir);
        exit(EXIT_FAILURE);
    }
    
    if (stat(dest_dir, &st) != 0 || !is_directory(dest_dir)) {
        fprintf(stderr, "Destination directory %s is not valid. Creating it now.\n", dest_dir);
        if (mkdir(dest_dir, 0755) != 0) {
            perror("Failed to create destination directory");
            exit(EXIT_FAILURE);
        }
    }

    sync_directory(source_dir, dest_dir);
}

void sync_directory(const char *source_dir, const char *dest_dir) {
    DIR *dir;
    struct dirent *entry;
    char source_path[MAX_PATH];
    char dest_path[MAX_PATH];

    dir = opendir(source_dir);
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;  // Skip hidden files and current/parent directories
        }

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (is_directory(source_path)) {
            sync_directory(source_path, dest_path);
        } else {
            if (is_file_modified(source_path, dest_path)) {
                copy_file(source_path, dest_path);
            }
        }
    }

    closedir(dir);
}

int is_file_modified(const char *source_file, const char *dest_file) {
    struct stat source_stat, dest_stat;

    if (stat(source_file, &source_stat) != 0) {
        perror("stat");
        return 1;  // File doesn't exist in source, needs to be copied
    }

    if (stat(dest_file, &dest_stat) != 0) {
        return 1;  // File doesn't exist in dest, needs to be copied
    }

    return difftime(source_stat.st_mtime, dest_stat.st_mtime) > 0;  // Check modification time
}

void copy_file(const char *source_file, const char *dest_file) {
    FILE *src = fopen(source_file, "rb");
    FILE *dst = fopen(dest_file, "wb");
    char buffer[BUFFER_SIZE];
    size_t bytes;

    if (!src || !dst) {
        perror("File open error");
        exit(EXIT_FAILURE);
    }

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dst);
    }

    fclose(src);
    fclose(dst);
}

int is_directory(const char *path) {
    struct stat st;
    if (stat(path, &st) != 0) {
        return 0;  // Not a directory (or path doesn't exist)
    }
    return S_ISDIR(st.st_mode);
}