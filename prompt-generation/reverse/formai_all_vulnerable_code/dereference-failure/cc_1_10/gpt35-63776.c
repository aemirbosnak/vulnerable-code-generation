//FormAI DATASET v1.0 Category: Chat server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int n_clients = 0;

void error(char *msg) {
    perror(msg);
    exit(1);
}

void accept_client(int server_socket) {
    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_len);
    if (client_socket < 0) {
        error("Error on accept");
    }

    if (n_clients >= MAX_CLIENTS) {
        printf("Max clients reached\n");
        close(client_socket);
        return;
    }

    clients[n_clients++] = client_socket;

    printf("Client %s connected\n", inet_ntoa(client_addr.sin_addr));
}

void broadcast(char *message, int sender) {
    int i;
    int message_len = strlen(message);

    for (i = 0; i < n_clients; i++) {
        if (clients[i] != sender) {
            send(clients[i], message, message_len, 0);
        }
    }
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int n;

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (n < 0) {
            error("Error reading from socket");
        }

        if (n == 0) {
            printf("Client disconnected\n");
            close(client_socket);
            return;
        }

        printf("Received message: %s\n", buffer);

        broadcast(buffer, client_socket);
    }
}

int main(int argc, char *argv[]) {
    int server_socket;
    int port_number;
    struct sockaddr_in server_addr;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
        exit(1);
    }

    port_number = atoi(argv[1]);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error("Error opening socket");
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_number);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error on binding");
    }

    listen(server_socket, 5);

    printf("Server started on port %d\n", port_number);

    while (1) {
        fd_set fds;
        int max_fd;
        int i;

        FD_ZERO(&fds);
        FD_SET(server_socket, &fds);
        max_fd = server_socket;

        for (i = 0; i < n_clients; i++) {
            FD_SET(clients[i], &fds);
            if (clients[i] > max_fd) {
                max_fd = clients[i];
            }
        }

        if (select(max_fd + 1, &fds, NULL, NULL, NULL) < 0) {
            error("Error on select");
        }

        if (FD_ISSET(server_socket, &fds)) {
            accept_client(server_socket);
        }

        for (i = 0; i < n_clients; i++) {
            if (FD_ISSET(clients[i], &fds)) {
                handle_client(clients[i]);
            }
        }
    }

    return 0;
}