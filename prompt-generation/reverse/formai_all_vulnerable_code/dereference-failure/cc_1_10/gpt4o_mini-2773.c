//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 8192

// Function to check if a file exists
int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Function to get last modification time of a file
time_t get_modification_time(const char *filename) {
    struct stat attr;
    stat(filename, &attr);
    return attr.st_mtime;
}

// Function to copy a file from source to destination
void copy_file(const char *src_file, const char *dst_file) {
    int src_fd, dst_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    src_fd = open(src_file, O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        return;
    }

    dst_fd = open(dst_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd < 0) {
        perror("Error opening destination file");
        close(src_fd);
        return;
    }

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dst_fd, buffer, bytes_read);
        if (bytes_written < 0) {
            perror("Error writing to destination file");
            break;
        }
    }

    close(src_fd);
    close(dst_fd);
}

// Function to synchronize files from source to destination directory
void sync_directories(const char *src_dir, const char *dst_dir) {
    DIR *dir = opendir(src_dir);
    struct dirent *entry;
    char src_path[PATH_MAX], dst_path[PATH_MAX];

    if (dir == NULL) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip '.' and '..'
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);

        if (file_exists(dst_path)) {
            // If destination file exists, check the modification time
            if (get_modification_time(src_path) > get_modification_time(dst_path)) {
                printf("Updating file: %s to %s\n", src_path, dst_path);
                copy_file(src_path, dst_path);
            }
        } else {
            // If the destination file doesn't exist, copy it
            printf("Copying new file: %s to %s\n", src_path, dst_path);
            copy_file(src_path, dst_path);
        }
    }

    closedir(dir);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *src_dir = argv[1];
    const char *dst_dir = argv[2];

    sync_directories(src_dir, dst_dir);
    
    return EXIT_SUCCESS;
}