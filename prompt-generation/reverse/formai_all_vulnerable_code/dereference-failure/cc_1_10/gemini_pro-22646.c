//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// Convert a decimal number to a base-n representation.
char *ntoa(int n, int base) {
    if (base < 2 || base > 36) {
        return NULL;  // Invalid base.
    }

    int len = 1;
    int num = n;
    while (num >= base) {
        num /= base;
        len++;
    }

    char *str = malloc(len + 1);
    str[len] = '\0';
    while (n >= base) {
        int rem = n % base;
        str[--len] = rem < 10 ? rem + '0' : rem - 10 + 'a';
        n /= base;
    }
    str[--len] = n < 10 ? n + '0' : n - 10 + 'a';

    return str;
}

// Send a HTTP response to a client.
void send_response(int sockfd, int status_code, char *message) {
    char buffer[1024];
    int len = snprintf(buffer, sizeof(buffer),
        "HTTP/1.1 %d %s\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: %d\r\n"
        "\r\n"
        "%s",
        status_code, message, strlen(message), message);

    send(sockfd, buffer, len, 0);
}

// Handle a HTTP request from a client.
void handle_request(int sockfd) {
    char buffer[1024];
    int n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        return;  // Client closed the connection.
    }

    // Parse the request.
    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check if the request is valid.
    if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
        send_response(sockfd, 400, "Bad Request");
        return;
    }

    // Generate a response.
    char *message = "Hello, world!";
    send_response(sockfd, 200, message);
}

// Start the server on the specified port.
void start_server(int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        int clientfd = accept(sockfd, NULL, NULL);
        if (clientfd < 0) {
            perror("accept");
            continue;
        }

        handle_request(clientfd);
        close(clientfd);
    }

    close(sockfd);
}

int main() {
    start_server(8080);
    return 0;
}