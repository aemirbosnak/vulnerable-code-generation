//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 4096

void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        error("Usage: ./http_client <url>");
    }

    char* url = argv[1];
    char* host = NULL;
    char* path = NULL;
    int port = 80;

    // Parse URL
    char* protocol_prefix = strtok(url, ":/");
    if (strcmp(protocol_prefix, "http") != 0) {
        error("Unsupported protocol");
    }
    host = strtok(NULL, "/");
    path = strtok(NULL, "\0");
    if (path == NULL) {
        path = "";
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("Unable to create socket");
    }

    // Resolve IP address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    struct in_addr addr;
    if (inet_pton(AF_INET, host, &addr) != 1) {
        error("Invalid IP address");
    }
    server_addr.sin_addr = addr;

    // Connect to server
    if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        error("Unable to connect to server");
    }

    // Send HTTP GET request
    char* request_fmt = "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n";
    char request[strlen(request_fmt) + strlen(path) + strlen(host)];
    sprintf(request, request_fmt, path, host);
    if (send(sock, request, strlen(request), 0) == -1) {
        error("Failed to send request");
    }

    // Receive response
    char buf[BUF_SIZE];
    int bytes_received = 0;
    while (true) {
        int n = recv(sock, &buf[bytes_received], BUF_SIZE - bytes_received, 0);
        if (n == -1) {
            error("Failed to receive data");
        }
        if (n == 0) {
            break; // Connection closed
        }
        bytes_received += n;
    }
    buf[bytes_received] = '\0';

    // Output response
    printf("%s", buf);

    // Cleanup
    close(sock);

    return 0;
}