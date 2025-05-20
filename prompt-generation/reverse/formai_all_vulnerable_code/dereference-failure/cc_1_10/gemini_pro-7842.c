//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <signal.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 512

struct client {
    int sockfd;
    struct sockaddr_un addr;
    char name[MAX_MSG_LEN];
};

struct server {
    int sockfd;
    struct sockaddr_un addr;
    struct client clients[MAX_CLIENTS];
    int num_clients;
};

struct message {
    char sender[MAX_MSG_LEN];
    char msg[MAX_MSG_LEN];
};

struct server *server;

void *handle_client(void *arg) {
    struct client *client = (struct client *)arg;
    char msg[MAX_MSG_LEN];
    while (1) {
        if (recv(client->sockfd, msg, MAX_MSG_LEN, 0) <= 0) {
            break;
        }
        printf("%s: %s", client->name, msg);
        for (int i = 0; i < server->num_clients; i++) {
            if (server->clients[i].sockfd != client->sockfd) {
                send(server->clients[i].sockfd, msg, MAX_MSG_LEN, 0);
            }
        }
    }
    close(client->sockfd);
    for (int i = 0; i < server->num_clients; i++) {
        if (server->clients[i].sockfd == client->sockfd) {
            server->clients[i] = server->clients[server->num_clients - 1];
            server->num_clients--;
        }
    }
    return NULL;
}

void handle_signal(int sig) {
    close(server->sockfd);
    unlink(server->addr.sun_path);
    exit(0);
}

int main(int argc, char *argv[]) {
    server = malloc(sizeof(struct server));
    server->sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server->sockfd < 0) {
        perror("socket");
        return 1;
    }

    server->addr.sun_family = AF_UNIX;
    strcpy(server->addr.sun_path, "chat");

    if (bind(server->sockfd, (struct sockaddr *)&server->addr, sizeof(server->addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(server->sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        return 1;
    }

    signal(SIGINT, handle_signal);

    while (1) {
        struct client client;
        socklen_t len = sizeof(client.addr);
        client.sockfd = accept(server->sockfd, (struct sockaddr *)&client.addr, &len);
        if (client.sockfd < 0) {
            perror("accept");
            continue;
        }

        if (recv(client.sockfd, client.name, MAX_MSG_LEN, 0) <= 0) {
            close(client.sockfd);
            continue;
        }

        printf("%s joined the chat\n", client.name);

        server->clients[server->num_clients] = client;
        server->num_clients++;

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, &client) != 0) {
            perror("pthread_create");
            close(client.sockfd);
            continue;
        }
    }

    close(server->sockfd);
    unlink(server->addr.sun_path);
    return 0;
}