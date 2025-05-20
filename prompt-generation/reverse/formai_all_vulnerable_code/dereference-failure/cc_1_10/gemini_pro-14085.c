//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 4096

struct file_info {
    char *path;
    off_t size;
    time_t mtime;
};

int compare_files(struct file_info *file1, struct file_info *file2) {
    if (file1->size != file2->size) {
        return 0;
    }

    if (file1->mtime != file2->mtime) {
        return 0;
    }

    return 1;
}

void sync_files(char *src_path, char *dst_path) {
    int src_fd, dst_fd;
    char *buf = malloc(BUF_SIZE);

    if ((src_fd = open(src_path, O_RDONLY)) == -1) {
        perror("open");
        return;
    }

    if ((dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
        perror("open");
        return;
    }

    while (1) {
        int n = read(src_fd, buf, BUF_SIZE);
        if (n == -1) {
            perror("read");
            break;
        }

        if (n == 0) {
            break;
        }

        if (write(dst_fd, buf, n) == -1) {
            perror("write");
            break;
        }
    }

    close(src_fd);
    close(dst_fd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src_path> <dst_path>\n", argv[0]);
        return 1;
    }

    struct file_info src_file, dst_file;

    if (stat(argv[1], &src_file) == -1) {
        perror("stat");
        return 1;
    }

    if (stat(argv[2], &dst_file) == -1) {
        perror("stat");
        return 1;
    }

    if (compare_files(&src_file, &dst_file)) {
        printf("Files are up to date.\n");
        return 0;
    }

    printf("Syncing files...\n");
    sync_files(argv[1], argv[2]);

    printf("Files synced successfully.\n");
    return 0;
}