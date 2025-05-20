//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

#define BUFFSIZE 1024

static size_t file_copy(const char *src, const char *dst, mode_t mode)
{
    int fdr, fdw;
    char buf[BUFFSIZE];
    ssize_t nread, nwritten;
    size_t total_nwritten = 0;

    fdr = open(src, O_RDONLY);
    if (fdr < 0) {
        perror("open");
        return (size_t)-1;
    }

    fdw = open(dst, O_WRONLY | O_CREAT | O_TRUNC, mode);
    if (fdw < 0) {
        perror("open");
        close(fdr);
        return (size_t)-1;
    }

    while ((nread = read(fdr, buf, BUFFSIZE)) > 0) {
        nwritten = write(fdw, buf, nread);
        if (nwritten != nread) {
            perror("write");
            close(fdr);
            close(fdw);
            return (size_t)-1;
        }
        total_nwritten += nwritten;
    }

    if (nread < 0) {
        perror("read");
        close(fdr);
        close(fdw);
        return (size_t)-1;
    }

    close(fdr);
    close(fdw);
    return total_nwritten;
}

static int directory_copy(const char *src, const char *dst, mode_t mode)
{
    DIR *dp;
    struct dirent *dir;
    struct stat st;
    char buf[BUFFSIZE];
    int err;

    if ((err = stat(src, &st)) < 0) {
        perror("stat");
        return err;
    }

    if (!(S_ISDIR(st.st_mode))) {
        errno = ENOTDIR;
        return -1;
    }

    if ((err = mkdir(dst, mode)) < 0) {
        perror("mkdir");
        return err;
    }

    if ((dp = opendir(src)) == NULL) {
        perror("opendir");
        return -1;
    }

    while ((dir = readdir(dp)) != NULL) {
        if (!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."))
            continue;

        snprintf(buf, BUFFSIZE, "%s/%s", src, dir->d_name);
        snprintf(buf + strlen(buf), BUFFSIZE - strlen(buf), "/%s", dst);

        if (dir->d_type == DT_DIR) {
            if ((err = directory_copy(buf, buf + strlen(buf), mode)) < 0)
                goto error;
        } else if (dir->d_type == DT_REG) {
            if (file_copy(buf, buf + strlen(buf), mode) < 0)
                goto error;
        }
    }

    closedir(dp);
    return 0;

error:
    closedir(dp);
    return err;
}

int main(int argc, char **argv)
{
    struct stat st;
    mode_t mode;
    int err;

    if (argc < 3) {
        fprintf(stderr, "usage: %s source destination\n", argv[0]);
        return -1;
    }

    if ((err = stat(argv[1], &st)) < 0) {
        perror("stat");
        return err;
    }

    if (S_ISDIR(st.st_mode)) {
        const char *suffix = "/backup";
        char buf[BUFFSIZE];

        snprintf(buf, BUFFSIZE, "%s%s", argv[2], suffix);
        mode = (st.st_mode & ~S_IXUSR) | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

        if ((err = directory_copy(argv[1], buf, mode)) < 0) {
            perror("directory_copy");
            return err;
        }
    } else if (S_ISREG(st.st_mode)) {
        mode = (st.st_mode & ~S_IXUSR) | S_IRUSR | S_IWUSR;

        if (file_copy(argv[1], argv[2], mode) < 0) {
            perror("file_copy");
            return -1;
        }
    } else {
        errno = ENOTSUP;
        perror("source is neither a file nor a directory");
    }

    return 0;
}