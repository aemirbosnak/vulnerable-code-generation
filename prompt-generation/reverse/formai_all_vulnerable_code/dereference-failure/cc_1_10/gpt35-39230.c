//FormAI DATASET v1.0 Category: Firewall ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define ALLOWED_IP "192.168.1.1" // Replace with your trusted IP
#define BLOCKED_MESSAGE "Access denied, your IP address has been blocked"

int main(int argc, char const *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[1024] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port 8080
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections...\n");

    // Accept incoming connections
    while (1) {
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("Accepting connection failed");
            exit(EXIT_FAILURE);
        }

        printf("Incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Check if IP is trusted
        if (strcmp(ALLOWED_IP, inet_ntoa(client_addr.sin_addr)) != 0) {
            // If not, close connection and send blocked message
            close(client_fd);

            // Print blocked message to server console
            printf("Blocked connection from %s\n", inet_ntoa(client_addr.sin_addr));

            // Respond to client with blocked message
            send(client_fd, BLOCKED_MESSAGE, strlen(BLOCKED_MESSAGE), 0);
        } else {
            // If IP is trusted, process request
            memset(buffer, 0, 1024);
            read(client_fd, buffer, 1024);

            // Insert your custom code to process request here
            // ---------------------------------------------- //

            // Echo request back to client
            send(client_fd, buffer, strlen(buffer), 0);

            printf("Request processed and response sent to %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            close(client_fd);
        }
    }

    return 0;
}