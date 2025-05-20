//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

typedef struct {
    int fd;
    char *path;
    size_t size;
    char *buf;
} File;

static File files[100];
static int num_files = 0;

static int open_file(const char *path) {
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }
    return fd;
}

static char *read_file(int fd, size_t *size) {
    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        return NULL;
    }
    char *buf = malloc(st.st_size);
    if (buf == NULL) {
        perror("malloc");
        return NULL;
    }
    *size = st.st_size;
    if (read(fd, buf, *size) != *size) {
        perror("read");
        free(buf);
        return NULL;
    }
    return buf;
}

static void close_file(File *file) {
    if (file->fd != -1) {
        close(file->fd);
        file->fd = -1;
    }
    if (file->buf != NULL) {
        free(file->buf);
        file->buf = NULL;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file> [<file> ...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        int fd = open_file(argv[i]);
        if (fd == -1) {
            return EXIT_FAILURE;
        }
        size_t size;
        char *buf = read_file(fd, &size);
        if (buf == NULL) {
            close_file(&files[num_files]);
            return EXIT_FAILURE;
        }
        files[num_files].fd = fd;
        files[num_files].path = strdup(argv[i]);
        files[num_files].size = size;
        files[num_files].buf = buf;
        num_files++;
    }

    for (int i = 0; i < num_files; i++) {
        char *backup_path = malloc(strlen(files[i].path) + 5);
        if (backup_path == NULL) {
            perror("malloc");
            return EXIT_FAILURE;
        }
        strcpy(backup_path, files[i].path);
        strcat(backup_path, ".bak");
        int fd = open(backup_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) {
            perror("open");
            free(backup_path);
            return EXIT_FAILURE;
        }
        if (write(fd, files[i].buf, files[i].size) != files[i].size) {
            perror("write");
            close(fd);
            free(backup_path);
            return EXIT_FAILURE;
        }
        close(fd);
        free(backup_path);
    }

    for (int i = 0; i < num_files; i++) {
        close_file(&files[i]);
    }

    return EXIT_SUCCESS;
}