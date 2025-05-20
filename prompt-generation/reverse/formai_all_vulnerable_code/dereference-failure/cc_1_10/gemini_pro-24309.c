//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

// Define the maximum size of the request and response buffers
#define REQUEST_BUFFER_SIZE 4096
#define RESPONSE_BUFFER_SIZE 8192

// Create a socket for communication with the server
int create_socket(const char *hostname, int port) {
    // Get the IP address of the server
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return -1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        return -1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return -1;
    }

    return sockfd;
}

// Send a request to the server
int send_request(int sockfd, const char *request) {
    // Send the request
    int bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent < 0) {
        perror("send");
        return -1;
    }

    return 0;
}

// Receive a response from the server
int receive_response(int sockfd, char *response, int response_size) {
    // Receive the response
    int bytes_received = recv(sockfd, response, response_size, 0);
    if (bytes_received < 0) {
        perror("recv");
        return -1;
    }

    return bytes_received;
}

// Print the response from the server
void print_response(char *response, int response_size) {
    // Print the response
    printf("%s", response);
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Get the hostname and port from the arguments
    const char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = create_socket(hostname, port);
    if (sockfd < 0) {
        return 1;
    }

    // Send a request to the server
    const char *request = "GET / HTTP/1.1\nHost: example.com\n\n";
    if (send_request(sockfd, request) < 0) {
        return 1;
    }

    // Receive a response from the server
    char response[RESPONSE_BUFFER_SIZE];
    int response_size = receive_response(sockfd, response, RESPONSE_BUFFER_SIZE);
    if (response_size < 0) {
        return 1;
    }

    // Print the response from the server
    print_response(response, response_size);

    // Close the socket
    close(sockfd);

    return 0;
}