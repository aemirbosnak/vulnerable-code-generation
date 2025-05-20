//FormAI DATASET v1.0 Category: File Backup System ; Style: realistic
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

void backup_file(const char* src_path, const char* dst_path) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    int src_fd = open(src_path, O_RDONLY);
    if (src_fd == -1) {
        perror("Failed to open source file");
        exit(EXIT_FAILURE);
    }
    int dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd == -1) {
        perror("Failed to open destination file");
        exit(EXIT_FAILURE);
    }
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        ssize_t bytes_written = write(dst_fd, buffer, (size_t) bytes_read);
        if (bytes_written != bytes_read) {
            fprintf(stderr, "Failed to write to destination file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
    if (bytes_read == -1) {
        perror("Failed to read source file");
        exit(EXIT_FAILURE);
    }
    if (close(src_fd) == -1) {
        perror("Failed to close source file");
        exit(EXIT_FAILURE);
    }
    if (close(dst_fd) == -1) {
        perror("Failed to close destination file");
        exit(EXIT_FAILURE);
    }
}

void backup_dir(const char* src_path, const char* dst_path) {
    DIR* src_dir = opendir(src_path);
    if (src_dir == NULL) {
        perror("Failed to open source directory");
        exit(EXIT_FAILURE);
    }
    int dst_dir_fd = open(dst_path, O_RDONLY | O_DIRECTORY);
    if (dst_dir_fd == -1) {
        if (errno == ENOENT) {
            if (mkdir(dst_path, 0755) == -1) {
                perror("Failed to create destination directory");
                exit(EXIT_FAILURE);
            }
            dst_dir_fd = open(dst_path, O_RDONLY | O_DIRECTORY);
            if (dst_dir_fd == -1) {
                perror("Failed to open destination directory");
                exit(EXIT_FAILURE);
            }
        } else {
            perror("Failed to open destination directory");
            exit(EXIT_FAILURE);
        }
    }
    struct dirent* dp;
    while ((dp = readdir(src_dir))) {
        if (dp->d_type == DT_REG) {
            char src_file_path[PATH_MAX];
            snprintf(src_file_path, PATH_MAX, "%s/%s", src_path, dp->d_name);
            char dst_file_path[PATH_MAX];
            snprintf(dst_file_path, PATH_MAX, "%s/%s", dst_path, dp->d_name);
            backup_file(src_file_path, dst_file_path);
            printf("Backed up file %s to %s\n", src_file_path, dst_file_path);
        } else if (dp->d_type == DT_DIR) {
            if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
                char src_subdir_path[PATH_MAX];
                snprintf(src_subdir_path, PATH_MAX, "%s/%s", src_path, dp->d_name);
                char dst_subdir_path[PATH_MAX];
                snprintf(dst_subdir_path, PATH_MAX, "%s/%s", dst_path, dp->d_name);
                backup_dir(src_subdir_path, dst_subdir_path);
            }
        }
    }
    if (closedir(src_dir) == -1) {
        perror("Failed to close source directory");
        exit(EXIT_FAILURE);
    }
    if (close(dst_dir_fd) == -1) {
        perror("Failed to close destination directory");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    backup_dir(argv[1], argv[2]);
    printf("Backup complete\n");
    return 0;
}