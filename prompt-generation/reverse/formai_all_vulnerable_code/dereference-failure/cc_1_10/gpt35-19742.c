//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, port;
    char *host, *path, *request;
    struct sockaddr_in server_addr;
    char response[BUFFER_SIZE];

    if (argc < 3) {
        printf("Usage: %s <host> <port> <path>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);
    path = argv[3];

    // Initialize socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported \n");
        exit(1);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Connection Failed \n");
        exit(1);
    }

    // Build HTTP request
    request = malloc(BUFFER_SIZE * sizeof(char));
    sprintf(request, "GET %s HTTP/1.1\r\n", path);
    sprintf(request + strlen(request), "Host: %s:%d\r\n", host, port);
    sprintf(request + strlen(request), "Connection: close\r\n");
    sprintf(request + strlen(request), "\r\n");

    // Send HTTP request to server
    if (send(sock, request, strlen(request), 0) < 0) {
        printf("Send failed \n");
        exit(1);
    }

    // Receive HTTP response from server
    if (recv(sock, response, BUFFER_SIZE, 0) < 0) {
        printf("Receive failed \n");
        exit(1);
    }

    printf("%s\n", response);

    free(request);
    close(sock);

    return 0;
}