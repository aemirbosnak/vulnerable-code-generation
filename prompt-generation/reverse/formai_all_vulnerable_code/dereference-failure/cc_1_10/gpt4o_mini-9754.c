//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 8192

void copy_file(const char *source, const char *destination) {
    FILE *src_file = fopen(source, "rb");
    FILE *dest_file = fopen(destination, "wb");
    char buffer[BUFFER_SIZE];
    
    if (!src_file || !dest_file) {
        fprintf(stderr, "Error opening files for copy.\n");
        return;
    }

    size_t n;
    while ((n = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, n, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

void synchronize_files(const char *source_dir, const char *dest_dir) {
    struct dirent *entry;
    struct stat source_stat, dest_stat;
    char source_path[MAX_PATH];
    char dest_path[MAX_PATH];
    DIR *dir = opendir(source_dir);

    if (!dir) {
        fprintf(stderr, "Error opening source directory: %s\n", source_dir);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (stat(source_path, &source_stat) == 0) {
            if (stat(dest_path, &dest_stat) != 0 || source_stat.st_mtime > dest_stat.st_mtime) {
                copy_file(source_path, dest_path);
                printf("Copied: %s to %s\n", source_path, dest_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];

    if (access(source_dir, F_OK) == -1) {
        fprintf(stderr, "Source directory does not exist: %s\n", source_dir);
        return EXIT_FAILURE;
    }

    if (access(dest_dir, F_OK) == -1) {
        fprintf(stderr, "Destination directory does not exist: %s\n", dest_dir);
        return EXIT_FAILURE;
    }

    synchronize_files(source_dir, dest_dir);
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}