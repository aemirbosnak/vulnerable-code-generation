//FormAI DATASET v1.0 Category: File Synchronizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

void copy_file(char *source, char *dest) {
    int src_file, dst_file, error, nread;
    char buf[BUF_SIZE];

    src_file = open(source, O_RDONLY);
    if (src_file == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    dst_file = open(dest, O_WRONLY | O_CREAT, 0644);
    if (dst_file == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while ((nread = read(src_file, buf, BUF_SIZE)) > 0) {
        error = write(dst_file, buf, nread);
        if (error == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    if (nread == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    if (close(src_file) == -1) {
        perror("close src_file");
        exit(EXIT_FAILURE);
    }

    if (close(dst_file) == -1) {
        perror("close dst_file");
        exit(EXIT_FAILURE);
    }
}

void copy_dir(char *source, char *dest) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    char src_path[BUF_SIZE];
    char dst_path[BUF_SIZE];

    dp = opendir(source);
    if (dp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        sprintf(src_path, "%s/%s", source, entry->d_name);
        sprintf(dst_path, "%s/%s", dest, entry->d_name);

        if (lstat(src_path, &statbuf) == -1) {
            perror("lstat");
            exit(EXIT_FAILURE);
        }

        if (S_ISREG(statbuf.st_mode)) {
            if (access(dst_path, F_OK) == -1) {
                copy_file(src_path, dst_path);
            } else {
                if (stat(src_path, &statbuf) == -1) {
                    perror("stat");
                    exit(EXIT_FAILURE);
                }

                if (stat(dst_path, &statbuf) == -1) {
                    perror("stat");
                    exit(EXIT_FAILURE);
                }

                if (statbuf.st_mtime > statbuf.st_mtime) {
                    copy_file(src_path, dst_path);
                }
            }
        } else if (S_ISDIR(statbuf.st_mode)) {
            if (access(dst_path, F_OK) == -1) {
                if (mkdir(dst_path, 0755) == -1) {
                    perror("mkdir");
                    exit(EXIT_FAILURE);
                }

                copy_dir(src_path, dst_path);
            } else {
                copy_dir(src_path, dst_path);
            }
        }
    }

    if (closedir(dp) == -1) {
        perror("closedir");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_dir dest_dir\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], argv[2]) == 0) {
        fprintf(stderr, "Source and destination directories cannot be the same\n");
        exit(EXIT_FAILURE);
    }

    copy_dir(argv[1], argv[2]);
    printf("Synchronization complete\n");
    exit(EXIT_SUCCESS);
}