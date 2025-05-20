//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void sync_file(const char *src_file, const char *dest_file) {
    struct stat src_stat, dest_stat;

    if (stat(src_file, &src_stat) < 0) {
        perror("Failed to stat source file");
        return;
    }

    if (stat(dest_file, &dest_stat) == 0) {
        // Check if we need to update the file
        if (difftime(src_stat.st_mtime, dest_stat.st_mtime) > 0) {
            if (remove(dest_file) == 0) {
                printf("Updated: %s\n", dest_file);
            } else {
                perror("Failed to remove outdated destination file");
                return;
            }
        } else {
            printf("File is up to date: %s\n", dest_file);
            return;
        }
    } else {
        printf("Adding: %s\n", dest_file);
    }

    // Synchronize the file
    FILE *src_fp = fopen(src_file, "rb");
    FILE *dest_fp = fopen(dest_file, "wb");

    if (src_fp == NULL || dest_fp == NULL) {
        perror("Failed to open files");
        if (src_fp) fclose(src_fp);
        if (dest_fp) fclose(dest_fp);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src_fp)) > 0) {
        fwrite(buffer, 1, bytes, dest_fp);
    }

    fclose(src_fp);
    fclose(dest_fp);
}

void sync_directories(const char *source_dir, const char *dest_dir) {
    DIR *src_dir = opendir(source_dir);
    struct dirent *entry;

    if (!src_dir) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(src_dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        char src_path[MAX_PATH];
        char dest_path[MAX_PATH];

        snprintf(src_path, sizeof(src_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        sync_file(src_path, dest_path);
    }

    closedir(src_dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    sync_directories(source_directory, destination_directory);

    return EXIT_SUCCESS;
}