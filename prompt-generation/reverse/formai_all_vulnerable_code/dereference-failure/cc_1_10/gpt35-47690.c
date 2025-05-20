//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, status;
    struct sockaddr_in server_addr;
    char *http_request, *http_response;
    http_response = (char *) malloc(MAX_BUF_SIZE);

    if (argc != 3) {
        printf("Usage: %s <server_address> <server_port>\n", argv[0]);
        return 1;
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // set server address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("Error setting server address");
        return 1;
    }

    // connect to server
    status = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (status < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // send HTTP request
    http_request = "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n";
    status = send(sockfd, http_request, strlen(http_request), 0);
    if (status < 0) {
        perror("Error sending HTTP request");
        return 1; 
    }

    // receive HTTP response
    status = recv(sockfd, http_response, MAX_BUF_SIZE, 0);
    if (status < 0) {
        perror("Error receiving HTTP response");
        return 1;
    }

    // print HTTP response
    printf("HTTP response:\n%s", http_response);

    // close socket
    close(sockfd);

    return 0;
}