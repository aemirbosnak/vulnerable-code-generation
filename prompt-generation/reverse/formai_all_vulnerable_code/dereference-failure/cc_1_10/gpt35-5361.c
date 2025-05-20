//FormAI DATASET v1.0 Category: Socket programming ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please specify a port number.\n");
        return 1;
    }

    int port = atoi(argv[1]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket.\n");
        return 1;
    }

    // Bind socket to port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket to port.\n");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        printf("Error listening for connections.\n");
        return 1;
    }

    printf("Server started on port %d\n", port);

    while (1) {
        // Wait for client to connect
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
        if (client_sockfd < 0) {
            printf("Error accepting connection.\n");
            continue;
        }

        char *client_ip = inet_ntoa(client_addr.sin_addr);
        int client_port = ntohs(client_addr.sin_port);
        printf("Client connected from %s:%d\n", client_ip, client_port);

        // Receive data from client
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received < 0) {
            printf("Error receiving data from client.\n");
            continue;
        }

        printf("Received %d bytes from client: %s\n", bytes_received, buffer);

        // Send response to client
        char response[1024];
        sprintf(response, "Hello, %s! I received your data.", client_ip);
        int bytes_sent = send(client_sockfd, response, strlen(response), 0);
        if (bytes_sent < 0) {
            printf("Error sending data to client.\n");
            continue;
        }

        printf("Sent %d bytes to client: %s\n", bytes_sent, response);

        // Close connection with client
        close(client_sockfd);
        printf("Connection with client closed.\n");
    }

    // Close server socket
    close(sockfd);

    return 0; 
}