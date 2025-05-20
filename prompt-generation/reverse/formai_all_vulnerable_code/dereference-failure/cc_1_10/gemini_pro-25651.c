//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 4096

// Recursive function to synchronize two directories
void sync_dirs(char *src, char *dst) {
    DIR *src_dir, *dst_dir;
    struct dirent *src_ent, *dst_ent;
    struct stat src_stat, dst_stat;
    int src_fd, dst_fd;
    char src_path[1024], dst_path[1024], buf[BUFSIZE];
    int n;

    // Open source directory
    src_dir = opendir(src);
    if (src_dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Create destination directory if it doesn't exist
    dst_dir = opendir(dst);
    if (dst_dir == NULL) {
        if (mkdir(dst, 0755) != 0) {
            perror("mkdir");
            exit(EXIT_FAILURE);
        }
        dst_dir = opendir(dst);
    }

    // Loop through source directory entries
    while ((src_ent = readdir(src_dir)) != NULL) {
        // Skip "." and ".." entries
        if (strcmp(src_ent->d_name, ".") == 0 || strcmp(src_ent->d_name, "..") == 0) {
            continue;
        }

        // Construct source and destination paths
        snprintf(src_path, sizeof(src_path), "%s/%s", src, src_ent->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst, src_ent->d_name);

        // Get source file stats
        if (lstat(src_path, &src_stat) != 0) {
            perror("lstat");
            exit(EXIT_FAILURE);
        }

        // If source is a directory, recursively synchronize it
        if (S_ISDIR(src_stat.st_mode)) {
            sync_dirs(src_path, dst_path);
            continue;
        }

        // Get destination file stats
        if (lstat(dst_path, &dst_stat) != 0) {
            perror("lstat");
            exit(EXIT_FAILURE);
        }

        // If destination file doesn't exist or is older than source file, copy it
        if (dst_stat.st_mtime < src_stat.st_mtime) {
            // Open source file
            src_fd = open(src_path, O_RDONLY);
            if (src_fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }

            // Open/create destination file
            dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, src_stat.st_mode);
            if (dst_fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }

            // Copy file contents
            while ((n = read(src_fd, buf, BUFSIZE)) > 0) {
                write(dst_fd, buf, n);
            }

            if (n == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // Close files
            close(src_fd);
            close(dst_fd);
        }
    }

    // Close directories
    closedir(src_dir);
    closedir(dst_dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sync_dirs(argv[1], argv[2]);

    return 0;
}