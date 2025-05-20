//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024

// Function to create a new socket
int create_socket(int *sockfd, char *ip_address, int port) {
    struct sockaddr_in server_address;

    // Create socket
    if((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    // Set server_address values
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if(inet_pton(AF_INET, ip_address, &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }

    // Connect to server_address
    if(connect(*sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection error");
        return -1;
    }

    return 0;
}

// Function to send a HTTP GET request
void send_request(int sockfd, char *host, char *path) {
    char request[MAXLINE];

    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
    write(sockfd, request, strlen(request));
}

// Function to receive the HTTP response
void receive_response(int sockfd) {
    char response[MAXLINE];
    int n;

    while((n = read(sockfd, response, MAXLINE-1)) > 0) {
        response[n] = '\0';
        printf("%s", response);
    }
}

// Main function
int main(int argc, char *argv[]) {
    int sockfd, port;
    char *ip_address, *host, *path;

    if(argc != 4) {
        printf("Usage: %s <IP address> <Port> <path>\n", argv[0]);
        exit(1);
    }

    ip_address = argv[1];
    port = atoi(argv[2]);
    path = argv[3];
    host = strtok(argv[3], "/");

    if(create_socket(&sockfd, ip_address, port) == 0) {
        send_request(sockfd, host, path);
        receive_response(sockfd);
        close(sockfd);
    }

    return 0;
}