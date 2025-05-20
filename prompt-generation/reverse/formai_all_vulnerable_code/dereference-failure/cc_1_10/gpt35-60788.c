//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if the user provided enough arguments
    if (argc < 2) {
        printf("Usage: %s <URL/SERVER_NAME>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char request[BUFFER_SIZE], response[BUFFER_SIZE];
    int client_socket, status, bytes;
    struct hostent *server;
    struct sockaddr_in server_address;

    // Parse the URL to extract the server name
    char *server_name = strtok(argv[1], "/");
    // If the URL contains the protocol, ignore it
    if (strstr(server_name, "://")) {
        server_name = strtok(NULL, "/");
    }

    // Resolve the server name to its IP address
    server = gethostbyname(server_name);
    if (server == NULL) {
        printf("Error: Invalid server name.\n");
        exit(EXIT_FAILURE);
    }

    // Create the socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        printf("Error: Failed to create socket.\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    status = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (status < 0) {
        printf("Error: Failed to connect to server.\n");
        exit(EXIT_FAILURE);
    }

    // Build the HTTP request
    snprintf(request, sizeof(request), "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", server_name);

    // Send the request to the server
    bytes = send(client_socket, request, strlen(request), 0);
    if (bytes < 0) {
        printf("Error: Failed to send request to server.\n");
        exit(EXIT_FAILURE);
    }

    // Receive and print the server response
    memset(response, 0, sizeof(response));
    bytes = recv(client_socket, response, sizeof(response), 0);
    if (bytes < 0) {
        printf("Error: Failed to receive response from server.\n");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // Close the socket and exit
    close(client_socket);
    return 0;
}