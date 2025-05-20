//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

void sync_file(const char *src, const char *dest) {
    FILE *src_file, *dest_file;
    char buffer[BUFFER_SIZE];
    size_t bytes;

    // Open source file for reading
    src_file = fopen(src, "rb");
    if (!src_file) {
        perror("Failed to open source file");
        return;
    }

    // Open destination file for writing
    dest_file = fopen(dest, "wb");
    if (!dest_file) {
        perror("Failed to open destination file");
        fclose(src_file);
        return;
    }

    // Copy the content from source to destination
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

int is_file_updated(const char *src, const char *dest) {
    struct stat src_stat, dest_stat;

    if (stat(src, &src_stat) != 0 || stat(dest, &dest_stat) != 0) {
        return 1; // File is missing, consider it updated
    }

    return src_stat.st_mtime > dest_stat.st_mtime;
}

void synchronize_directories(const char *src_dir, const char *dest_dir) {
    DIR *dir;
    struct dirent *entry;
    char src_path[MAX_PATH], dest_path[MAX_PATH];

    dir = opendir(src_dir);
    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Ignore the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_REG) {
            // Regular file, check if it needs updating
            if (is_file_updated(src_path, dest_path)) {
                printf("Syncing file: %s -> %s\n", src_path, dest_path);
                sync_file(src_path, dest_path);
            }
        }
        // If this was a folder, you might want to add directory handling here
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    synchronize_directories(src_dir, dest_dir);

    printf("Synchronization completed.\n");

    return EXIT_SUCCESS;
}