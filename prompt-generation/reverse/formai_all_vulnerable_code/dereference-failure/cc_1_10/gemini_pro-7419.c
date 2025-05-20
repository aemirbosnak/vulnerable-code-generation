//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

#define MAX_CLIENTS 100
#define MAX_MSG_LEN 1024

typedef struct {
    int fd;
    struct sockaddr_in addr;
    char name[32];
    char msg_buf[MAX_MSG_LEN + 1];
    size_t msg_len;
    time_t last_active;
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients;
int server_fd;
struct sockaddr_in server_addr;

void broadcast(const char *msg, size_t len) {
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].fd != -1) {
            send(clients[i].fd, msg, len, 0);
        }
    }
}

void handle_client(client_t *client) {
    char buf[MAX_MSG_LEN + 1];
    int n;

    while ((n = recv(client->fd, buf, MAX_MSG_LEN, 0)) > 0) {
        buf[n] = '\0';

        if (strncmp(buf, "/name", 5) == 0) {
            strncpy(client->name, buf + 6, sizeof(client->name) - 1);
            broadcast(buf, strlen(buf));
        } else if (strncmp(buf, "/msg", 4) == 0) {
            char *msg = buf + 5;
            char *delim = strchr(msg, ' ');
            if (delim != NULL) {
                *delim = '\0';
                int to = atoi(msg);
                if (to >= 0 && to < num_clients && clients[to].fd != -1) {
                    snprintf(buf, sizeof(buf), "%s: %s", client->name, delim + 1);
                    send(clients[to].fd, buf, strlen(buf), 0);
                }
            }
        } else {
            broadcast(buf, strlen(buf));
        }

        client->last_active = time(NULL);
    }

    close(client->fd);
    client->fd = -1;
    num_clients--;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(server_fd, MAX_CLIENTS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    while (1) {
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(server_fd, &rfds);

        for (int i = 0; i < num_clients; i++) {
            if (clients[i].fd != -1) {
                FD_SET(clients[i].fd, &rfds);
            }
        }

        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        if (select(FD_SETSIZE, &rfds, NULL, NULL, &timeout) == -1) {
            perror("select");
            return EXIT_FAILURE;
        }

        if (FD_ISSET(server_fd, &rfds)) {
            struct sockaddr_in client_addr;
            socklen_t client_addr_len = sizeof(client_addr);

            int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
            if (client_fd == -1) {
                perror("accept");
                continue;
            }

            if (num_clients == MAX_CLIENTS) {
                close(client_fd);
                continue;
            }

            client_t *client = &clients[num_clients++];
            client->fd = client_fd;
            client->addr = client_addr;
            client->name[0] = '\0';
            client->msg_len = 0;
            client->last_active = time(NULL);

            char buf[MAX_MSG_LEN + 1];
            snprintf(buf, sizeof(buf), "%d has joined the chat", num_clients);
            broadcast(buf, strlen(buf));
        }

        for (int i = 0; i < num_clients; i++) {
            if (clients[i].fd != -1 && FD_ISSET(clients[i].fd, &rfds)) {
                handle_client(&clients[i]);
            }
        }

        time_t now = time(NULL);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].fd != -1 && now - clients[i].last_active > 600) {
                char buf[MAX_MSG_LEN + 1];
                snprintf(buf, sizeof(buf), "%s has left the chat", clients[i].name);
                broadcast(buf, strlen(buf));

                close(clients[i].fd);
                clients[i].fd = -1;
                num_clients--;
            }
        }
    }

    return EXIT_SUCCESS;
}