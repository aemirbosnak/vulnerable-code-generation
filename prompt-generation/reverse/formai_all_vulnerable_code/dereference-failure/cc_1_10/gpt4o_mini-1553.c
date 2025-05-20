//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void print_usage() {
    printf("Usage: file_backup <source_directory> <destination_directory>\n");
}

int copy_file(const char *src, const char *dest) {
    FILE *src_file = fopen(src, "rb");
    if (!src_file) {
        perror("Failed to open source file");
        return -1;
    }

    FILE *dest_file = fopen(dest, "wb");
    if (!dest_file) {
        fclose(src_file);
        perror("Failed to open destination file");
        return -1;
    }

    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    return 0;
}

int create_backup(const char *src_dir, const char *dest_dir) {
    DIR *dir = opendir(src_dir);
    if (!dir) {
        perror("Failed to open source directory");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            char src_path[MAX_PATH];
            char dest_path[MAX_PATH];

            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);
            
            if (copy_file(src_path, dest_path) == 0) {
                printf("Copied: %s to %s\n", src_path, dest_path);
            } else {
                fprintf(stderr, "Failed to copy: %s\n", src_path);
            }
        }
    }

    closedir(dir);
    return 0;
}

int ensure_directory(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        if (mkdir(path, 0755) == -1) {
            perror("Failed to create destination directory");
            return -1;
        }
    } else if (!S_ISDIR(statbuf.st_mode)) {
        fprintf(stderr, "%s exists but is not a directory\n", path);
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    if (ensure_directory(dest_dir) != 0) {
        return EXIT_FAILURE;
    }

    if (create_backup(src_dir, dest_dir) != 0) {
        return EXIT_FAILURE;
    }

    printf("Backup completed successfully!\n");
    return EXIT_SUCCESS;
}