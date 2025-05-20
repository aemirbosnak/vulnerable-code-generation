//FormAI DATASET v1.0 Category: File Synchronizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define BUF_SIZE 1024

int check_directory(char *dir_path);
int file_sync(char *src, char *dst);
int sync_directories(char *src, char *dst);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [source_directory] [destination_directory]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (!check_directory(argv[1])) {
        fprintf(stderr, "%s is not a valid directory.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (!check_directory(argv[2])) {
        fprintf(stderr, "%s is not a valid directory.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    if (sync_directories(argv[1], argv[2]) == -1) {
        fprintf(stderr, "Failed to synchronize directories.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

int check_directory(char *dir_path) {
    DIR *dir;
    if ((dir = opendir(dir_path)) != NULL) {
        closedir(dir);
        return 1;
    } else {
        return 0;
    }
}

int file_sync(char *src, char *dst) {
    int src_fd, dst_fd, read_bytes, write_bytes, total_bytes = 0;
    char buf[BUF_SIZE];
    struct stat src_stat, dst_stat;
    time_t src_mtime, dst_mtime;

    if ((src_fd = open(src, O_RDONLY)) == -1) {
        perror("open");
        return -1;
    }

    if ((fstat(src_fd, &src_stat)) == -1) {
        perror("fstat");
        return -1;
    }
    src_mtime = src_stat.st_mtime;

    if ((dst_fd = open(dst, O_WRONLY | O_TRUNC | O_CREAT, src_stat.st_mode)) == -1) {
        perror("open");
        return -1;
    }

    if ((fstat(dst_fd, &dst_stat)) == -1) {
        perror("fstat");
        return -1;
    }
    dst_mtime = dst_stat.st_mtime;

    if (difftime(src_mtime, dst_mtime) > 0) {
        while ((read_bytes = read(src_fd, buf, BUF_SIZE)) > 0) {
            write_bytes = write(dst_fd, buf, read_bytes);
            if (write_bytes != read_bytes) {
                perror("write");
                return -1;
            }
            total_bytes += write_bytes;
        }

        if (read_bytes == -1) {
            perror("read");
            return -1;
        }

        printf("%d bytes copied from %s to %s.\n", total_bytes, src, dst);
    }

    close(src_fd);
    close(dst_fd);

    return 0;
}

int sync_directories(char *src, char *dst) {
    DIR *src_dir, *dst_dir;
    struct dirent *src_entry;
    char src_path[PATH_MAX + 1], dst_path[PATH_MAX + 1];

    if ((src_dir = opendir(src)) == NULL) {
        perror("opendir");
        return -1;
    }

    if ((dst_dir = opendir(dst)) == NULL) {
        perror("opendir");
        closedir(src_dir);
        return -1;
    }

    while ((src_entry = readdir(src_dir)) != NULL) {
        if (strcmp(src_entry->d_name, ".") == 0 || strcmp(src_entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_path, PATH_MAX + 1, "%s/%s", src, src_entry->d_name);
        snprintf(dst_path, PATH_MAX + 1, "%s/%s", dst, src_entry->d_name);

        if (src_entry->d_type == DT_DIR) {
            if (mkdir(dst_path, S_IRWXU) == -1 && errno != EEXIST) {
                perror("mkdir");
                closedir(src_dir);
                closedir(dst_dir);
                return -1;
            }
            if (sync_directories(src_path, dst_path) == -1) {
                closedir(src_dir);
                closedir(dst_dir);
                return -1;
            }
        } else if (src_entry->d_type == DT_REG) {
            if (file_sync(src_path, dst_path) == -1) {
                closedir(src_dir);
                closedir(dst_dir);
                return -1;
            }
        }
    }

    closedir(src_dir);
    closedir(dst_dir);

    return 0;
}