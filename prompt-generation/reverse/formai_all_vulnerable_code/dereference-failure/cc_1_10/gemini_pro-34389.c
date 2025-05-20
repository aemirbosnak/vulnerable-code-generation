//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 1024

struct client {
    int fd;
    char ip[INET_ADDRSTRLEN];
    char port[6];
    char name[32];
};

struct server {
    int fd;
    struct sockaddr_in addr;
    struct client clients[MAX_CLIENTS];
    int num_clients;
};

void recv_from_client(struct server *server, int fd) {
    char msg[MAX_MSG_LEN];
    int len = recv(fd, msg, MAX_MSG_LEN, 0);
    if (len <= 0) {
        printf("Client %s:%s disconnected\n", server->clients[fd].ip, server->clients[fd].port);
        close(fd);
        server->num_clients--;
    } else {
        msg[len] = '\0';
        printf("Received message from %s:%s: %s\n", server->clients[fd].ip, server->clients[fd].port, msg);
        for (int i = 0; i < server->num_clients; i++) {
            if (i != fd) {
                send(server->clients[i].fd, msg, len, 0);
            }
        }
    }
}

void accept_new_client(struct server *server) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_fd = accept(server->fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_fd < 0) {
        perror("Accept new client failed");
    } else {
        server->clients[server->num_clients].fd = client_fd;
        strcpy(server->clients[server->num_clients].ip, inet_ntoa(client_addr.sin_addr));
        sprintf(server->clients[server->num_clients].port, "%d", ntohs(client_addr.sin_port));
        printf("New client connected: %s:%s\n", server->clients[server->num_clients].ip, server->clients[server->num_clients].port);
        server->num_clients++;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct server server;
    server.fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server.fd < 0) {
        perror("Create server socket failed");
        return EXIT_FAILURE;
    }

    memset(&server.addr, 0, sizeof(server.addr));
    server.addr.sin_family = AF_INET;
    server.addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server.addr.sin_port = htons(atoi(argv[1]));

    if (bind(server.fd, (struct sockaddr *)&server.addr, sizeof(server.addr)) < 0) {
        perror("Bind server socket failed");
        return EXIT_FAILURE;
    }

    if (listen(server.fd, 10) < 0) {
        perror("Listen on server socket failed");
        return EXIT_FAILURE;
    }

    server.num_clients = 0;

    while (1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(server.fd, &read_fds);
        for (int i = 0; i < server.num_clients; i++) {
            FD_SET(server.clients[i].fd, &read_fds);
        }

        int max_fd = server.fd;
        for (int i = 0; i < server.num_clients; i++) {
            if (server.clients[i].fd > max_fd) {
                max_fd = server.clients[i].fd;
            }
        }

        int select_result = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
        if (select_result < 0) {
            perror("Select failed");
            return EXIT_FAILURE;
        }

        if (FD_ISSET(server.fd, &read_fds)) {
            accept_new_client(&server);
        }

        for (int i = 0; i < server.num_clients; i++) {
            if (FD_ISSET(server.clients[i].fd, &read_fds)) {
                recv_from_client(&server, server.clients[i].fd);
            }
        }
    }

    close(server.fd);
    return EXIT_SUCCESS;
}