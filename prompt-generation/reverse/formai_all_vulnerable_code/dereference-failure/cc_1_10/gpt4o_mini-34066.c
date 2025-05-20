//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

void copy_file(const char *src, const char *dest) {
    int source = open(src, O_RDONLY);
    if (source < 0) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    int destination = open(dest, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (destination < 0) {
        perror("Error opening destination file");
        close(source);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    while ((bytesRead = read(source, buffer, BUFFER_SIZE)) > 0) {
        write(destination, buffer, bytesRead);
    }

    close(source);
    close(destination);
}

int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

void sync_files(const char *src_dir, const char *dest_dir) {
    struct dirent *entry;
    DIR *dp = opendir(src_dir);
    if (dp == NULL) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files and directories
        }

        char src_path[PATH_MAX];
        char dest_path[PATH_MAX];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        struct stat st_src, st_dest;

        if (stat(src_path, &st_src) == 0) {
            if (S_ISDIR(st_src.st_mode)) {
                // Create the destination directory if it doesn't exist
                if (!file_exists(dest_path)) {
                    mkdir(dest_path, 0755);
                }
                // Recurively sync the directory
                sync_files(src_path, dest_path);
            } else {
                // If the file does not exist in the destination or has changed, copy it
                if (!file_exists(dest_path) || (stat(dest_path, &st_dest) == 0 && st_src.st_mtime > st_dest.st_mtime)) {
                    printf("Copying file: %s -> %s\n", src_path, dest_path);
                    copy_file(src_path, dest_path);
                }
            }
        }
    }

    closedir(dp);
}

void print_usage(char *prog_name) {
    printf("Usage: %s <source_directory> <destination_directory>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    printf("Synchronizing files from '%s' to '%s'\n", source_directory, destination_directory);
    sync_files(source_directory, destination_directory);
    printf("Synchronization complete!\n");

    return EXIT_SUCCESS;
}