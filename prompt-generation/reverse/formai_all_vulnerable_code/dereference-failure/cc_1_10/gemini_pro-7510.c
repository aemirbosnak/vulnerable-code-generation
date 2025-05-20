//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: invasive
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define BUF_SIZE 4096
#define MAX_PATHNAME_LEN PATH_MAX

static int
copy_file(const char *src_path, const char *dst_path)
{
    int src_fd, dst_fd;
    struct stat src_stat;
    char buf[BUF_SIZE];
    ssize_t n;

    src_fd = open(src_path, O_RDONLY);
    if (src_fd < 0) {
        perror("open");
        return -1;
    }

    dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd < 0) {
        perror("open");
        close(src_fd);
        return -1;
    }

    if (fstat(src_fd, &src_stat) < 0) {
        perror("fstat");
        close(src_fd);
        close(dst_fd);
        return -1;
    }

    while ((n = read(src_fd, buf, sizeof(buf))) > 0) {
        if (write(dst_fd, buf, n) < 0) {
            perror("write");
            close(src_fd);
            close(dst_fd);
            return -1;
        }
    }

    if (n < 0) {
        perror("read");
        close(src_fd);
        close(dst_fd);
        return -1;
    }

    if (fchown(dst_fd, src_stat.st_uid, src_stat.st_gid) < 0) {
        perror("fchown");
        close(src_fd);
        close(dst_fd);
        return -1;
    }

    if (fchmod(dst_fd, src_stat.st_mode) < 0) {
        perror("fchmod");
        close(src_fd);
        close(dst_fd);
        return -1;
    }

    close(src_fd);
    close(dst_fd);

    return 0;
}

static int
copy_dir(const char *src_dir, const char *dst_dir)
{
    DIR *src_dirp;
    struct dirent *src_dirent;
    char src_path[MAX_PATHNAME_LEN];
    char dst_path[MAX_PATHNAME_LEN];
    int rc;

    src_dirp = opendir(src_dir);
    if (src_dirp == NULL) {
        perror("opendir");
        return -1;
    }

    while ((src_dirent = readdir(src_dirp)) != NULL) {
        if (strcmp(src_dirent->d_name, ".") == 0 ||
            strcmp(src_dirent->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, src_dirent->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, src_dirent->d_name);

        if (src_dirent->d_type == DT_REG) {
            if (copy_file(src_path, dst_path) < 0) {
                rc = -1;
                goto out;
            }
        } else if (src_dirent->d_type == DT_DIR) {
            if (mkdir(dst_path, 0755) < 0) {
                perror("mkdir");
                rc = -1;
                goto out;
            }

            if (copy_dir(src_path, dst_path) < 0) {
                rc = -1;
                goto out;
            }
        } else {
            fprintf(stderr, "unsupported file type: %s\n", src_dirent->d_name);
            rc = -1;
            goto out;
        }
    }

    rc = 0;

out:
    closedir(src_dirp);

    return rc;
}

int
main(int argc, char *argv[])
{
    char dst_dir[MAX_PATHNAME_LEN];
    char *src_dir;
    time_t start_time;
    time_t end_time;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <src-dir> <dst-dir>\n", argv[0]);
        return EXIT_FAILURE;
    }

    src_dir = argv[1];
    snprintf(dst_dir, sizeof(dst_dir), "%s.backup", argv[2]);

    start_time = time(NULL);

    if (copy_dir(src_dir, dst_dir) < 0) {
        fprintf(stderr, "failed to backup directory\n");
        return EXIT_FAILURE;
    }

    end_time = time(NULL);

    printf("backup completed in %ld seconds\n", end_time - start_time);

    return EXIT_SUCCESS;
}