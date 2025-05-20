//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

struct client_info {
    int fd;
    char name[32];
    char msg[MAX_MSG_SIZE];
};

struct server_info {
    int fd;
    struct sockaddr_in addr;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    struct server_info server;
    server.fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server.fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server.addr.sin_family = AF_INET;
    server.addr.sin_port = htons(port);
    server.addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server.fd, (struct sockaddr *)&server.addr, sizeof(server.addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server.fd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    struct client_info clients[MAX_CLIENTS];
    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i].fd = -1;
    }

    while (1) {
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(server.fd, &fds);

        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].fd != -1) {
                FD_SET(clients[i].fd, &fds);
            }
        }

        if (select(FD_SETSIZE, &fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(server.fd, &fds)) {
            struct sockaddr_in client_addr;
            socklen_t client_addr_len = sizeof(client_addr);
            int client_fd = accept(server.fd, (struct sockaddr *)&client_addr, &client_addr_len);
            if (client_fd == -1) {
                perror("accept");
                continue;
            }

            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].fd == -1) {
                    clients[i].fd = client_fd;
                    strcpy(clients[i].name, inet_ntoa(client_addr.sin_addr));
                    printf("Client %s connected\n", clients[i].name);
                    break;
                }
            }
        }

        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].fd != -1 && FD_ISSET(clients[i].fd, &fds)) {
                int n = read(clients[i].fd, clients[i].msg, MAX_MSG_SIZE);
                if (n == -1) {
                    perror("read");
                    close(clients[i].fd);
                    clients[i].fd = -1;
                    continue;
                } else if (n == 0) {
                    printf("Client %s disconnected\n", clients[i].name);
                    close(clients[i].fd);
                    clients[i].fd = -1;
                    continue;
                }

                clients[i].msg[n] = '\0';
                printf("Client %s says: %s\n", clients[i].name, clients[i].msg);

                for (int j = 0; j < MAX_CLIENTS; j++) {
                    if (clients[j].fd != -1 && i != j) {
                        write(clients[j].fd, clients[i].msg, n);
                    }
                }
            }
        }
    }

    close(server.fd);
    return 0;
}