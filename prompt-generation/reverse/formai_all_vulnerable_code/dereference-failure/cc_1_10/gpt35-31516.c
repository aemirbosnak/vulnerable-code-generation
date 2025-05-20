//FormAI DATASET v1.0 Category: File Synchronizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <openssl/md5.h>

#define BUFSIZE 1024
#define MD5SIZE 16

int md5sum(char *filename, unsigned char *digest) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return -1;
    }

    MD5_CTX context;
    MD5_Init(&context);

    unsigned char buffer[BUFSIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, BUFSIZE)) > 0) {
        MD5_Update(&context, buffer, bytes_read);
    }

    MD5_Final(digest, &context);
    close(fd);
    return 0;
}

int copy_file(char *src, char *dst) {
    unsigned char buffer[BUFSIZE];
    int bytes_read, bytes_written;
    int src_fd = open(src, O_RDONLY);
    if (src_fd < 0) return -1;

    int dst_fd = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd < 0) return -1;

    while ((bytes_read = read(src_fd, buffer, BUFSIZE)) > 0) {
        bytes_written = write(dst_fd, buffer, bytes_read);
        if (bytes_written < 0) return -1;
        if (bytes_written != bytes_read) return -1;
    }

    close(src_fd);
    close(dst_fd);

    return 0;
}

void sync_files(char *src_dir, char *dst_dir) {
    DIR *src_dp = opendir(src_dir);
    if (src_dp == NULL) {
        perror(src_dir);
        return;
    }

    DIR *dst_dp = opendir(dst_dir);
    if (dst_dp == NULL) {
        perror(dst_dir);
        closedir(src_dp);
        return;
    }

    struct dirent *src_entry, *dst_entry;
    char src_path[BUFSIZE], dst_path[BUFSIZE];
    while ((src_entry = readdir(src_dp)) != NULL) {
        if (src_entry->d_name[0] == '.') continue;
        snprintf(src_path, BUFSIZE, "%s/%s", src_dir, src_entry->d_name);

        dst_entry = NULL;
        while ((dst_entry = readdir(dst_dp)) != NULL) {
            if (dst_entry->d_name[0] == '.') continue;
            snprintf(dst_path, BUFSIZE, "%s/%s", dst_dir, dst_entry->d_name);

            if (strcasecmp(src_entry->d_name, dst_entry->d_name) == 0) break;
        }

        if (dst_entry) {
            struct stat src_stat, dst_stat;
            if ((stat(src_path, &src_stat) == 0) && (stat(dst_path, &dst_stat) == 0)) {
                if (src_stat.st_mtime > dst_stat.st_mtime) {
                    unsigned char src_digest[MD5SIZE], dst_digest[MD5SIZE];
                    md5sum(src_path, src_digest);
                    md5sum(dst_path, dst_digest);
                    if (memcmp(src_digest, dst_digest, MD5SIZE)) {
                        printf("Syncing %s to %s\n", src_path, dst_path);
                        if (copy_file(src_path, dst_path) == 0) {
                            printf("Synced %s to %s\n", src_path, dst_path);
                        } else {
                            fprintf(stderr, "Error syncing %s to %s: %s\n", src_path, dst_path, strerror(errno));
                        }
                    }
                }
            }
        } else {
            printf("Copying %s to %s\n", src_path, dst_dir);
            if (copy_file(src_path, dst_dir) == 0) {
                printf("Copied %s to %s\n", src_path, dst_dir);
            } else {
                fprintf(stderr, "Error copying %s to %s: %s\n", src_path, dst_dir, strerror(errno));
            }
        }
        rewinddir(dst_dp);
    }

    closedir(src_dp);
    closedir(dst_dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }
    char *src_dir = argv[1], *dst_dir = argv[2];

    while (1) {
        sync_files(src_dir, dst_dir);
        sleep(10);
    }

    return 0;
}