//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

void sync_files(const char *src, const char *dest);
void copy_file(const char *src_file, const char *dest_file);
int file_exists(const char *path);
void print_usage(const char *prog_name);

int main(int argc, char *argv[]) {
    // Providing usage information in case of wrong input
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    const char *source_dir = argv[1];
    const char *destination_dir = argv[2];

    // Start the synchronization process
    sync_files(source_dir, destination_dir);
    return 0;
}

// Function to print the usage of the program
void print_usage(const char *prog_name) {
    printf("Usage: %s <source_directory> <destination_directory>\n", prog_name);
}

// Function to compare and sync files from source to destination
void sync_files(const char *src, const char *dest) {
    DIR *source_dir = opendir(src);
    struct dirent *entry;
    
    if (!source_dir) {
        perror("Could not open source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(source_dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Construct full file paths for source and destination
        char source_file[MAX_PATH];
        char dest_file[MAX_PATH];
        snprintf(source_file, sizeof(source_file), "%s/%s", src, entry->d_name);
        snprintf(dest_file, sizeof(dest_file), "%s/%s", dest, entry->d_name);

        // Check if the file exists in the destination directory
        if (!file_exists(dest_file)) {
            printf("Copying new file: %s to %s\n", source_file, dest_file);
            copy_file(source_file, dest_file);
        } else {
            // Only show file comparison if it already exists in destination
            struct stat src_stat, dest_stat;
            stat(source_file, &src_stat);
            stat(dest_file, &dest_stat);

            // Check if there is a size or modification time difference 
            if (src_stat.st_size != dest_stat.st_size || src_stat.st_mtime != dest_stat.st_mtime) {
                printf("Updating file: %s to %s\n", source_file, dest_file);
                copy_file(source_file, dest_file);
            }
        }
    }

    closedir(source_dir);
}

// Function to check if a file exists
int file_exists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

// Function to copy a file from src_file to dest_file
void copy_file(const char *src_file, const char *dest_file) {
    FILE *source = fopen(src_file, "rb");
    if (!source) {
        perror("Source file opening error");
        exit(EXIT_FAILURE);
    }

    FILE *destination = fopen(dest_file, "wb");
    if (!destination) {
        fclose(source);
        perror("Destination file opening error");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFSIZ];
    size_t size;

    // Copying content from source to destination
    while ((size = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, size, destination);
    }

    fclose(source);
    fclose(destination);
}