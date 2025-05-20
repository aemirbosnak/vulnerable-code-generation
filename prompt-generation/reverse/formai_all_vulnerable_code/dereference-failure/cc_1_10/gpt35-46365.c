//FormAI DATASET v1.0 Category: Networking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind the socket to the specified port
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", port);

    while (1) {
        int client_sockfd;
        struct sockaddr_in client_addr;
        socklen_t client_addrlen = sizeof(client_addr);

        // Accept an incoming connection
        client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addrlen);
        if (client_sockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Receive data from the client
        char buffer[1024] = {0};
        int bytes_read = read(client_sockfd, buffer, sizeof(buffer));
        printf("Received %d bytes from client: %s\n", bytes_read, buffer);

        // Send a response back to the client
        char response[1024] = "Hello from the server!";
        write(client_sockfd, response, strlen(response));

        close(client_sockfd);
        printf("Connection closed.\n");
    }

    close(sockfd);
    return 0;
}