//Falcon2-11B DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct {
    int sockfd;
    int input_buffer;
    int output_buffer;
    int in_size;
    int out_size;
} t_async_io;

static void sigint_handler(int signum) {
    fprintf(stderr, "Received SIGINT signal, exiting...\n");
    exit(0);
}

static void *read_handler(void *arg) {
    t_async_io *io = (t_async_io *)arg;
    char *buffer = malloc(io->in_size);

    while (1) {
        int bytes_read = read(io->sockfd, buffer, io->in_size);
        if (bytes_read < 0) {
            fprintf(stderr, "Error reading from socket: %s\n", strerror(errno));
            exit(1);
        } else if (bytes_read == 0) {
            break;
        }

        printf("%s", buffer);
        free(buffer);
    }

    free(io);
    return NULL;
}

static void *write_handler(void *arg) {
    t_async_io *io = (t_async_io *)arg;
    char *buffer = malloc(io->out_size);

    while (1) {
        int bytes_written = write(io->sockfd, buffer, io->out_size);
        if (bytes_written < 0) {
            fprintf(stderr, "Error writing to socket: %s\n", strerror(errno));
            exit(1);
        }

        if (bytes_written == 0) {
            break;
        }

        printf("%s", buffer);
        free(buffer);
    }

    free(io);
    return NULL;
}

int main(int argc, char **argv) {
    int sockfd = 0;
    struct sockaddr_in server_addr;
    int listen_fd;
    int conn_fd;
    int client_addrlen;
    int in_size = 1024;
    int out_size = 1024;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server-ip>\n", argv[0]);
        exit(1);
    }

    signal(SIGINT, sigint_handler);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(12345);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    listen_fd = accept(sockfd, (struct sockaddr *)&server_addr, &client_addrlen);
    if (listen_fd < 0) {
        fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
        exit(1);
    }

    t_async_io *io = malloc(sizeof(t_async_io));
    io->sockfd = listen_fd;
    io->input_buffer = io->out_size = in_size;
    io->in_size = io->out_size = in_size;
    io->output_buffer = io->in_size = in_size;

    pthread_t read_thread;
    pthread_t write_thread;

    pthread_create(&read_thread, NULL, read_handler, (void *)io);
    pthread_create(&write_thread, NULL, write_handler, (void *)io);

    int rc = pthread_join(read_thread, NULL);
    if (rc) {
        fprintf(stderr, "Error joining read thread: %s\n", strerror(rc));
        exit(1);
    }

    rc = pthread_join(write_thread, NULL);
    if (rc) {
        fprintf(stderr, "Error joining write thread: %s\n", strerror(rc));
        exit(1);
    }

    return 0;
}