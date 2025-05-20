//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Creating socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    // Configuring server address structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) == 0) {
        printf("Invalid address\n");
        exit(EXIT_FAILURE);
    }

    // Connecting to server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Sending HTTP request
    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s:%s\r\nConnection: close\r\n\r\n", argv[1], argv[2]);
    send(client_socket, request, strlen(request), 0);

    // Receiving HTTP response
    char response[1024];
    int response_length = recv(client_socket, response, 1024, 0);
    if (response_length < 0) {
        printf("Failed to receive response\n");
        exit(EXIT_FAILURE);
    }

    // Printing HTTP response
    printf("HTTP Response:\n\n");
    for (int i = 0; i < response_length; i++) {
        if (isprint(response[i])) {
            printf("%c", response[i]);
        } else {
            printf("\\x%02x", response[i]);
        }
    }

    // Closing socket
    close(client_socket);
    
    return 0;
}