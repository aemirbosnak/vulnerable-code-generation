//FormAI DATASET v1.0 Category: Client Server Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define PORT 9002
#define MAX_MSG_LENGTH 1024

int main() {
    // Creating the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error in creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Configuring the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Binding the socket to the server
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error in binding socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(sockfd, 5) == -1) {
        printf("Error in listening for connections: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accepting a new connection
        int client_fd = accept(sockfd, NULL, NULL);
        if (client_fd == -1) {
            printf("Error in accepting incoming connection: %s\n", strerror(errno));
            continue;
        }

        printf("Client connected to the server...\n");

        // Receiving a message from the client
        char msg[MAX_MSG_LENGTH];
        memset(msg, 0, MAX_MSG_LENGTH);
        if (recv(client_fd, msg, MAX_MSG_LENGTH, 0) == -1) {
            printf("Error in receiving message from client: %s\n", strerror(errno));
            close(client_fd);
            continue;
        }

        printf("Received message from the client: %s\n", msg);

        // Sending a response back to the client
        char response[] = "Server received your message!";
        if (send(client_fd, response, strlen(response), 0) == -1) {
            printf("Error in sending response to client: %s\n", strerror(errno));
            close(client_fd);
            continue;
        }

        printf("Successfully sent response to client...\n");

        // Closing the connection
        close(client_fd);
        printf("Connection with client closed...\n");
    }

    // Closing the socket
    close(sockfd);
    printf("Server shutting down...\n");

    return 0;
}