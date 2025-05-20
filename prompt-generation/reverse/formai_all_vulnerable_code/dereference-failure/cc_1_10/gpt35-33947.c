//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char *http_request(char *host, char *page) {
    int socket_fd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char *http_request;
    char *http_response;
    int bytes_read;
    int port = 80;

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get server information
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host\n");
        exit(1);
    }

    // Setup sockaddr_in struct
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(socket_fd,(struct sockaddr *) &server_addr,sizeof(server_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    // Construct HTTP request
    http_request = malloc(strlen(page) + strlen(host) + 26);
    sprintf(http_request, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", page, host);

    // Send HTTP request
    if (send(socket_fd, http_request, strlen(http_request), 0) == -1) {
        perror("Error sending request");
        exit(1);
    }

    // Read HTTP response
    http_response = malloc(BUFFER_SIZE);
    bytes_read = recv(socket_fd, http_response, BUFFER_SIZE-1, 0);
    if (bytes_read == -1) {
        perror("Error receiving response");
        exit(1);
    }
    http_response[bytes_read] = '\0';

    // Close socket
    close(socket_fd);

    return http_response;
}

int main() {
    char *host = "www.example.com";
    char *page = "index.html";
    char *http_response = http_request(host, page);

    printf("%s", http_response);

    free(http_response);
    return 0;
}