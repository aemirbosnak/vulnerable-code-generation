//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <poll.h>

// Define constants
#define PORT 8080
#define BUFSIZE 1024
#define MAX_CONN 5

// Structure for storing client information
typedef struct {
    int sockfd;
    char client_address[INET6_ADDRSTRLEN];
    int client_len;
} client_t;

// Function to handle client connection
void handle_client(int client_sockfd) {
    char buffer[BUFSIZE];
    int bytes_read;

    // Receive message from client
    bytes_read = recv(client_sockfd, buffer, BUFSIZE, 0);
    if (bytes_read == 0) {
        // Client disconnected
        printf("Client disconnected\n");
        close(client_sockfd);
        return;
    }
    printf("Received message from client: %s\n", buffer);

    // Send response to client
    send(client_sockfd, "Thank you for connecting", strlen("Thank you for connecting"), 0);

    // Close client socket
    close(client_sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    // Create socket
    int server_sockfd;
    struct sockaddr_in server_address;
    int opt = 1;
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // Set socket options
    if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        return 1;
    }

    // Set socket address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Binding failed");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_sockfd, MAX_CONN) == -1) {
        perror("Listen failed");
        return 1;
    }

    // Accept incoming connections
    client_t clients[MAX_CONN];
    int num_clients = 0;
    for (;;) {
        struct sockaddr_in client_address;
        socklen_t client_len = sizeof(client_address);

        // Accept connection
        int client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
        if (client_sockfd == -1) {
            perror("Accept failed");
            continue;
        }

        // Add client information to array
        clients[num_clients].sockfd = client_sockfd;
        clients[num_clients].client_address[0] = '\0';
        strcpy(clients[num_clients].client_address, inet_ntoa(client_address.sin_addr));
        clients[num_clients].client_len = client_len;
        num_clients++;

        // Handle client connection
        if (num_clients < MAX_CONN) {
            handle_client(client_sockfd);
        }
    }

    // Cleanup
    for (int i = 0; i < num_clients; i++) {
        close(clients[i].sockfd);
    }
    close(server_sockfd);

    return 0;
}