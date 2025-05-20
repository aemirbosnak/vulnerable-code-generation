//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 4096
#define PORT 80
#define USER_AGENT "Custom HTTP Client v1.0"

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void init_address(struct sockaddr_in *addr, const char *hostname) {
    struct hostent *host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        handle_error("gethostbyname() failed");
    }

    memset(addr, 0, sizeof(struct sockaddr_in));
    addr->sin_family = AF_INET;
    addr->sin_port = htons(PORT);
    memcpy(&addr->sin_addr.s_addr, host_info->h_addr_list[0], host_info->h_length);
}

void build_request(char *request, const char *hostname, const char *path) {
    snprintf(request, BUF_SIZE, 
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "User-Agent: %s\r\n"
             "Connection: close\r\n\r\n", 
             path, hostname, USER_AGENT);
}

void send_http_request(int sockfd, const char *request) {
    if (send(sockfd, request, strlen(request), 0) < 0) {
        handle_error("send() failed");
    }
}

void receive_http_response(int sockfd) {
    char buffer[BUF_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, BUF_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';  // Null-terminate buffer
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        handle_error("recv() failed");
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
    struct sockaddr_in server_addr;
    char request[BUF_SIZE];

    // Initialize socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("socket() failed");
    }

    // Initialize server address structure
    init_address(&server_addr, hostname);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("connect() failed");
    }

    // Build the HTTP GET request
    build_request(request, hostname, path);

    // Send the HTTP request
    send_http_request(sockfd, request);

    // Receive and display the HTTP response
    receive_http_response(sockfd);
    
    // Close the socket
    close(sockfd);
    return EXIT_SUCCESS;
}