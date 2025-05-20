//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

void print_usage() {
    printf("Usage: file_sync <source_directory> <destination_directory>\n");
}

int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

int is_file_modified(const char *src, const char *dest) {
    struct stat src_stat, dest_stat;
    stat(src, &src_stat);
    if (stat(dest, &dest_stat) != 0) return 1;
    return src_stat.st_mtime > dest_stat.st_mtime;
}

void sync_file(const char *src_path, const char *dest_path) {
    FILE *src_file = fopen(src_path, "rb");
    if (src_file == NULL) {
        printf("Failed to open source file: %s\n", src_path);
        return;
    }

    FILE *dest_file = fopen(dest_path, "wb");
    if (dest_file == NULL) {
        printf("Failed to open destination file: %s\n", dest_path);
        fclose(src_file);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    printf("Synchronized: %s to %s\n", src_path, dest_path);
}

void sync_directory(const char *src_dir, const char *dest_dir) {
    DIR *dir = opendir(src_dir);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Could not open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Ignore hidden files and directories
        }

        char src_path[1024];
        char dest_path[1024];

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_REG) {
            // Regular file
            if (!file_exists(dest_path) || is_file_modified(src_path, dest_path)) {
                sync_file(src_path, dest_path);
            }
        } else if (entry->d_type == DT_DIR) {
            // Directory, create it in destination if not exists and sync recursively
            if (!file_exists(dest_path)) {
                mkdir(dest_path, 0755);
            }
            sync_directory(src_path, dest_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    // Create destination directory if it does not exist
    if (!file_exists(dest_dir)) {
        if (mkdir(dest_dir, 0755) != 0) {
            perror("Failed to create destination directory");
            return EXIT_FAILURE;
        }
    }

    sync_directory(src_dir, dest_dir);
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}