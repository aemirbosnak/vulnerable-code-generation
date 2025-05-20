//FormAI DATASET v1.0 Category: Socket programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MSG_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 2) {
        perror("Usage: ./decentralized_server <port_number>");
        exit(1);
    }

    int port_number = atoi(argv[1]);

    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port_number);

    int bind_result = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (bind_result < 0) {
        perror("Failed to bind socket");
        exit(1);
    }

    int listen_result = listen(server_socket, 5);
    if (listen_result < 0) {
        perror("Failed to listen on socket");
        exit(1);
    }

    while (1) {
        struct sockaddr_in client_address;
        memset(&client_address, 0, sizeof(client_address));
        socklen_t client_address_size = sizeof(client_address);

        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size);
        if (client_socket < 0) {
            perror("Failed to accept client connection");
            exit(1);
        }

        char message[MSG_SIZE];
        memset(message, 0, MSG_SIZE);

        ssize_t recv_result = recv(client_socket, message, MSG_SIZE, 0);
        if (recv_result < 0) {
            perror("Failed to receive message from client");
            exit(1);
        }

        printf("Received message: %s\n", message);

        if (strcmp(message, "HELLO") == 0) {
            char *response = "WORLD";
            ssize_t send_result = send(client_socket, response, strlen(response), 0);
            if (send_result < 0) {
                perror("Failed to send message to client");
                exit(1);
            }

            printf("Sent response: %s\n", response);
        } else {
            printf("Unknown message: %s\n", message);
        }

        close(client_socket);
    }

    close(server_socket);

    return 0;
}