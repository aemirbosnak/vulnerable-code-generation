//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUF_SIZE 1024

typedef struct {
    int fd;
    char *path;
    int mode;
} file_t;

void sync_file(file_t *file) {
    char buf[BUF_SIZE];
    ssize_t nbytes;

    while ((nbytes = read(file->fd, buf, BUF_SIZE)) > 0) {
        write(file->fd, buf, nbytes);
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source destination\n", argv[0]);
        exit(1);
    }

    file_t source = {0};
    file_t destination = {0};

    source.fd = open(argv[1], O_RDONLY);
    if (source.fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    destination.fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destination.fd == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        exit(1);
    }

    source.path = argv[1];
    destination.path = argv[2];

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        sync_file(&source);
        close(source.fd);
        exit(0);
    } else if (pid > 0) {
        // Parent process
        sync_file(&destination);
        close(destination.fd);
        waitpid(pid, NULL, 0);
        exit(0);
    } else {
        // Error forking
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        exit(1);
    }

    return 0;
}