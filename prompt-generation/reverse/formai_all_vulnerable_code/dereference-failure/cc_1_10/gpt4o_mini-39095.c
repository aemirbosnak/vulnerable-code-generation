//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void sync_files(const char *src_dir, const char *dst_dir);
void copy_file(const char *src_path, const char *dst_path);
void get_full_path(const char *base, const char *filename, char *full_path);
int file_exists(const char *filepath);
int is_difference(const char *src_file, const char *dst_file);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_directory = argv[1];
    const char *dst_directory = argv[2];

    sync_files(src_directory, dst_directory);
    printf("Synchronization of '%s' to '%s' completed.\n", src_directory, dst_directory);

    return EXIT_SUCCESS;
}

void sync_files(const char *src_dir, const char *dst_dir) {
    struct dirent *entry;
    DIR *dp = opendir(src_dir);

    if (dp == NULL) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] == '.') // Skip hidden files
            continue;

        char src_path[512], dst_path[512];
        get_full_path(src_dir, entry->d_name, src_path);
        get_full_path(dst_dir, entry->d_name, dst_path);

        if (entry->d_type == DT_DIR) {
            mkdir(dst_path, 0755); // Create directory if it does not exist
            sync_files(src_path, dst_path); // Recursive call for directories
        } else {
            if (!file_exists(dst_path) || is_difference(src_path, dst_path)) {
                copy_file(src_path, dst_path);
            }
        }
    }

    closedir(dp);
}

void copy_file(const char *src_path, const char *dst_path) {
    FILE *src_file = fopen(src_path, "rb");
    FILE *dst_file = fopen(dst_path, "wb");
    
    if (src_file == NULL || dst_file == NULL) {
        perror("Error opening file");
        if (src_file) fclose(src_file);
        return;
    }
    
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);
    printf("Copied: %s to %s\n", src_path, dst_path);
}

void get_full_path(const char *base, const char *filename, char *full_path) {
    snprintf(full_path, 512, "%s/%s", base, filename);
}

int file_exists(const char *filepath) {
    struct stat buffer;
    return (stat(filepath, &buffer) == 0);
}

int is_difference(const char *src_file, const char *dst_file) {
    struct stat src_stat, dst_stat;
    stat(src_file, &src_stat);
    stat(dst_file, &dst_stat);
    return (src_stat.st_mtime > dst_stat.st_mtime);
}

void print_usage(const char *program_name) {
    printf("Usage: %s <source_directory> <destination_directory>\n", program_name);
}