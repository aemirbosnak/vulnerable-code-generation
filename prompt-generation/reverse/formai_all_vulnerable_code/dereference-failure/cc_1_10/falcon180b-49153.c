//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, port, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        return 1;
    }

    port = atoi(argv[2]);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options on the socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(port);

    // Connect to server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Accept client connections
    while (1) {
        socklen_t addr_size;
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Forward data between client and server
        while (1) {
            bzero(buffer, BUF_SIZE);
            ssize_t recv_size = recv(client_socket, buffer, BUF_SIZE, 0);
            if (recv_size <= 0) {
                close(client_socket);
                break;
            }

            ssize_t send_size = send(server_socket, buffer, recv_size, 0);
            if (send_size!= recv_size) {
                close(client_socket);
                break;
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}