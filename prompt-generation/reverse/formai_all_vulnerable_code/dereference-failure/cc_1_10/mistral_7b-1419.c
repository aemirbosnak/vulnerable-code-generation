//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PIPE_NAME "myfifo"

// Function to create a named pipe
int create_pipe(const char *path) {
    int fd[2];
    int ret;

    ret = mkfifo(path, 0666);
    if (ret && errno != EEXIST) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    ret = pipe(fd);
    if (ret < 0) {
        perror("pipe");
        unlink(path);
        exit(EXIT_FAILURE);
    }

    return fd[0];
}

int main() {
    int reader_fd, writer_fd;
    char *message = "Hello, IPC!";
    char read_buffer[100];
    size_t read_len;
    int status;

    // Create named pipe
    writer_fd = create_pipe(PIPE_NAME);

    // Write to named pipe
    writer_fd = open(PIPE_NAME, O_WRONLY);
    if (writer_fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    status = write(writer_fd, message, strlen(message) + 1);
    if (status < 0) {
        perror("write");
        close(writer_fd);
        unlink(PIPE_NAME);
        exit(EXIT_FAILURE);
    }

    close(writer_fd);

    // Read from named pipe
    reader_fd = open(PIPE_NAME, O_RDONLY);
    if (reader_fd < 0) {
        perror("open");
        unlink(PIPE_NAME);
        exit(EXIT_FAILURE);
    }

    while ((read_len = read(reader_fd, read_buffer, sizeof(read_buffer))) > 0) {
        printf("Received: %s\n", read_buffer);
    }

    if (read_len < 0) {
        perror("read");
    }

    close(reader_fd);
    unlink(PIPE_NAME);

    free(message);

    return EXIT_SUCCESS;
}