//FormAI DATASET v1.0 Category: Client Server Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MESSAGE_SIZE 2000

void error(const char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket, port_number;
    socklen_t client_length;
    char message[MAX_MESSAGE_SIZE];
    struct sockaddr_in server_address, client_address;

    if (argc < 2) {
        fprintf(stderr, "Error: Please provide a valid port number.\n");
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error("Error: Failed to create server socket.");
    }

    memset((char *)&server_address, 0, sizeof(server_address));
    port_number = atoi(argv[1]);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("Error: Failed to bind server socket to address.");
    }

    listen(server_socket, 5);
    printf("Listening for incoming connections on port %d...\n", port_number);

    while (1) {
        client_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_length);

        if (client_socket < 0) {
            error("Error: Failed to accept incoming connection.");
        }

        memset(message, 0, MAX_MESSAGE_SIZE);
        int message_length = read(client_socket, message, MAX_MESSAGE_SIZE);
        if (message_length < 0) {
            error("Error: Failed to read message from client.");
        }

        printf("Received message from client: %s\n", message);

        char response[MAX_MESSAGE_SIZE];
        sprintf(response, "Server received message: %s", message);

        message_length = write(client_socket, response, strlen(response));
        if (message_length < 0) {
            error("Error: Failed to write response to client.");
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}