//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        return 1;
    }

    // Send a GET request
    char request[512];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    write(sockfd, request, strlen(request));

    // Receive the response
    char response[1024];
    memset(response, 0, sizeof(response));
    int n = read(sockfd, response, sizeof(response));
    if (n < 0) {
        fprintf(stderr, "Error reading from server\n");
        return 1;
    }

    // Print the response
    printf("%s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}