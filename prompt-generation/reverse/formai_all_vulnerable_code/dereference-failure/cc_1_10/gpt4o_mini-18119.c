//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage: sync <source_directory> <destination_directory>\n");
}

int is_file_modified(const char *src_file, const char *dest_file) {
    struct stat src_stat, dest_stat;

    if (stat(src_file, &src_stat) != 0 ||
        stat(dest_file, &dest_stat) != 0) {
        return 1; // Treat as modified if stat fails
    }

    return src_stat.st_mtime > dest_stat.st_mtime;
}

void copy_file(const char *src_file, const char *dest_file) {
    FILE *src = fopen(src_file, "rb");
    FILE *dest = fopen(dest_file, "wb");

    if (!src || !dest) {
        perror("Error opening files for copy");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

void sync_directories(const char *src_dir, const char *dest_dir) {
    DIR *dir = opendir(src_dir);
    struct dirent *entry;

    if (!dir) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files and directories
        }

        char src_file[MAX_PATH];
        char dest_file[MAX_PATH];

        snprintf(src_file, MAX_PATH, "%s/%s", src_dir, entry->d_name);
        snprintf(dest_file, MAX_PATH, "%s/%s", dest_dir, entry->d_name);

        struct stat file_info;
        if (stat(src_file, &file_info) == 0) {
            if (S_ISDIR(file_info.st_mode)) {
                // Create destination directory if it does not exist
                mkdir(dest_file, 0755); 
                // Recursively sync subdirectory
                sync_directories(src_file, dest_file);
            } else {
                // If file doesn't exist or is modified, copy it
                if (access(dest_file, F_OK) != 0 || is_file_modified(src_file, dest_file)) {
                    copy_file(src_file, dest_file);
                    printf("Copied: %s -> %s\n", src_file, dest_file);
                }
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }
    
    sync_directories(argv[1], argv[2]);

    return EXIT_SUCCESS;
}