//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PATH_MAX 4096

void sync_files(const char *source_dir, const char *target_dir);
void copy_file(const char *source_file, const char *target_file);
int is_same_file(const char *file1, const char *file2);
void create_directory(const char *path);
void list_files(const char *directory, FILE *log_file);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <target_directory>\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);
    return 0;
}

void sync_files(const char *source_dir, const char *target_dir) {
    DIR *dir;
    struct dirent *entry;
    char source_path[PATH_MAX];
    char target_path[PATH_MAX];
    
    create_directory(target_dir);

    if ((dir = opendir(source_dir)) == NULL) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(target_path, sizeof(target_path), "%s/%s", target_dir, entry->d_name);

        struct stat st;
        if (stat(source_path, &st) == -1) {
            perror("Failed to retrieve file information");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            sync_files(source_path, target_path);
        } else {
            if (!is_same_file(source_path, target_path)) {
                copy_file(source_path, target_path);
            }
        }
    }

    closedir(dir);
}

void copy_file(const char *source_file, const char *target_file) {
    FILE *src = fopen(source_file, "rb");
    FILE *dst = fopen(target_file, "wb");
    
    if (!src || !dst) {
        perror("Error opening files for copy");
        if (src) fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, sizeof(char), bytes, dst);
    }

    fclose(src);
    fclose(dst);
    printf("Copied: %s to %s\n", source_file, target_file);
}

int is_same_file(const char *file1, const char *file2) {
    struct stat st1, st2;

    if (stat(file1, &st1) == -1 || stat(file2, &st2) == -1) {
        return 0; // If one file does not exist, they are not the same
    }

    return (st1.st_size == st2.st_size && st1.st_mtime == st2.st_mtime);
}

void create_directory(const char *path) {
    struct stat st;
    if (stat(path, &st) != 0) {
        // If it does not exist, create the directory
        if (mkdir(path, 0755) != 0) {
            perror("Failed to create directory");
        } else {
            printf("Created directory: %s\n", path);
        }
    }
}

void list_files(const char *directory, FILE *log_file) {
    DIR *dir;
    struct dirent *entry;
    
    if ((dir = opendir(directory)) == NULL) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            continue; // Skip directories for this log
        }
        fprintf(log_file, "%s/%s\n", directory, entry->d_name);
    }

    closedir(dir);
}