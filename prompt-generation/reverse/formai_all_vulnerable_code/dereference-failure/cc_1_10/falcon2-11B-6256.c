//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 4096
#define MAX_CONNECTION_NUM 100

int main(int argc, char *argv[]) {
    // Initialize variables
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;
    int client_socket;
    int server_socket;
    int port;
    int max_connections;

    // Parse command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [port]\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);
    max_connections = atoi(argv[2]);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    client_addr_len = sizeof(client_addr);

    // Create a socket for server
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Failed to create socket\n");
        exit(1);
    }

    // Bind the server socket to a specific address and port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Failed to bind socket\n");
        exit(1);
    }

    listen(server_socket, MAX_CONNECTION_NUM);

    // Accept client connections
    while (1) {
        printf("Waiting for client connection...\n");

        // Accept a client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            fprintf(stderr, "Failed to accept connection\n");
            exit(1);
        }

        printf("Connected to client (%s:%d)\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle client requests
        char buffer[MAX_BUFFER_SIZE];
        char *request;
        char *response;

        request = (char *)malloc(sizeof(char) * MAX_BUFFER_SIZE);
        response = (char *)malloc(sizeof(char) * MAX_BUFFER_SIZE);

        printf("Sending request to server...\n");

        // Read the client request
        read(client_socket, request, MAX_BUFFER_SIZE);

        // Replace the server address with the client address in the request
        strcpy(request, "GET / HTTP/1.1\r\nHost: ");
        strcat(request, inet_ntoa(client_addr.sin_addr));
        strcat(request, " ");
        strcat(request, inet_ntoa(client_addr.sin_addr));

        // Send the modified request to the server
        write(server_socket, request, strlen(request));

        // Read the server response
        read(server_socket, response, MAX_BUFFER_SIZE);

        // Send the server response to the client
        write(client_socket, response, strlen(response));

        // Cleanup
        free(request);
        free(response);

        // Close the client socket
        close(client_socket);
    }

    return 0;
}