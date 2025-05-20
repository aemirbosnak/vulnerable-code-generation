//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the IP address and port number
    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the socket address
    struct sockaddr_in socket_address;
    memset(&socket_address, 0, sizeof(socket_address));
    socket_address.sin_family = AF_INET;
    socket_address.sin_addr.s_addr = inet_addr(ip_address);
    socket_address.sin_port = htons(port_number);

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&socket_address, sizeof(socket_address)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    char *message = "Hello, world!\n";
    if (send(socket_fd, message, strlen(message), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive a message from the server
    char buffer[1024];
    if (recv(socket_fd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Print the message from the server
    printf("%s", buffer);

    // Close the socket
    close(socket_fd);

    return 0;
}