//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int server_fd, new_socket, portno, n;
    struct sockaddr_in server_addr, client_addr;

    // Create a socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Configure the socket address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(server_fd, 5);

    while (1) {
        // Accept a connection
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&n);
        if (new_socket < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Receive data from the client
        bzero((char *)&server_addr, sizeof(server_addr));
        n = sizeof(server_addr);
        if (getsockname(new_socket, (struct sockaddr *)&server_addr, &n) < 0) {
            perror("getsockname failed");
            exit(EXIT_FAILURE);
        }
        printf("Connection from %s:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

        // Send data back to the client
        if (send(new_socket, "Hello, world!", 13, 0) < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }
        printf("Data sent\n");

        // Close the connection
        close(new_socket);
    }

    close(server_fd);
    return 0;
}