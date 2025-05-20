//LLAMA2-13B DATASET v1.0 Category: File system simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BLOCK_SIZE 512
#define MAX_FILE_SIZE 1024 * 1024

struct file {
    char *name;
    size_t size;
    off_t offset;
    int fd;
};

struct inode {
    char *name;
    mode_t mode;
    uid_t uid;
    gid_t gid;
    size_t block_size;
    size_t file_size;
    struct file *files[10];
};

void init_inode(struct inode *i) {
    memset(i, 0, sizeof(struct inode));
}

struct file *create_file(const char *name, size_t size, mode_t mode) {
    struct file *f = malloc(sizeof(struct file));
    f->name = strdup(name);
    f->size = size;
    f->offset = 0;
    f->fd = -1;
    return f;
}

int open_file(struct file *f) {
    int fd = open(f->name, O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return -1;
    }
    f->fd = fd;
    return 0;
}

int read_file(struct file *f, char *buf, size_t size) {
    size_t left = f->size - f->offset;
    if (left > size) {
        left = size;
    }
    ssize_t ret = read(f->fd, buf, left);
    if (ret < 0) {
        perror("read");
        return -1;
    }
    f->offset += ret;
    return ret;
}

int write_file(struct file *f, char *buf, size_t size) {
    size_t left = f->size - f->offset;
    if (left > size) {
        left = size;
    }
    ssize_t ret = write(f->fd, buf, left);
    if (ret < 0) {
        perror("write");
        return -1;
    }
    f->offset += ret;
    return ret;
}

int unlink_file(struct file *f) {
    if (unlink(f->name) < 0) {
        perror("unlink");
        return -1;
    }
    free(f->name);
    free(f);
    return 0;
}

int mkdir_p(const char *path) {
    char *ptr = path;
    while (*ptr != '/') {
        ptr++;
    }
    char *dir = malloc(ptr - path);
    memcpy(dir, path, ptr - path);
    dir[ptr - path] = '\0';
    if (mkdir(dir, 0755) < 0) {
        perror("mkdir");
        free(dir);
        return -1;
    }
    free(dir);
    return 0;
}

int main() {
    struct inode *i = malloc(sizeof(struct inode));
    init_inode(i);
    char *name = "/hello";
    size_t size = 1024;
    mode_t mode = 0644;
    struct file *f = create_file(name, size, mode);
    if (open_file(f) < 0) {
        perror("open");
        return -1;
    }
    char *buf = malloc(size);
    for (size_t i = 0; i < size; i++) {
        buf[i] = 'h';
    }
    size_t ret = write_file(f, buf, size);
    if (ret < 0) {
        perror("write");
        return -1;
    }
    ret = read_file(f, buf, size);
    if (ret < 0) {
        perror("read");
        return -1;
    }
    for (size_t i = 0; i < size; i++) {
        if (buf[i] != 'h') {
            printf("error: %c\n", buf[i]);
            return -1;
        }
    }
    unlink_file(f);
    return 0;
}