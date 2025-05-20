//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define PORT_RANGE 1024

int main(void) {
    int sock = 0;
    struct sockaddr_in server_addr;
    socklen_t client_len = sizeof(struct sockaddr_in);
    char *host = "127.0.0.1"; // Replace with target host
    int port = 80; // Replace with target port

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set address and port of the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, client_len) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Send a request to the server
    char request[] = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char *host_str = host;
    char *req = malloc(strlen(request) + strlen(host_str) + 1);
    sprintf(req, request, host_str);
    send(sock, req, strlen(req), 0);

    // Receive the response from the server
    char buffer[4096];
    recv(sock, buffer, 4096, 0);

    // Print the response
    printf("Received response: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}