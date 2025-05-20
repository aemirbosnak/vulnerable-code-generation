//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int connect_to_server(const char *server_addr, int port) {
    struct sockaddr_in server;
    int sock_fd;

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, server_addr, &(server.sin_addr));

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        fprintf(stderr, "Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sock_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        fprintf(stderr, "Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    return sock_fd;
}

void receive_response(int sock_fd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    memset(buffer, 0, BUFFER_SIZE);
    while ((bytes_received = recv(sock_fd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        fflush(stdout);
        memset(buffer, 0, BUFFER_SIZE);
    }
}

int main(int argc, char *argv[]) {
    int sock_fd;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s server_address port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sock_fd = connect_to_server(argv[1], atoi(argv[2]));

    snprintf(buffer, BUFFER_SIZE, "01 LOGIN user@example.com password\n");
    send(sock_fd, buffer, strlen(buffer), 0);
    receive_response(sock_fd);

    snprintf(buffer, BUFFER_SIZE, "02 SELECT INBOX\n");
    send(sock_fd, buffer, strlen(buffer), 0);
    receive_response(sock_fd);

    snprintf(buffer, BUFFER_SIZE, "03 FETCH 1:10 (BODY[HEADER.FIELDS (SUBJECT FROM DATE)])\n");
    send(sock_fd, buffer, strlen(buffer), 0);
    receive_response(sock_fd);

    snprintf(buffer, BUFFER_SIZE, "04 LOGOUT\n");
    send(sock_fd, buffer, strlen(buffer), 0);
    receive_response(sock_fd);

    close(sock_fd);
    exit(EXIT_SUCCESS);
}