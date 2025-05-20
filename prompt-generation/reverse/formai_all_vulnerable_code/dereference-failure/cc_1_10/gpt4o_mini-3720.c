//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 4096

void usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", program_name);
    exit(EXIT_FAILURE);
}

int copy_file(const char *source_file, const char *dest_file) {
    int src_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    src_fd = open(source_file, O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        return -1;
    }

    dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (dest_fd < 0) {
        perror("Error opening destination file");
        close(src_fd);
        return -1;
    }

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written < 0) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            return -1;
        }
    }

    if (bytes_read < 0) {
        perror("Error reading source file");
    }

    close(src_fd);
    close(dest_fd);
    return 0;
}

int synchronize_files(const char *src, const char *dest) {
    struct stat src_stat, dest_stat;

    if (stat(src, &src_stat) < 0) {
        perror("Stat error on source file");
        return -1;
    }
    
    if (stat(dest, &dest_stat) < 0) {
        copy_file(src, dest);
        return 0;
    }

    // Check if source file is newer than destination file
    if (src_stat.st_mtime > dest_stat.st_mtime) {
        return copy_file(src, dest);
    }
    
    return 0; // No action needed if destination is up to date
}

void sync_directory(const char *src_dir, const char *dest_dir) {
    DIR *directory;
    struct dirent *entry;
    char src_path[MAX_PATH_LENGTH], dest_path[MAX_PATH_LENGTH];

    directory = opendir(src_dir);
    if (!directory) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files and directories
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Create destination directory if it doesn't exist
            mkdir(dest_path, 0755);
            // Recursively synchronize the subdirectory
            sync_directory(src_path, dest_path);
        } else if (entry->d_type == DT_REG) {
            synchronize_files(src_path, dest_path);
        }
    }

    closedir(directory);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
    }

    sync_directory(argv[1], argv[2]);
    printf("Synchronization completed from '%s' to '%s'.\n", argv[1], argv[2]);

    return EXIT_SUCCESS;
}