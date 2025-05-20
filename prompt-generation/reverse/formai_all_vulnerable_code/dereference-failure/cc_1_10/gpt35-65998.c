//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 80

int main(int argc, char *argv[]) {
    int sock_fd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    if (argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Get server by hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error resolving hostname: %s\n", strerror(h_errno));
        exit(1);
    }

    // Set server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *) server->h_addr);
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    // Prepare HTTP request
    char request[1024];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);

    // Send HTTP request to server
    if (send(sock_fd, request, strlen(request), 0) < 0) {
        printf("Error sending request to server: %s\n", strerror(errno));
        exit(1);
    }

    // Receive HTTP response from server and print to stdout
    char response_buf[1024];
    int n;
    while ((n = recv(sock_fd, response_buf, sizeof(response_buf), 0)) > 0) {
        fwrite(response_buf, 1, n, stdout);
    }

    // Close socket
    close(sock_fd);

    return 0;
}