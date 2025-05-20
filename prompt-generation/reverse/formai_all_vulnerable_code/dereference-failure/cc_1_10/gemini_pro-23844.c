//GEMINI-pro DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct {
    int fd;
    char *buf;
    size_t len;
} async_read_data;

void async_read(async_read_data *data) {
    ssize_t nread = read(data->fd, data->buf, data->len);
    if (nread == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("read %zd bytes: %s\n", nread, data->buf);
    free(data->buf);
    free(data);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    async_read_data *data = malloc(sizeof(async_read_data));
    data->fd = fd;
    data->len = st.st_size;
    data->buf = malloc(data->len);

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        async_read(data);
        exit(EXIT_SUCCESS);
    }

    close(fd);

    int status;
    waitpid(pid, &status, 0);

    if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS) {
        printf("async read completed successfully.\n");
    } else {
        printf("async read failed with status %d.\n", WEXITSTATUS(status));
    }

    return EXIT_SUCCESS;
}