//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <sys/fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <pthread.h>

#define MAX_CLIENTS 16
#define BUFFER_SIZE 256

typedef struct {
    int fd;
    struct sockaddr_in addr;
    char *buffer;
    int buffer_len;
} client_t;

typedef struct {
    int fd;
    pthread_t thread;
    pthread_mutex_t mutex;
    client_t *clients[MAX_CLIENTS];
    int num_clients;
} server_t;

static void sigint_handler(int sig) {
    exit(0);
}

static int create_socket(int port) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    if (bind(fd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("bind");
        close(fd);
        return -1;
    }

    if (listen(fd, 16) < 0) {
        perror("listen");
        close(fd);
        return -1;
    }

    return fd;
}

static void handle_client(server_t *server, client_t *client) {
    char *buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        perror("malloc");
        free(client);
        return;
    }

    while (1) {
        int n = read(client->fd, buffer, BUFFER_SIZE);
        if (n < 0) {
            perror("read");
            free(buffer);
            free(client);
            return;
        } else if (n == 0) {
            free(buffer);
            free(client);
            return;
        }

        pthread_mutex_lock(&server->mutex);
        for (int i = 0; i < server->num_clients; i++) {
            if (server->clients[i] != client) {
                write(server->clients[i]->fd, buffer, n);
            }
        }
        pthread_mutex_unlock(&server->mutex);
    }
}

static void *server_thread(void *arg) {
    server_t *server = (server_t *) arg;

    while (1) {
        struct sockaddr_in addr;
        socklen_t addr_len = sizeof(addr);
        int fd = accept(server->fd, (struct sockaddr *) &addr, &addr_len);
        if (fd < 0) {
            if (errno == EINTR) {
                continue;
            }
            perror("accept");
            continue;
        }

        pthread_mutex_lock(&server->mutex);
        if (server->num_clients < MAX_CLIENTS) {
            client_t *client = malloc(sizeof(client_t));
            if (!client) {
                perror("malloc");
                close(fd);
                pthread_mutex_unlock(&server->mutex);
                continue;
            }

            client->fd = fd;
            client->addr = addr;
            client->buffer = NULL;
            client->buffer_len = 0;
            server->clients[server->num_clients++] = client;
            pthread_mutex_unlock(&server->mutex);
        } else {
            close(fd);
        }
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);
    if (port <= 0 || port > 65535) {
        fprintf(stderr, "Invalid port number: %d\n", port);
        return EXIT_FAILURE;
    }

    signal(SIGINT, sigint_handler);

    server_t server;
    memset(&server, 0, sizeof(server));

    server.fd = create_socket(port);
    if (server.fd < 0) {
        return EXIT_FAILURE;
    }

    pthread_mutex_init(&server.mutex, NULL);

    if (pthread_create(&server.thread, NULL, server_thread, &server) != 0) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    while (1) {
        sleep(1);
    }

    pthread_join(server.thread, NULL);
    pthread_mutex_destroy(&server.mutex);

    for (int i = 0; i < server.num_clients; i++) {
        close(server.clients[i]->fd);
        free(server.clients[i]->buffer);
        free(server.clients[i]);
    }

    close(server.fd);

    return EXIT_SUCCESS;
}