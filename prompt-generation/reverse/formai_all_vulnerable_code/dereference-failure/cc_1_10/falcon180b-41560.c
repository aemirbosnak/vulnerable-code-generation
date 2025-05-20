//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

int main(int argc, char **argv) {
    int server_socket, new_socket, valread, sd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage:./server <port>\n");
        exit(0);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %s\n", argv[1]);

    while (1) {
        printf("Waiting for connections...\n");
        sd = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen);

        if (sd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection, socket fd is %d\n", sd);

        if (send(sd, "Welcome to the server\n", strlen("Welcome to the server\n"), 0)!= strlen("Welcome to the server\n")) {
            perror("send");
            exit(EXIT_FAILURE);
        }

        close(sd);
    }

    return 0;
}