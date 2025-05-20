//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket(int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("socket failed");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("bind failed");
    }

    if (listen(sockfd, 5) < 0) {
        error("listen failed");
    }

    return sockfd;
}

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    send(client_socket, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", 51, 0);

    while (fgets(buffer, BUFFER_SIZE, stdin)!= NULL) {
        send(client_socket, buffer, strlen(buffer), 0);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    int server_socket = create_socket(port);

    printf("Server listening on port %d\n", port);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            error("accept failed");
        }

        printf("Client connected\n");
        handle_request(client_socket);

        close(client_socket);
    }

    return 0;
}