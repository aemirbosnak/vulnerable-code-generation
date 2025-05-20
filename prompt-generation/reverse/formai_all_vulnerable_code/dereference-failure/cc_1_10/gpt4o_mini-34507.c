//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 2048

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int create_socket() {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation failed");
    }
    return sockfd;
}

void connect_to_server(int sockfd, const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Get the host information
    if ((host = gethostbyname(hostname)) == NULL) {
        handle_error("gethostbyname failed");
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to server failed");
    }
}

void send_http_request(int sockfd, const char *hostname) {
    char request[BUFFER_SIZE];

    // Create HTTP GET request
    snprintf(request, sizeof(request),
             "GET / HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             hostname);

    // Send request to the server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        handle_error("send failed");
    }
}

void receive_http_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Read data from the socket
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';  // Null-terminate the received data
        printf("%s", buffer);  // Output the response to stdout
    }

    if (bytes_received < 0) {
        handle_error("recv failed");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    int sockfd;

    // Create a socket
    sockfd = create_socket();

    // Connect to the server
    connect_to_server(sockfd, hostname, port);

    // Send HTTP request
    send_http_request(sockfd, hostname);

    // Receive HTTP response
    receive_http_response(sockfd);

    // Close the socket
    close(sockfd);
    return 0;
}