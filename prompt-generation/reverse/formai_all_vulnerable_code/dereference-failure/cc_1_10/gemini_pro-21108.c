//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define DEFAULT_HOSTNAME "example.com"
#define DEFAULT_PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Parse command-line arguments.
    char *hostname = DEFAULT_HOSTNAME;
    int port = DEFAULT_PORT;

    if (argc > 1) {
        hostname = argv[1];
    }

    if (argc > 2) {
        port = atoi(argv[2]);
    }

    // Create a socket.
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Connect to the server.
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Send a request to the server.
    char request[] = "GET / HTTP/1.1\r\n\r\n";

    if (send(sock, request, strlen(request), 0) < 0) {
        fprintf(stderr, "Error sending request: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    // Receive a response from the server.
    char buffer[BUFFER_SIZE];

    int bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);

    if (bytes_received < 0) {
        fprintf(stderr, "Error receiving response: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    buffer[bytes_received] = '\0';

    // Print the response to the console.
    printf("%s\n", buffer);

    // Close the socket.
    close(sock);

    return 0;
}