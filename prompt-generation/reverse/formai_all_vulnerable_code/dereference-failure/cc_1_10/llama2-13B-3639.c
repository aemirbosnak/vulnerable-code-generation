//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define PORT_MIN 1024
#define PORT_MAX 65535

// Structure to store information about a connection
struct connection {
    int sock; // Socket descriptor
    char ip_address[16]; // IP address of the client
    unsigned short port; // Port number of the client
};

// Function to create a socket
int create_socket(int domain, int type, int protocol) {
    int sock;
    sock = socket(domain, type, protocol);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to listen for incoming connections
void listen_for_connections(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Listen for incoming connections
    listen(sock, 3);

    // Accept incoming connections
    while (1) {
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Print the IP address and port number of the client
        printf("New client connection from IP address: %s, port %d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Add the client to the list of connections
        struct connection *new_conn = malloc(sizeof(struct connection));
        new_conn->sock = client_sock;
        strcpy(new_conn->ip_address, inet_ntoa(client_addr.sin_addr));
        new_conn->port = ntohs(client_addr.sin_port);
        // ... add more code to handle the client connection here ...
    }
}

// Example program
int main() {
    int sock = create_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    listen_for_connections(sock);
    return 0;
}