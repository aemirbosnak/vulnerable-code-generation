//FormAI DATASET v1.0 Category: File Synchronizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 1024

// Function to check if directory exists
bool dir_exists(const char *path) {
    DIR *dir = opendir(path);
    if (dir) {
        closedir(dir);
        return true;
    } else {
        return false;
    }
}

// Function to copy file from source to destination path
void copy_file(const char *src_path, const char *dest_path) {
    int src_fd = open(src_path, O_RDONLY);
    int dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0666);

    char buf[BUF_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(src_fd, buf, BUF_SIZE)) > 0) {
        write(dest_fd, buf, bytes_read);
    }

    close(src_fd);
    close(dest_fd);
}

// Function to synchronize directories recursively
void sync_dir(const char *src_dir, const char *dest_dir) {
    DIR *src_dp = opendir(src_dir);
    struct dirent *src_entry;

    // Traverse source directory
    while ((src_entry = readdir(src_dp))) {
        if (strcmp(src_entry->d_name, ".") == 0 || strcmp(src_entry->d_name, "..") == 0) {
            continue;
        }

        // Build source and destination paths
        char src_path[1024];
        sprintf(src_path, "%s/%s", src_dir, src_entry->d_name);

        char dest_path[1024];
        sprintf(dest_path, "%s/%s", dest_dir, src_entry->d_name);

        // Check if source is a directory
        struct stat src_stat;
        stat(src_path, &src_stat);
        if (S_ISDIR(src_stat.st_mode)) {
            // If destination directory does not exist, create it recursively
            if (!dir_exists(dest_path)) {
                mkdir(dest_path, 0777);
            }
            sync_dir(src_path, dest_path);
        } else {
            // If destination file does not exist or is out of date, copy it
            struct stat dest_stat;
            if (stat(dest_path, &dest_stat) != 0 || src_stat.st_mtime > dest_stat.st_mtime) {
                copy_file(src_path, dest_path);
            }
        }
    }

    closedir(src_dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [source_dir] [destination_dir]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *src_dir = argv[1];
    char *dest_dir = argv[2];

    if (!dir_exists(src_dir)) {
        printf("Source directory does not exist.\n");
        exit(EXIT_FAILURE);
    }

    if (!dir_exists(dest_dir)) {
        printf("Destination directory does not exist. Creating directory %s...\n", dest_dir);
        mkdir(dest_dir, 0777);
    }

    sync_dir(src_dir, dest_dir);

    printf("Synchronization complete!\n");

    return 0;
}