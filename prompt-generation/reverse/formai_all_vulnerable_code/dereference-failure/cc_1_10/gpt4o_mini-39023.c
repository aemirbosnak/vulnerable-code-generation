//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void http_get(const char *hostname, const char *path) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;

    if ((host = gethostbyname(hostname)) == NULL) {
        die("gethostbyname failed");
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("socket failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("connect failed");
    }

    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    
    if (send(sock, request, strlen(request), 0) < 0) {
        die("send failed");
    }

    char response[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sock, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }

    if (bytes_received < 0) {
        die("recv failed");
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    http_get(hostname, path);

    return 0;
}