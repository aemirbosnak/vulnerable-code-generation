//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

void sync_files(const char* src, const char* dst);
void copy_file(const char* src_file, const char* dst_file);
int is_file_modified(const char* src_file, const char* dst_file);
void copy_directory(const char* src, const char* dst);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sync_files(argv[1], argv[2]);
    return EXIT_SUCCESS;
}

void sync_files(const char* src, const char* dst) {
    struct stat sb;
    
    if (stat(dst, &sb) != 0) {
        if (mkdir(dst, 0700) != 0) {
            perror("Error creating destination directory");
            return;
        }
    }

    DIR* dir = opendir(src);
    if (!dir) {
        perror("Error opening source directory");
        return;
    }
    
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char src_path[MAX_PATH];
            char dst_path[MAX_PATH];

            snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
            snprintf(dst_path, sizeof(dst_path), "%s/%s", dst, entry->d_name);

            if (entry->d_type == DT_DIR) {
                sync_files(src_path, dst_path);
            } else if (entry->d_type == DT_REG) {
                if (is_file_modified(src_path, dst_path)) {
                    printf("Copying modified file: %s to %s\n", src_path, dst_path);
                    copy_file(src_path, dst_path);
                }
            }
        }
    }
    
    closedir(dir);
}

void copy_file(const char* src_file, const char* dst_file) {
    FILE* src = fopen(src_file, "rb");
    if (!src) {
        perror("Error opening source file for reading");
        return;
    }
    
    FILE* dst = fopen(dst_file, "wb");
    if (!dst) {
        perror("Error opening destination file for writing");
        fclose(src);
        return;
    }
    
    char buffer[BUFFER_SIZE];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dst);
    }
    
    fclose(src);
    fclose(dst);
}

int is_file_modified(const char* src_file, const char* dst_file) {
    struct stat src_stat, dst_stat;

    if (stat(src_file, &src_stat) != 0) {
        perror("Error getting source file status");
        return 1; // treat as modified if we cannot access
    }

    if (stat(dst_file, &dst_stat) != 0) {
        return 1; // destination file does not exist, treat as modified
    }

    // Compare modification times
    return src_stat.st_mtime > dst_stat.st_mtime;
}