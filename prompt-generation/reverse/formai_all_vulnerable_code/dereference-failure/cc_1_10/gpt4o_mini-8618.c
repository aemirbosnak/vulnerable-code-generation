//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void print_usage(const char *program_name) {
    printf("Usage: %s <hostname> <port> <path>\n", program_name);
}

int create_socket(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Get the host information
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: Unable to find host %s\n", hostname);
        return -1;
    }

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Unable to create socket");
        return -1;
    }

    // Setting up the server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: Unable to connect to server");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

void send_http_request(int sockfd, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n", path);
    send(sockfd, request, strlen(request), 0);
}

void receive_http_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int received_bytes;

    while ((received_bytes = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[received_bytes] = '\0'; // Null terminate buffer
        printf("%s", buffer);
    }

    if (received_bytes < 0) {
        perror("Error: Unable to receive response");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    const char *path = argv[3];

    int sockfd = create_socket(hostname, port);
    if (sockfd < 0) {
        return EXIT_FAILURE;
    }

    send_http_request(sockfd, path);
    receive_http_response(sockfd);
    
    close(sockfd);
    return EXIT_SUCCESS;
}