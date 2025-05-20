//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <utime.h>
#include <errno.h>

#define MAX_PATH_LEN 1024

void copy_file(const char *src, const char *dst) {
    int src_fd, dst_fd;
    char buf[BUFSIZ];
    ssize_t nread;

    src_fd = open(src, O_RDONLY);
    if (src_fd < 0) {
        perror("open");
        exit(1);
    }

    dst_fd = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd < 0) {
        perror("open");
        exit(1);
    }

    while ((nread = read(src_fd, buf, sizeof(buf))) > 0) {
        if (write(dst_fd, buf, nread) != nread) {
            perror("write");
            exit(1);
        }
    }

    if (nread < 0) {
        perror("read");
        exit(1);
    }

    close(src_fd);
    close(dst_fd);
}

void copy_dir(const char *src, const char *dst) {
    DIR *dir;
    struct dirent *entry;
    char src_path[MAX_PATH_LEN], dst_path[MAX_PATH_LEN];

    dir = opendir(src);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    if (mkdir(dst, 0755) < 0) {
        perror("mkdir");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst, entry->d_name);

        if (entry->d_type == DT_DIR) {
            copy_dir(src_path, dst_path);
        } else {
            copy_file(src_path, dst_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <src> <dst>\n", argv[0]);
        exit(1);
    }

    copy_dir(argv[1], argv[2]);

    return 0;
}