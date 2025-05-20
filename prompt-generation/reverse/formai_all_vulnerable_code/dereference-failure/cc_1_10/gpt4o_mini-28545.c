//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_PATH 256

// Function prototypes
void sync_files(const char *source, const char *dest);
void copy_file(const char *source_file, const char *dest_file);
int is_directory(const char *path);
void create_directory(const char *path);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];

    printf("Synchronizing files from '%s' to '%s'\n", source_dir, dest_dir);
    sync_files(source_dir, dest_dir);

    printf("Synchronization complete!\n");
    return EXIT_SUCCESS;
}

// Function to synchronize files from source to destination
void sync_files(const char *source, const char *dest) {
    DIR *dir;
    struct dirent *entry;
    char source_path[MAX_PATH], dest_path[MAX_PATH];

    dir = opendir(source);
    if (!dir) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(source_path, sizeof(source_path), "%s/%s", source, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

            // If the entry is a directory, create the directory in destination and sync
            if (is_directory(source_path)) {
                create_directory(dest_path);
                sync_files(source_path, dest_path);
            } else {
                // If the entry is a file, copy it
                copy_file(source_path, dest_path);
            }
        }
    }
    closedir(dir);
}

// Function to copy a file from source to destination
void copy_file(const char *source_file, const char *dest_file) {
    FILE *src = fopen(source_file, "rb");
    FILE *dest = fopen(dest_file, "wb");
    char buffer[BUFFER_SIZE];
    size_t bytes;

    // Check if source file opened successfully
    if (!src) {
        perror("Error opening source file");
        return;
    }

    // Check if destination file opened successfully
    if (!dest) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    // Copy the file contents
    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, sizeof(char), bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

// Function to check if a given path is a directory
int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

// Function to create a directory if it does not exist
void create_directory(const char *path) {
    if (is_directory(path)) return;
    if (mkdir(path, 0755) != 0) {
        perror("Error creating directory");
    }
}

// Function to print usage instructions
void print_usage(const char *program_name) {
    printf("Usage: %s <source_directory> <destination_directory>\n", program_name);
    printf("Synchronize the contents of source_directory with destination_directory.\n");
}