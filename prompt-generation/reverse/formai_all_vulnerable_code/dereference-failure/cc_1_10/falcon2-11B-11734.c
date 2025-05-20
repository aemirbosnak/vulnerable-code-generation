//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct server_info {
    char hostname[16];
    int port;
};

void handle_connection(int socket_fd, char* input, char* response) {
    char* buffer = "Welcome to the chat server!";
    int num_bytes = strlen(buffer);
    int bytes_sent = send(socket_fd, buffer, num_bytes, 0);
    if (bytes_sent < 0) {
        perror("Error sending message");
    } else {
        printf("Message sent: %s\n", buffer);
    }
    int num_bytes_received = read(socket_fd, input, 256);
    if (num_bytes_received < 0) {
        perror("Error receiving message");
    } else {
        printf("Received message: %s\n", input);
        int num_bytes_to_send = sprintf(response, "You said: %s", input);
        int bytes_sent = send(socket_fd, response, num_bytes_to_send, 0);
        if (bytes_sent < 0) {
            perror("Error sending response");
        } else {
            printf("Response sent: %s\n", response);
        }
    }
}

int main(int argc, char* argv[]) {
    int server_fd;
    struct server_info server;
    char buffer[256];
    char response[256];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    strncpy(server.hostname, argv[1], sizeof(server.hostname));
    server.port = atoi(argv[1]);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(server.port);

    bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address));
    if (bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    listen(server_fd, 5);
    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("Error accepting connection");
            continue;
        }

        handle_connection(client_fd, buffer, response);
        close(client_fd);
    }

    close(server_fd);
    return 0;
}