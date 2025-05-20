//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void print_usage() {
    printf("Usage: ./http_client <hostname> <port> <path>\n");
    printf("Example: ./http_client www.example.com 80 /\n");
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

struct sockaddr_in create_address(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        herror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(port);

    return server_addr;
}

void send_http_request(int sockfd, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n", path);
    
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Failed to send request");
        exit(EXIT_FAILURE);
    }
}

void receive_http_response(int sockfd) {
    char response[BUFFER_SIZE];
    int received_bytes;

    printf("HTTP Response:\n");
    while ((received_bytes = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[received_bytes] = '\0'; // Null-terminate the response
        printf("%s", response);
    }

    if (received_bytes < 0) {
        perror("Failed to receive response");
    }
}

void close_socket(int sockfd) {
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    const char *path = argv[3];

    int sockfd = create_socket();
    struct sockaddr_in server_addr = create_address(hostname, port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close_socket(sockfd);
        return EXIT_FAILURE;
    }

    send_http_request(sockfd, path);
    receive_http_response(sockfd);
    
    close_socket(sockfd);
    return EXIT_SUCCESS;
}