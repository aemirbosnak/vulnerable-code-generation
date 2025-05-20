//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: enthusiastic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LINE 4096

int main(int argc, char **argv) {
    int sockfd;
    int port = 80;
    char *host = "www.google.com";
    char request[MAX_LINE], data[MAX_LINE], response[MAX_LINE];
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    // Get server address
    server = gethostbyname(host);
    if (server == NULL) {
        printf("Error: no such host %s\n", host);
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Construct HTTP request
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", host);

    // Send HTTP request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Error sending message\n");
        exit(1);
    }

    // Receive HTTP response
    memset(response, 0, MAX_LINE);
    while (recv(sockfd, data, MAX_LINE, 0) > 0) {
        strcat(response, data);
        memset(data, 0, MAX_LINE);
    }

    // Print HTTP response
    printf("%s\n", response);

    // Close socket
    close(sockfd);

    return 0;
}