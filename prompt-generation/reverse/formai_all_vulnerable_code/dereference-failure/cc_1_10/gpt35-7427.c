//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    struct sockaddr_in server_address;
    int socket_fd, response_length, bytes_received;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd < 0) {
        perror("socket() failed");
        exit(1);
    }

    // Initialize server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);

    // Resolve domain name to IP address
    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        printf("Unable to resolve hostname '%s'\n", argv[1]);
        exit(1);
    }
    memcpy(&server_address.sin_addr, host->h_addr_list[0], host->h_length);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect() failed");
        close(socket_fd);
        exit(1);
    }

    // Build HTTP request message
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);

    // Send HTTP request to server
    if (send(socket_fd, request, strlen(request), 0) < 0) {
        perror("send() failed");
        close(socket_fd);
        exit(1);
    }

    // Receive HTTP response from server
    response_length = 0;
    while ((bytes_received = recv(socket_fd, response + response_length, BUFFER_SIZE - response_length, 0)) > 0) {
        response_length += bytes_received;
        if (response_length >= BUFFER_SIZE - 1) {
            printf("Error: Response too large\n");
            close(socket_fd);
            exit(1);
        }
    }

    if (bytes_received < 0) {
        printf("Error: recv() failed\n");
        close(socket_fd);
        exit(1);
    }

    // Null-terminate the response string
    response[response_length] = '\0';

    printf("HTTP Response:\n%s\n", response);

    // Close the socket
    close(socket_fd);

    return 0;
}