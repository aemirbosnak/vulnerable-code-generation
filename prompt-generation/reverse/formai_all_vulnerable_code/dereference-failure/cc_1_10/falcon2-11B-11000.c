//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: future-proof
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void create_chat_server(int port) {
    int server_fd, new_socket;
    struct sockaddr_in server_address;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    if (listen(server_fd, 5) < 0) {
        perror("Error listening on socket");
        exit(1);
    }

    while (1) {
        new_socket = accept(server_fd, NULL, NULL);
        if (new_socket < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        printf("Connection accepted from %s\n", inet_ntoa(server_address.sin_addr));

        char message[100];
        sprintf(message, "Welcome to the chat server! Type your message and press enter to send.");
        send(new_socket, message, strlen(message), 0);

        close(new_socket);
    }
}

int main() {
    int port = 8080;
    create_chat_server(port);
    return 0;
}