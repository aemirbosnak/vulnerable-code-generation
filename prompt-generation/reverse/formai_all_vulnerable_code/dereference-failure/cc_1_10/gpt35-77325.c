//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    // Check that a valid IP address and port number have been supplied
    if (argc != 3) {
        printf("Usage: %s <Server IP> <Server Port>\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_address.sin_addr);

    // Create a socket for the client
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        printf("Error creating socket.\n");
        exit(1);
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    // Send an HTTP request to the server
    char *http_request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    int bytes_sent = send(client_socket, http_request, strlen(http_request), 0);
    if (bytes_sent < 0) {
        printf("Error sending data.\n");
        exit(1);
    }

    // Receive the server's HTTP response
    char server_response[1024];
    memset(server_response, 0, sizeof(server_response));
    int bytes_received = recv(client_socket, server_response, sizeof(server_response), 0);
    if (bytes_received < 0) {
        printf("Error receiving data.\n");
        exit(1);
    }

    printf("Server Response:\n%s", server_response);

    // Close the client socket
    close(client_socket);

    return 0;
}