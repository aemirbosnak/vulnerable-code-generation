//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 100
#define MAX_MSG_LEN 1024

struct client {
    int sockfd;
    char username[32];
    struct client *next;
};

struct server {
    int sockfd;
    struct client *clients;
};

struct server *server_init(int port) {
    struct server *server = malloc(sizeof(struct server));
    if (server == NULL) {
        perror("malloc");
        return NULL;
    }

    server->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sockfd == -1) {
        perror("socket");
        free(server);
        return NULL;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(server->sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(server->sockfd);
        free(server);
        return NULL;
    }

    if (listen(server->sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        close(server->sockfd);
        free(server);
        return NULL;
    }

    server->clients = NULL;

    return server;
}

void server_free(struct server *server) {
    struct client *client = server->clients;
    while (client != NULL) {
        struct client *next = client->next;
        free(client);
        client = next;
    }

    close(server->sockfd);
    free(server);
}

void client_add(struct server *server, int sockfd, char *username) {
    struct client *client = malloc(sizeof(struct client));
    if (client == NULL) {
        perror("malloc");
        return;
    }

    client->sockfd = sockfd;
    strcpy(client->username, username);
    client->next = server->clients;
    server->clients = client;
}

void client_remove(struct server *server, struct client *client) {
    if (client == server->clients) {
        server->clients = client->next;
    } else {
        struct client *prev = server->clients;
        while (prev->next != client) {
            prev = prev->next;
        }
        prev->next = client->next;
    }
    free(client);
}

void client_send_message(struct server *server, struct client *client, char *message) {
    char buffer[MAX_MSG_LEN];
    snprintf(buffer, sizeof(buffer), "%s: %s", client->username, message);
    for (struct client *c = server->clients; c != NULL; c = c->next) {
        if (c != client) {
            send(c->sockfd, buffer, strlen(buffer), 0);
        }
    }
}

void server_run(struct server *server) {
    fd_set read_fds;
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(server->sockfd, &read_fds);
        for (struct client *client = server->clients; client != NULL; client = client->next) {
            FD_SET(client->sockfd, &read_fds);
        }

        int maxfd = server->sockfd;
        for (struct client *client = server->clients; client != NULL; client = client->next) {
            if (client->sockfd > maxfd) {
                maxfd = client->sockfd;
            }
        }

        if (select(maxfd + 1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            continue;
        }

        if (FD_ISSET(server->sockfd, &read_fds)) {
            struct sockaddr_in addr;
            socklen_t addrlen = sizeof(addr);
            int sockfd = accept(server->sockfd, (struct sockaddr *)&addr, &addrlen);
            if (sockfd == -1) {
                perror("accept");
                continue;
            }

            char buffer[MAX_MSG_LEN];
            if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
                perror("recv");
                close(sockfd);
                continue;
            }

            char *username = strtok(buffer, ":");
            client_add(server, sockfd, username);
            printf("Client %s connected\n", username);
        }

        for (struct client *client = server->clients; client != NULL; client = client->next) {
            if (FD_ISSET(client->sockfd, &read_fds)) {
                char buffer[MAX_MSG_LEN];
                if (recv(client->sockfd, buffer, sizeof(buffer), 0) == -1) {
                    perror("recv");
                    client_remove(server, client);
                    printf("Client %s disconnected\n", client->username);
                    continue;
                }

                client_send_message(server, client, buffer);
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);

    struct server *server = server_init(port);
    if (server == NULL) {
        return EXIT_FAILURE;
    }

    server_run(server);

    server_free(server);

    return EXIT_SUCCESS;
}