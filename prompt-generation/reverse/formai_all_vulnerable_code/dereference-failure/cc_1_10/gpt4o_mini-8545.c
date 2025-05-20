//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

// Function prototypes
void synchronize_dir(const char *src, const char *dst);
int file_exists(const char *file_path);
int is_modified(const char *src, const char *dst);
void copy_file(const char *src, const char *dst);
void print_usage(const char *prog_name);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];

    synchronize_dir(source_dir, dest_dir);

    return EXIT_SUCCESS;
}

void synchronize_dir(const char *src, const char *dst) {
    DIR *dir;
    struct dirent *entry;
    char src_path[MAX_PATH];
    char dst_path[MAX_PATH];

    if ((dir = opendir(src)) == NULL) {
        fprintf(stderr, "Error: Could not open directory %s\n", src);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') // Skip hidden files and current/parent dir
            continue;

        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst, entry->d_name);

        if (entry->d_type == DT_REG) { // Regular file
            if (!file_exists(dst_path) || is_modified(src_path, dst_path)) {
                copy_file(src_path, dst_path);
                printf("Copied: %s -> %s\n", src_path, dst_path);
            }
        }
    }

    closedir(dir);
}

int file_exists(const char *file_path) {
    struct stat buffer;
    return (stat(file_path, &buffer) == 0);
}

int is_modified(const char *src, const char *dst) {
    struct stat src_stat, dst_stat;
    
    stat(src, &src_stat);
    stat(dst, &dst_stat);

    return src_stat.st_mtime > dst_stat.st_mtime; // Check modification time
}

void copy_file(const char *src, const char *dst) {
    FILE *source_file = fopen(src, "rb");
    FILE *dest_file = fopen(dst, "wb");

    if (source_file == NULL || dest_file == NULL) {
        fprintf(stderr, "Error: Could not open file for copying\n");
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <source_directory> <destination_directory>\n", prog_name);
}