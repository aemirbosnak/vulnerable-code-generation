//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);

    // Create a TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind the server socket to the specified address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Receive data from the client
        char buffer[1024];
        ssize_t bytes_read = recv(new_socket, buffer, sizeof(buffer), 0);

        if (bytes_read == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        // Send the received data back to the client
        send(new_socket, buffer, bytes_read, 0);

        // Close the client socket
        close(new_socket);
    }

    close(server_fd);
    return 0;
}