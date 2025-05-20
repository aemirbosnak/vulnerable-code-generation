//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_http_request(const char *hostname, const char *path) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    int sockfd;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Resolving the hostname to its IP address
    host = gethostbyname(hostname);
    if (host == NULL) {
        error("Error resolving hostname");
    }

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Setting up the server address structure
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, 
          (char *)&server_addr.sin_addr.s_addr,
          host->h_length);
    server_addr.sin_port = htons(80);

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting");
    }

    // Creating the HTTP request
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    
    // Sending the HTTP request to the server
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error("Error sending request");
    }

    // Receiving the response from the server
    printf("Response:\n");
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the buffer
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        error("Error reading response");
    }

    // Closing the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    send_http_request(hostname, path);
    
    return 0;
}