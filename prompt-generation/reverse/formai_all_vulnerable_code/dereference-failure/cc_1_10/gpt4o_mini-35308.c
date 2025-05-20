//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define PORT 80
#define MAX_RETRIES 3

void die_with_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int open_connection(const char *hostname, int port) {
    struct sockaddr_in server_address;
    struct hostent *host_info;
    int sockfd;

    if ((host_info = gethostbyname(hostname)) == NULL) {
        die_with_error("Failed to resolve hostname");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die_with_error("Failed to create socket");
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    memcpy(&server_address.sin_addr.s_addr, host_info->h_addr, host_info->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        close(sockfd);
        die_with_error("Failed to connect to server");
    }

    return sockfd;
}

void send_http_request(int sockfd, const char *hostname, const char *path) {
    char request[BUFFER_SIZE];

    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\n"
                                       "Host: %s\r\n"
                                       "Connection: close\r\n\r\n", path, hostname);
    
    if (send(sockfd, request, strlen(request), 0) < 0) {
        die_with_error("Failed to send request");
    }
}

void read_http_response(int sockfd) {
    char response[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }

    if (bytes_received < 0) {
        die_with_error("Failed to receive response");
    }
}

void close_connection(int sockfd) {
    if (close(sockfd) < 0) {
        die_with_error("Failed to close socket");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *path = argv[2];
    int sockfd;

    for (int attempt = 1; attempt <= MAX_RETRIES; attempt++) {
        sockfd = open_connection(hostname, PORT);
        if (sockfd >= 0) {
            send_http_request(sockfd, hostname, path);
            read_http_response(sockfd);
            close_connection(sockfd);
            break;
        } else {
            fprintf(stderr, "Attempt %d: Unable to connect to %s, retrying...\n", attempt, hostname);
            usleep(1000000); // Wait for 1 second before retrying
        }
    }

    return EXIT_SUCCESS;
}