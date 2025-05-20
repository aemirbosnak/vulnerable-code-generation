//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

// Function declarations
void sync_files(const char *source_dir, const char *dest_dir);
void copy_file(const char *source_file, const char *dest_file);
int is_file_newer(const char *source_file, const char *dest_file);
void create_directory_if_not_exists(const char *dir);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    sync_files(source_directory, destination_directory);

    return EXIT_SUCCESS;
}

// Synchronizing files from source directory to destination directory
void sync_files(const char *source_dir, const char *dest_dir) {
    DIR *dir = opendir(source_dir);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }

    create_directory_if_not_exists(dest_dir);

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[BUFFER_SIZE];
        char dest_path[BUFFER_SIZE];

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        // Check if it's a directory
        struct stat statbuf;
        if (stat(source_path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
            sync_files(source_path, dest_path);
        } else {
            // Copy file if it's newer or doesn't exist in destination
            if (!is_file_newer(source_path, dest_path)) {
                printf("Copying %s to %s\n", source_path, dest_path);
                copy_file(source_path, dest_path);
            } else {
                printf("Skipping %s, it is already up to date.\n", dest_path);
            }
        }
    }

    closedir(dir);
}

// Copying file from source to destination
void copy_file(const char *source_file, const char *dest_file) {
    FILE *src = fopen(source_file, "rb");
    if (!src) {
        perror("Failed to open source file");
        exit(EXIT_FAILURE);
    }

    FILE *dest = fopen(dest_file, "wb");
    if (!dest) {
        fclose(src);
        perror("Failed to open destination file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, sizeof(char), bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

// Checking if source file is newer than destination file
int is_file_newer(const char *source_file, const char *dest_file) {
    struct stat src_stat, dest_stat;

    if (stat(source_file, &src_stat) != 0) {
        perror("Error retrieving source file stats");
        exit(EXIT_FAILURE);
    }

    if (stat(dest_file, &dest_stat) != 0) {
        // If destination file doesn't exist, consider source file as newer
        return 0;
    }

    return src_stat.st_mtime <= dest_stat.st_mtime;
}

// Create directory if it does not exist
void create_directory_if_not_exists(const char *dir) {
    struct stat st;
    
    if (stat(dir, &st) == -1) {
        if (mkdir(dir, 0700) != 0) {
            perror("Error creating directory");
            exit(EXIT_FAILURE);
        }
    } else if (!S_ISDIR(st.st_mode)) {
        fprintf(stderr, "%s is not a directory\n", dir);
        exit(EXIT_FAILURE);
    }
}