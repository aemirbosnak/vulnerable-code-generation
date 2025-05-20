//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: imaginative
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

int create_socket() {
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("Socket creation failed");
    }

    return sockfd;
}

struct sockaddr_in resolve_host(const char *host) {
    struct sockaddr_in server_addr;
    struct hostent *host_info;

    host_info = gethostbyname(host);
    if (host_info == NULL) {
        die("Could not resolve host");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);
    server_addr.sin_port = htons(80);

    return server_addr;
}

void send_http_request(int sockfd, const char *host, const char *path) {
    char request[BUFFER_SIZE];

    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        die("Failed to send HTTP request");
    }
}

void receive_http_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        die("Failed to receive response");
    }
}

void http_client(const char *url) {
    char host[256], path[256];
    int sockfd;
    struct sockaddr_in server_addr;

    // Parse the URL
    if (sscanf(url, "http://%255[^/]/%255s", host, path) < 2) {
        strncpy(path, "", sizeof(path)); // Default path
        sscanf(url, "http://%255[^/]", host);
    }

    sockfd = create_socket();
    server_addr = resolve_host(host);
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection to server failed");
    }

    send_http_request(sockfd, host, path);
    receive_http_response(sockfd);
    
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Welcome to the Mystic HTTP Client!\n");
    printf("Connecting to %s...\n", argv[1]);
    http_client(argv[1]);
    printf("\nThank you for using the Mystic HTTP Client! Farewell!\n");

    return 0;
}