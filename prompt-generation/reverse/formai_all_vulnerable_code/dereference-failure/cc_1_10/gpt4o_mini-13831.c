//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void initiate_http_client(const char *hostname, const char *path) {
    struct sockaddr_in server_addr;
    struct hostent *server;
    int sockfd;
    char buffer[BUFFER_SIZE];
    
    // Resolve hostname to IP address
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Prepare the server address struct
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(80); // HTTP default port

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    // Prepare HTTP GET request
    snprintf(buffer, sizeof(buffer),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, hostname);

    // Send the request
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error("ERROR sending request");
    }

    // Read the response
    printf("Response received:\n");
    bzero(buffer, BUFFER_SIZE);
    while (recv(sockfd, buffer, sizeof(buffer) - 1, 0) > 0) {
        printf("%s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }

    // Clean up
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    printf("Initiating HTTP Client for %s%s...\n", hostname, path);
    initiate_http_client(hostname, path);
    
    printf("\nHTTP Client has successfully finished.\n");
    return 0;
}