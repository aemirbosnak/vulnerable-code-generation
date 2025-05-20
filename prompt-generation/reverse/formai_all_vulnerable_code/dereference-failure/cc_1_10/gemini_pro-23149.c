//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444
#define MAX_CLIENTS 10
#define MAX_MSG_LEN 1024

struct client {
    int sockfd;
    char name[32];
    char ip[16];
    time_t last_active;
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast_msg(char *msg, int sender) {
    for (int i = 0; i < num_clients; i++) {
        if (i == sender) continue;
        send(clients[i].sockfd, msg, strlen(msg), 0);
    }
}

int main() {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    char msg[MAX_MSG_LEN];
    char name[32];

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("Error creating server socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sockfd, (struct sockaddr *)&server_addr, addr_len) == -1) {
        perror("Error binding server socket");
        exit(1);
    }

    if (listen(server_sockfd, MAX_CLIENTS) == -1) {
        perror("Error listening on server socket");
        exit(1);
    }

    while (1) {
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &addr_len);
        if (client_sockfd == -1) {
            perror("Error accepting client connection");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            send(client_sockfd, "Server is full", 14, 0);
            close(client_sockfd);
            continue;
        }

        recv(client_sockfd, name, 32, 0);
        strcpy(clients[num_clients].name, name);
        strcpy(clients[num_clients].ip, inet_ntoa(client_addr.sin_addr));
        clients[num_clients].sockfd = client_sockfd;
        clients[num_clients].last_active = time(NULL);
        num_clients++;

        sprintf(msg, "%s joined the chat", name);
        broadcast_msg(msg, -1);

        while (1) {
            memset(msg, 0, MAX_MSG_LEN);
            if (recv(client_sockfd, msg, MAX_MSG_LEN, 0) <= 0) {
                sprintf(msg, "%s left the chat", name);
                broadcast_msg(msg, -1);
                close(client_sockfd);
                for (int i = 0; i < num_clients; i++) {
                    if (clients[i].sockfd == client_sockfd) {
                        clients[i] = clients[num_clients - 1];
                        num_clients--;
                        break;
                    }
                }
                break;
            }

            if (strcmp(msg, "/quit") == 0) {
                sprintf(msg, "%s left the chat", name);
                broadcast_msg(msg, -1);
                close(client_sockfd);
                for (int i = 0; i < num_clients; i++) {
                    if (clients[i].sockfd == client_sockfd) {
                        clients[i] = clients[num_clients - 1];
                        num_clients--;
                        break;
                    }
                }
                break;
            }

            time_t now = time(NULL);
            if (difftime(now, clients[num_clients].last_active) > 600) {
                sprintf(msg, "%s timed out", name);
                broadcast_msg(msg, -1);
                close(client_sockfd);
                for (int i = 0; i < num_clients; i++) {
                    if (clients[i].sockfd == client_sockfd) {
                        clients[i] = clients[num_clients - 1];
                        num_clients--;
                        break;
                    }
                }
                break;
            }

            clients[num_clients].last_active = now;
            broadcast_msg(msg, client_sockfd);
        }
    }

    close(server_sockfd);
    return 0;
}