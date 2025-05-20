//FormAI DATASET v1.0 Category: File Synchronizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

/* A surreal C File Synchronizer */

#define BUFFER_SIZE 1024
#define INTERVAL 10

/* A function to synchronize two files */
void sync_files(const char *src_path, const char *dst_path) {
    char buffer[BUFFER_SIZE];
    int src_fd, dst_fd, num_bytes;
    src_fd = open(src_path, O_RDONLY);
    if (src_fd == -1) {
        fprintf(stderr, "Error opening source file %s: %s\n", src_path, strerror(errno));
        return;
    }
    dst_fd = open(dst_path, O_WRONLY);
    if (dst_fd == -1) {
        fprintf(stderr, "Error opening destination file %s: %s\n", dst_path, strerror(errno));
        close(src_fd);
        return;
    }
    while ((num_bytes = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dst_fd, buffer, num_bytes) != num_bytes) {
            fprintf(stderr, "Error writing to file %s: %s\n", dst_path, strerror(errno));
            break;
        }
    }
    if (num_bytes == -1) {
        fprintf(stderr, "Error reading from file %s: %s\n", src_path, strerror(errno));
    }
    close(src_fd);
    close(dst_fd);
}

/* A recursive function to synchronize directories */
void sync_dirs(const char *src_path, const char *dst_path) {
    DIR *src_dir, *dst_dir;
    struct dirent *src_ent, *dst_ent;
    struct stat src_stat, dst_stat;
    char src_pathname[PATH_MAX], dst_pathname[PATH_MAX];
    src_dir = opendir(src_path);
    if (!src_dir) {
        fprintf(stderr, "Error opening source directory %s: %s\n", src_path, strerror(errno));
        return;
    }
    dst_dir = opendir(dst_path);
    if (!dst_dir) {
        fprintf(stderr, "Error opening destination directory %s: %s\n", dst_path, strerror(errno));
        closedir(src_dir);
        return;
    }
    while ((src_ent = readdir(src_dir))) {
        dst_ent = readdir(dst_dir);
        if (!dst_ent) {
            switch (errno) {
                case EBADF:
                    fprintf(stderr, "Error reading from destination directory %s: bad file descriptor\n", dst_path);
                    break;
                case EIO:
                    fprintf(stderr, "Error reading from destination directory %s: I/O error\n", dst_path);
                    break;
                case ENOMEM:
                    fprintf(stderr, "Error reading from destination directory %s: out of memory\n", dst_path);
                    break;
                case EOVERFLOW:
                    fprintf(stderr, "Error reading from destination directory %s: value too large for defined data type\n", dst_path);
                    break;
                default:
                    fprintf(stderr, "Error reading from destination directory %s: unknown error\n", dst_path);
                    break;
            }
            break;
        }
        if (src_ent->d_type == DT_DIR && strcmp(src_ent->d_name, ".") && strcmp(src_ent->d_name, "..")) {
            snprintf(src_pathname, PATH_MAX, "%s/%s", src_path, src_ent->d_name);
            if (lstat(src_pathname, &src_stat)) {
                fprintf(stderr, "Error getting status of source directory %s/%s: %s\n", src_path, src_ent->d_name, strerror(errno));
                continue;
            }
            snprintf(dst_pathname, PATH_MAX, "%s/%s", dst_path, dst_ent->d_name);
            if (lstat(dst_pathname, &dst_stat)) {
                fprintf(stderr, "Error getting status of destination directory %s/%s: %s\n", dst_path, dst_ent->d_name, strerror(errno));
                continue;
            }
            if (S_ISDIR(src_stat.st_mode) != S_ISDIR(dst_stat.st_mode)) {
                fprintf(stderr, "Error synchronizing directory %s and directory %s: not of the same type\n", src_pathname, dst_pathname);
                continue;
            }
            sync_dirs(src_pathname, dst_pathname);
        } else if (src_ent->d_type == DT_REG) {
            snprintf(src_pathname, PATH_MAX, "%s/%s", src_path, src_ent->d_name);
            snprintf(dst_pathname, PATH_MAX, "%s/%s", dst_path, dst_ent->d_name);
            sync_files(src_pathname, dst_pathname);
        }
    }
    while ((dst_ent = readdir(dst_dir))) {
        if (dst_ent->d_type == DT_DIR) {
            snprintf(dst_pathname, PATH_MAX, "%s/%s", dst_path, dst_ent->d_name);
            fprintf(stderr, "Directory %s does not exist in source directory %s, deleting...\n", dst_pathname, src_path);
            if (rmdir(dst_pathname)) {
                fprintf(stderr, "Error deleting directory %s: %s\n", dst_pathname, strerror(errno));
            }
        } else if (dst_ent->d_type == DT_REG) {
            snprintf(dst_pathname, PATH_MAX, "%s/%s", dst_path, dst_ent->d_name);
            fprintf(stderr, "File %s does not exist in source directory %s, deleting...\n", dst_pathname, src_path);
            if (unlink(dst_pathname)) {
                fprintf(stderr, "Error deleting file %s: %s\n", dst_pathname, strerror(errno));
            }
        }
    }
    closedir(src_dir);
    closedir(dst_dir);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s SOURCE DESTINATION\n", argv[0]);
        return 1;
    }
    while (1) {
        sync_dirs(argv[1], argv[2]);
        sleep(INTERVAL);
    }
    return 0;
}