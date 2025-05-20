//FormAI DATASET v1.0 Category: File Synchronizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PATH_LEN 1024
#define BUF_SIZE 8192

int sync_files(char* source, char* destination);
void sync_recursive(char* source, char* destination);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }

    sync_recursive(argv[1], argv[2]);

    printf("Done!\n");
    return 0;
}

int sync_files(char* source, char* destination) {
    int src_fd, dst_fd;
    char buf[BUF_SIZE];
    ssize_t num_read;

    // Open source file for reading
    src_fd = open(source, O_RDONLY);
    if (src_fd == -1) {
        printf("Failed to open %s for reading: %s\n", source, strerror(errno));
        return 0;
    }

    // Open destination file for writing, creating if it does not exist
    dst_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd == -1) {
        printf("Failed to open %s for writing: %s\n", destination, strerror(errno));
        close(src_fd);
        return 0;
    }

    // Copy data from source to destination
    while ((num_read = read(src_fd, buf, BUF_SIZE)) > 0) {
        if (write(dst_fd, buf, num_read) != num_read) {
            printf("Failed to write all bytes to %s: %s\n", destination, strerror(errno));
            close(src_fd);
            close(dst_fd);
            return 0;
        }
    }

    if (num_read == -1) {
        printf("Failed to read from %s: %s\n", source, strerror(errno));
        close(src_fd);
        close(dst_fd);
        return 0;
    }

    close(src_fd);
    close(dst_fd);
    return 1;
}

void sync_recursive(char* source, char* destination) {
    DIR* source_dir;
    struct dirent* entry;
    char source_path[MAX_PATH_LEN], dest_path[MAX_PATH_LEN];

    source_dir = opendir(source);
    if (source_dir == NULL) {
        printf("Failed to open directory %s: %s\n", source, strerror(errno));
        return;
    }

    // Create destination directory if it does not exist
    if (mkdir(destination, 0755) == -1 && errno != EEXIST) {
        printf("Failed to create directory %s: %s\n", destination, strerror(errno));
        closedir(source_dir);
        return;
    }

    // Traverse source directory and synchronize files
    while ((entry = readdir(source_dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Ignore "." and ".." directories
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // Recursively sync subdirectories
            snprintf(source_path, MAX_PATH_LEN, "%s/%s", source, entry->d_name);
            snprintf(dest_path, MAX_PATH_LEN, "%s/%s", destination, entry->d_name);
            sync_recursive(source_path, dest_path);
        } else {
            // Sync individual files
            snprintf(source_path, MAX_PATH_LEN, "%s/%s", source, entry->d_name);
            snprintf(dest_path, MAX_PATH_LEN, "%s/%s", destination, entry->d_name);
            sync_files(source_path, dest_path);
        }
    }

    closedir(source_dir);
}