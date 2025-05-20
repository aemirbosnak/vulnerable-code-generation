//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>

#define MAX_CLIENTS 10

struct client {
    int fd;
    char username[256];
    struct client *next;
};

struct client *clients = NULL;

int listenfd, port;
char *hostname;

void error(char *msg) {
    perror(msg);
    exit(1);
}

void send_to_all(char *msg, int sender_fd) {
    struct client *client = clients;
    while (client) {
        if (client->fd != sender_fd) {
            if (send(client->fd, msg, strlen(msg), 0) < 0) {
                error("send");
            }
        }
        client = client->next;
    }
}

void handle_client(void *arg) {
    int fd = *(int *)arg;
    char buffer[256], username[256];
    int n;
    free(arg);
    if (recv(fd, username, sizeof(username), 0) < 0) {
        error("recv");
    }
    sprintf(buffer, "%s has joined the chat\n", username);
    send_to_all(buffer, fd);

    while ((n = recv(fd, buffer, sizeof(buffer), 0)) > 0) {
        if (strncmp(buffer, "/quit", 5) == 0) {
            sprintf(buffer, "%s has left the chat\n", username);
            send_to_all(buffer, fd);
            close(fd);
            pthread_exit(NULL);
        } else {
            sprintf(buffer, "%s: %s", username, buffer);
            send_to_all(buffer, fd);
        }
    }
    if (n < 0) {
        error("recv");
    }
}

void signal_handler(int sig) {
    struct client *client = clients, *next_client;
    while (client) {
        close(client->fd);
        client = client->next;
    }
    close(listenfd);
    exit(0);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len;
    pthread_t tid;
    int newfd;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    port = atoi(argv[2]);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        error("socket");
    }

    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(hostname);
    serv_addr.sin_port = htons(port);

    if (bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("bind");
    }

    if (listen(listenfd, MAX_CLIENTS) < 0) {
        error("listen");
    }

    while (1) {
        cli_len = sizeof(cli_addr);
        newfd = accept(listenfd, (struct sockaddr *)&cli_addr, &cli_len);
        if (newfd < 0) {
            if (errno == EINTR) {
                continue;
            } else {
                error("accept");
            }
        }

        struct client *new_client = malloc(sizeof(struct client));
        if (!new_client) {
            error("malloc");
        }
        new_client->fd = newfd;
        strcpy(new_client->username, "");
        new_client->next = NULL;

        struct client *prev_client = clients;
        if (!prev_client) {
            clients = new_client;
        } else {
            while (prev_client->next) {
                prev_client = prev_client->next;
            }
            prev_client->next = new_client;
        }

        int *arg = malloc(sizeof(int));
        if (!arg) {
            error("malloc");
        }
        *arg = newfd;

        if (pthread_create(&tid, NULL, (void *)handle_client, (void *)arg) < 0) {
            error("pthread_create");
        }
    }

    return 0;
}