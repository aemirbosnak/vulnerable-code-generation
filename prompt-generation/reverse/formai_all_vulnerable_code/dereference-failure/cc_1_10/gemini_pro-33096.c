//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>
#include <dirent.h>
#include <signal.h>
#include <time.h>

#define BUFF_SIZE 1024

typedef struct {
    char *src_path;
    char *dst_path;
    int fd_src;
    int fd_dst;
    off_t offset;
    size_t size;
} file_info_t;

static void sig_handler(int signo) {
    exit(EXIT_SUCCESS);
}

static int copy_file(file_info_t *info) {
    char buff[BUFF_SIZE];
    ssize_t bytes_read, bytes_written;
    int err;

    while (info->offset < info->size) {
        bytes_read = read(info->fd_src, buff, BUFF_SIZE);
        if (bytes_read == -1) {
            err = errno;
            perror("read");
            return err;
        }

        bytes_written = write(info->fd_dst, buff, bytes_read);
        if (bytes_written == -1) {
            err = errno;
            perror("write");
            return err;
        }

        info->offset += bytes_written;
    }

    return 0;
}

static int backup_file(file_info_t *info) {
    int err;

    info->fd_src = open(info->src_path, O_RDONLY);
    if (info->fd_src == -1) {
        err = errno;
        perror("open");
        return err;
    }

    info->fd_dst = open(info->dst_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (info->fd_dst == -1) {
        err = errno;
        perror("open");
        return err;
    }

    info->size = lseek(info->fd_src, 0, SEEK_END);
    if (info->size == -1) {
        err = errno;
        perror("lseek");
        return err;
    }

    err = copy_file(info);
    if (err) {
        return err;
    }

    return 0;
}

static int backup_directory(file_info_t *info) {
    DIR *dir;
    struct dirent *entry;
    file_info_t new_info;
    int err;

    dir = opendir(info->src_path);
    if (dir == NULL) {
        err = errno;
        perror("opendir");
        return err;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        new_info.src_path = malloc(strlen(info->src_path) + strlen(entry->d_name) + 2);
        if (new_info.src_path == NULL) {
            err = ENOMEM;
            perror("malloc");
            return err;
        }

        strcpy(new_info.src_path, info->src_path);
        strcat(new_info.src_path, "/");
        strcat(new_info.src_path, entry->d_name);

        new_info.dst_path = malloc(strlen(info->dst_path) + strlen(entry->d_name) + 2);
        if (new_info.dst_path == NULL) {
            err = ENOMEM;
            perror("malloc");
            return err;
        }

        strcpy(new_info.dst_path, info->dst_path);
        strcat(new_info.dst_path, "/");
        strcat(new_info.dst_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            err = backup_directory(&new_info);
            if (err) {
                return err;
            }
        } else if (entry->d_type == DT_REG) {
            err = backup_file(&new_info);
            if (err) {
                return err;
            }
        }

        free(new_info.src_path);
        free(new_info.dst_path);
    }

    closedir(dir);

    return 0;
}

int main(int argc, char *argv[]) {
    file_info_t info;
    char *src_dir, *dst_dir;
    int err;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src_dir> <dst_dir>\n", argv[0]);
        return EXIT_FAILURE;
    }

    src_dir = argv[1];
    dst_dir = argv[2];

    info.src_path = src_dir;
    info.dst_path = dst_dir;

    signal(SIGINT, sig_handler);

    err = backup_directory(&info);
    if (err) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}