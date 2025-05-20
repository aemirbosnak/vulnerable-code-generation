//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CONNECTIONS 5

// Structure to store client information
typedef struct client {
    int sockfd;
    struct sockaddr_in addr;
    char *username;
    char *password;
} client_t;

// Function to handle client connections
void handle_client(client_t *client) {
    char buffer[1024];
    int n;

    // Receive the client's message
    n = recv(client->sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv");
        close(client->sockfd);
        return;
    }

    // Process the client's message
    char *command = strtok(buffer, " ");
    if (strcmp(command, "LOGIN") == 0) {
        // Handle the LOGIN command
        char *username = strtok(NULL, " ");
        char *password = strtok(NULL, " ");

        // Check the client's credentials
        if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
            // Send a success message to the client
            n = send(client->sockfd, "SUCCESS", strlen("SUCCESS"), 0);
            if (n < 0) {
                perror("send");
                close(client->sockfd);
                return;
            }
        } else {
            // Send a failure message to the client
            n = send(client->sockfd, "FAILURE", strlen("FAILURE"), 0);
            if (n < 0) {
                perror("send");
                close(client->sockfd);
                return;
            }
        }
    } else if (strcmp(command, "LOGOUT") == 0) {
        // Handle the LOGOUT command
        // Send a success message to the client
        n = send(client->sockfd, "SUCCESS", strlen("SUCCESS"), 0);
        if (n < 0) {
            perror("send");
            close(client->sockfd);
            return;
        }
    } else {
        // Send an error message to the client
        n = send(client->sockfd, "ERROR", strlen("ERROR"), 0);
        if (n < 0) {
            perror("send");
            close(client->sockfd);
            return;
        }
    }

    // Close the client's connection
    close(client->sockfd);
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        close(sockfd);
        return 1;
    }

    // Set the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(5000);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(sockfd);
        return 1;
    }

    // Listen for connections
    if (listen(sockfd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        close(sockfd);
        return 1;
    }

    // Accept connections
    while (1) {
        // Accept a connection
        client_t client;
        client.sockfd = accept(sockfd, (struct sockaddr *) &client.addr, (socklen_t *) sizeof(client.addr));
        if (client.sockfd < 0) {
            perror("accept");
            continue;
        }

        // Handle the client connection
        handle_client(&client);
    }

    // Close the socket
    close(sockfd);

    return 0;
}