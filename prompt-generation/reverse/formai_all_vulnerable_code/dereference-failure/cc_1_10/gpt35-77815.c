//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int socket_fd, client_fd, port_number, proxy_fd, proxy_port_number, n;
    struct sockaddr_in server_address, client_address, proxy_address;
    struct hostent *server;
    char buffer[BUFFER_SIZE], proxy_buffer[BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port_number proxy_port_number\n", argv[0]);
        exit(1);
    }

    port_number = atoi(argv[2]);
    proxy_port_number = atoi(argv[3]);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0) {
        error("Error opening socket");
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(0);
    }

    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server -> h_addr, (char *) &server_address.sin_addr.s_addr, server -> h_length);
    server_address.sin_port = htons(port_number);

    if (bind(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("Error on binding");
    }

    listen(socket_fd, 5);
    socklen_t client_length = sizeof(client_address);

    printf("Proxy server started on port %d\n", proxy_port_number);

    while (1) {
        client_fd = accept(socket_fd, (struct sockaddr *) &client_address, &client_length);

        if (client_fd < 0) {
            error("Error on accept");
        }

        bzero(buffer, BUFFER_SIZE);
        n = read(client_fd, buffer, BUFFER_SIZE);

        if (n < 0) {
            error("Error reading from socket");
        }

        printf("Request from client:\n%s\n", buffer);

        proxy_fd = socket(AF_INET, SOCK_STREAM, 0);

        if (proxy_fd < 0) {
            error("Error opening socket");
        }

        bzero((char *) &proxy_address, sizeof(proxy_address));
        proxy_address.sin_family = AF_INET;
        proxy_address.sin_addr.s_addr = INADDR_ANY;
        proxy_address.sin_port = htons(proxy_port_number);

        if (connect(proxy_fd, (struct sockaddr *) &proxy_address, sizeof(proxy_address)) < 0) {
            error("Error connecting to proxy server");
        }

        strcpy(proxy_buffer, argv[1]);
        strcat(proxy_buffer, buffer + 3);

        n = write(proxy_fd, proxy_buffer, strlen(proxy_buffer));

        if (n < 0) {
            error("Error writing to socket");
        }

        bzero(buffer, BUFFER_SIZE);
        n = read(proxy_fd, buffer, BUFFER_SIZE);

        if (n < 0) {
            error("Error reading from socket");
        }

        printf("Response from server:\n%s\n", buffer);

        n = write(client_fd, buffer, strlen(buffer));

        if (n < 0) {
            error("Error writing to socket");
        }

        close(client_fd);
        close(proxy_fd);
    }

    return 0;
}