//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024

int build_connection(char *server_address, int port) {
    // Create a new socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(port);
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        exit(1);
    }

    return sockfd;
}

void send_request(int sockfd, char *method, char *path, char *host) {
    // Build the HTTP request
    char request[MAX_BUFFER_SIZE];
    sprintf(request, "%s %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", method, path, host);
    printf("Request:\n%s", request);

    // Send the request to the server
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(1);
    }
}

void receive_response(int sockfd) {
    // Receive the response from the server
    char response[MAX_BUFFER_SIZE];
    int len = recv(sockfd, response, MAX_BUFFER_SIZE, 0);
    if (len == -1) {
        perror("recv");
        exit(1);
    }

    // Print the response from server
    printf("Response:\n");
    fwrite(response, len, 1, stdout);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <server_address> <port> <path>\n", argv[0]);
        return 1;
    }

    // Extract the server_address, port and path from the command-line arguments
    char *server_address = argv[1];
    int port = atoi(argv[2]);
    char *path = argv[3];

    // Build the connection
    int sockfd = build_connection(server_address, port);

    // Send the HTTP GET request to the server
    send_request(sockfd, "GET", path, server_address);

    // Receive the HTTP response from the server
    receive_response(sockfd);

    // Close the socket
    close(sockfd);

    return 0;
}