//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: irregular
// Firewall Frenzy! 🔥🔨

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_CLIENT_LENGTH 1024
#define MAX_PACKET_LENGTH 1024

struct client_info {
    char *ip;
    char *port;
};

int main() {
    int listen_fd, client_fd;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buffer[MAX_PACKET_LENGTH];
    int bytes_recv, bytes_sent;

    // Create the listening socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("Error creating listening socket");
        exit(1);
    }

    // Set up the listening socket address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    // Bind the listening socket to the address and port
    if (bind(listen_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error binding listening socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_fd, 3) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        // Accept an incoming connection
        client_fd = accept(listen_fd, (struct sockaddr *)&client, &client_len);
        if (client_fd == -1) {
            perror("Error accepting incoming connection");
            exit(1);
        }

        printf("Connection accepted from IP address: %s and port: %d\n",
               inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Read data from the client
        bytes_recv = recv(client_fd, buffer, MAX_PACKET_LENGTH, 0);
        if (bytes_recv == -1) {
            perror("Error reading data from client");
            exit(1);
        }

        // Check if the client's IP address is in the list of allowed IPs
        if (strcmp(client.sin_addr.s_addr, "192.168.1.1") == 0) {
            // Allow the connection and print the received data
            printf("Received data from client: %s\n", buffer);
        } else {
            // Drop the connection and print an error message
            printf("Drop connection from unauthorized IP address: %s\n",
                   inet_ntoa(client.sin_addr));
            close(client_fd);
        }

        // Send a response back to the client
        bytes_sent = send(client_fd, "Hello, client! 😊", 13, 0);
        if (bytes_sent == -1) {
            perror("Error sending data to client");
            exit(1);
        }

        // Close the client socket
        close(client_fd);
    }

    return 0;
}