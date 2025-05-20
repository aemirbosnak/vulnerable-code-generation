//FormAI DATASET v1.0 Category: Chat server ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        perror("ERROR: Port number not provided\n");
        exit(1);
    }

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    bzero((char*)&server_address, sizeof(server_address));

    int port_number = atoi(argv[1]);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("ERROR: Binding failed\n");
        exit(1);
    }

    listen(server_socket, 5);

    printf("Server is running on port %d...\n", port_number);

    while(true) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket < 0) {
            perror("ERROR: Failed to accept incoming connection\n");
            exit(1);
        }

        char buffer[256];
        bzero(buffer, 256);
        int n = read(client_socket, buffer, 255);

        if (n < 0) {
            perror("ERROR: Failed to read from socket\n");
            exit(1);
        }

        printf("Received message from client: %s\n", buffer);

        n = write(client_socket, "Server received your message", 28);

        if (n < 0) {
            perror("ERROR: Failed to write to socket\n");
            exit(1);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}