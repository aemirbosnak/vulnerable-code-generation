//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    char *host;
    int port;
    char *path;
} url_t;

url_t parseUrl(char *url) {
    url_t result;
    char *host, *path;
    int port = 80;

    host = strtok(url, "/");
    result.host = host;

    path = strtok(NULL, "");
    if (path == NULL) {
        path = "/";
    } else if (strstr(path, "://") != NULL) {
        path = strstr(path, "/");
        result.host = strtok(host, ":");
        port = atoi(strtok(NULL, ""));
    }
    result.port = port;
    result.path = path;

    return result;
}

void sendHttpRequest(url_t url) {
    int sock;
    struct sockaddr_in server;
    char *message, response[MAX_BUFFER_SIZE];
    int messageSize, readSize;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket.");
        exit(1);
    }
    server.sin_addr.s_addr = inet_addr(url.host);
    server.sin_family = AF_INET;
    server.sin_port = htons(url.port);

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Failed to connect to server.");
        exit(1);
    }

    // Send HTTP request
    message = malloc(MAX_BUFFER_SIZE);
    memset(message, 0, MAX_BUFFER_SIZE);
    snprintf(message, MAX_BUFFER_SIZE, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", url.path, url.host);
    messageSize = strlen(message);
    if (send(sock, message, messageSize, 0) < 0) {
        perror("Failed to send HTTP request.");
        exit(1);
    }

    // Receive server response
    readSize = recv(sock, response, MAX_BUFFER_SIZE, 0);
    while (readSize > 0) {
        printf("%.*s", readSize, response);
        memset(response, 0, MAX_BUFFER_SIZE);
        readSize = recv(sock, response, MAX_BUFFER_SIZE, 0);
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s url\n", argv[0]);
        return 0;
    }

    url_t url = parseUrl(argv[1]);
    printf("Host: %s, Port: %d, Path: %s\n", url.host, url.port, url.path);

    sendHttpRequest(url);

    return 0;
}