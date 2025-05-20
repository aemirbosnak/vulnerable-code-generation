//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        error("Usage: ./proxy <port>");
    }

    int proxy_port = atoi(argv[1]);
    int client_sockets[MAX_CONNECTIONS];
    int num_clients = 0;

    fd_set readfds;
    FD_ZERO(&readfds);

    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        error("Error opening proxy socket");
    }

    struct sockaddr_in proxy_addr, client_addr;
    memset((char *) &proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(proxy_port);

    if (bind(proxy_socket, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
        error("Error binding proxy socket");
    }

    listen(proxy_socket, MAX_CONNECTIONS);

    printf("Proxy listening on port %d...\n", proxy_port);

    while (1) {
        FD_SET(proxy_socket, &readfds);
        for (int i = 0; i < num_clients; i++) {
            FD_SET(client_sockets[i], &readfds);
        }

        int max_fd = proxy_socket;
        for (int i = 0; i < num_clients; i++) {
            max_fd = (max_fd > client_sockets[i]) ? max_fd : client_sockets[i];
        }

        if (select(max_fd + 1, &readfds, NULL, NULL, NULL) < 0) {
            error("Error selecting socket descriptors");
        }

        if (FD_ISSET(proxy_socket, &readfds)) {
            int client_len = sizeof(client_addr);
            int client_socket = accept(proxy_socket, (struct sockaddr *) &client_addr, &client_len);
            if (client_socket < 0) {
                error("Error accepting client connection");
            }

            printf("Received connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            if (num_clients < MAX_CONNECTIONS) {
                client_sockets[num_clients++] = client_socket;
            } else {
                printf("Maximum number of connections reached, closing connection from %s:%d\n",
                       inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                close(client_socket);
            }
        }

        for (int i = 0; i < num_clients; i++) {
            int client_socket = client_sockets[i];
            if (FD_ISSET(client_socket, &readfds)) {
                char buffer[BUFFER_SIZE];
                memset(buffer, 0, BUFFER_SIZE);
                int recv_size = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
                if (recv_size < 0) {
                    printf("Error receiving data from client %d\n", client_socket);
                } else if (recv_size == 0) {
                    printf("Closing connection from client %d\n", client_socket);
                    close(client_socket);
                    client_sockets[i] = client_sockets[--num_clients];
                } else {
                    strcpy(buffer, "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, world!</h1></body></html>\r\n");
                    int send_size = send(client_socket, buffer, strlen(buffer), 0);
                    if (send_size < 0) {
                        printf("Error sending data to client %d\n", client_socket);
                    }
                }
            }
        }
    }

    close(proxy_socket);
    return 0;
}