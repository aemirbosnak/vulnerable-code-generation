//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int server_fd, new_socket, portno;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    int n;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    // Create the socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    // Initialize the server address structure
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(portno);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Waiting for a connection...\n");
    fflush(stdout);

    while (1) {
        // Accept the incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *) &client_addr, (socklen_t *) &n)) == -1) {
            perror("accept");
            exit(1);
        }

        // Receive data from the client
        bzero(buffer, sizeof(buffer));
        n = recv(new_socket, buffer, sizeof(buffer), 0);
        if (n < 0) {
            perror("recv");
            exit(1);
        }

        // Process the data
        printf("Received message: %s\n", buffer);

        // Send a response back to the client
        bzero(buffer, sizeof(buffer));
        sprintf(buffer, "Message received!\n");
        if (send(new_socket, buffer, strlen(buffer), 0) == -1) {
            perror("send");
            exit(1);
        }

        // Close the socket
        close(new_socket);
    }

    close(server_fd);
    return 0;
}