//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 4096 // Maximum size of the buffer used for receiving data

// Function to handle communication between client and server
void handle_communication(int client_socket, int server_socket){

    char buffer[BUF_SIZE];
    int read_size;

    while ((read_size = recv(client_socket, buffer, BUF_SIZE, 0)) > 0) {

        if (send(server_socket, buffer, read_size, 0) < 0) {
            perror("Error sending data to server");
            break;
        }

        memset(buffer, 0, BUF_SIZE);

        if (recv(server_socket, buffer, BUF_SIZE, 0) < 0) {
            perror("Error receiving data from server");
            break;
        }

        if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
            perror("Error sending data to client");
            break;
        }

        memset(buffer, 0, BUF_SIZE);
    }

    close(client_socket);
    close(server_socket);
}

int main(int argc, char **argv){

    if (argc != 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    // Set up a socket for incoming client connections
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    // Allow reuse of the server port
    int reuse = 1;

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("Error setting socket options");
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address,0,sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the server socket to the local address and port
    if (bind(server_socket, (const struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket to local address");
        exit(1);
    }

    // Listen for incoming client connections
    if (listen(server_socket, 10) < 0) {
        perror("Error listening for client connections");
        exit(1);
    }

    printf("Proxy server running on port %d\n", port);

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_len = sizeof(client_address);

        // Accept incoming client connections
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_len);

        if (client_socket < 0) {
            perror("Error accepting client connection");
            exit(1);
        }

        char *ip = inet_ntoa(client_address.sin_addr);
        int client_port = ntohs(client_address.sin_port);

        printf("Received connection from %s:%d\n", ip, client_port);

        // Set up a socket for communication with the remote server
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);

        if (server_socket < 0) {
            perror("Error creating server socket for remote server");
            close(client_socket);
            continue;
        }

        struct hostent *host = gethostbyname(argv[2]);

        if (host == NULL) {
            printf("Error resolving host %s : %s\n", argv[2], strerror(errno));
            close(server_socket);
            close(client_socket);
            continue;
        }

        struct sockaddr_in server_address;
        memset(&server_address,0,sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(80);
        server_address.sin_addr = *((struct in_addr*) host->h_addr);

        // Connect to the remote server
        if (connect(server_socket, (const struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
            perror("Error connecting to remote server");
            close(server_socket);
            close(client_socket);
            continue;
        }

        // Handle the communication between client and server
        handle_communication(client_socket, server_socket);
    }

    return 0;
}