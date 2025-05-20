//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char **argv)
{
    int fd;
    char *buf;
    struct stat st;
    pid_t pid;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <boot-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    if (fstat(fd, &st) < 0) {
        perror("fstat");
        close(fd);
        return EXIT_FAILURE;
    }

    if (!(buf = malloc(st.st_size))) {
        perror("malloc");
        close(fd);
        return EXIT_FAILURE;
    }

    if (read(fd, buf, st.st_size) < 0) {
        perror("read");
        close(fd);
        free(buf);
        return EXIT_FAILURE;
    }

    close(fd);

    if (!(pid = fork())) {
        // child process
        execve("/sbin/init", NULL, NULL);
        perror("execve");
        exit(EXIT_FAILURE);
    } else {
        // parent process
        waitpid(pid, NULL, 0);
        free(buf);
    }

    return EXIT_SUCCESS;
}