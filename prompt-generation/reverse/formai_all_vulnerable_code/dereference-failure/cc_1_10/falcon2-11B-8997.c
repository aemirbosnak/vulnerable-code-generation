//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    // Define socket parameters
    int listen_fd, conn_fd;
    struct sockaddr_in listen_addr, client_addr;
    int addrlen = sizeof(client_addr);

    // Create socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up socket address structure
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(atoi(argv[1]));

    // Bind socket to port
    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("Error binding to port");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(listen_fd, 5) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if (conn_fd < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Send greeting message to connected client
        printf("Connected by client with IP: %s\n", inet_ntoa(client_addr.sin_addr));
        printf("Hello, client!\n");

        // Close connection
        close(conn_fd);
        break;
    }

    // Close socket
    close(listen_fd);
    return 0;
}