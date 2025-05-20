//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

void proxy(int client_socket, char *host, int port) {
    int server_socket, i;
    struct sockaddr_in server_address;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Resolve hostname
    struct hostent *server;
    server = gethostbyname(host);
    if (server == NULL) {
        perror("Error: Host not found");
        exit(1);
    }

    // Build server address
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port);

    // Connect to server
    if (connect(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Forward traffic between client and server
    char buffer[BUFFER_SIZE];
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        i = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (i <= 0) {
            break;
        }
        send(server_socket, buffer, i, 0);
    }

    close(server_socket);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s [proxy-port] [remote-host] [remote-port]\n", argv[0]);
        exit(1);
    }

    int proxy_port = atoi(argv[1]);
    char *host = argv[2];
    int remote_port = atoi(argv[3]);

    // Create socket
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_length;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Set socket options
    int optval = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (const void *) &optval, sizeof(int));

    // Bind socket
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(proxy_port);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    listen(server_socket, 5);
    printf("Waiting for connections on port %d...\n", proxy_port);

    // Handle incoming connections
    client_length = sizeof(client_address);
    while (1) {
        // Accept connection
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_length);
        if (client_socket < 0) {
            perror("Error accepting connection");
            exit(1);
        }
        printf("Accepted connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Handle incoming traffic
        proxy(client_socket, host, remote_port);

        close(client_socket);
        printf("Closed connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    }

    close(server_socket);

    return 0;
}