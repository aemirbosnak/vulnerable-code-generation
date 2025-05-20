//GEMINI-pro DATASET v1.0 Category: Networking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5
#define MAX_LINE_LENGTH 1024
#define PORT 5000

struct client {
    int fd;
    struct sockaddr_in addr;
    char buffer[MAX_LINE_LENGTH];
    int buffer_len;
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

void handle_client(struct client *client) {
    int n;

    while ((n = recv(client->fd, client->buffer, MAX_LINE_LENGTH, 0)) > 0) {
        client->buffer[n] = '\0';
        printf("Received: %s\n", client->buffer);
        send(client->fd, client->buffer, n, 0);
    }

    if (n == 0) {
        printf("Client closed connection\n");
    } else {
        perror("recv");
    }

    close(client->fd);
    num_clients--;
}

int main() {
    int server_fd, new_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_fd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        client_addr_len = sizeof(client_addr);
        new_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_fd == -1) {
            perror("accept");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            printf("Too many clients connected, ignoring new connection\n");
            close(new_fd);
            continue;
        }

        clients[num_clients].fd = new_fd;
        clients[num_clients].addr = client_addr;
        clients[num_clients].buffer_len = 0;
        num_clients++;

        printf("New client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        handle_client(&clients[num_clients - 1]);
    }

    return 0;
}