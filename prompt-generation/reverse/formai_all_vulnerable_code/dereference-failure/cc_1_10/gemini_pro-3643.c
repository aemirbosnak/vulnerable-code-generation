//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the host information
    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *(struct in_addr *)host->h_addr_list[0];

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HTTP request
    char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the HTTP response
    char response[BUFSIZE];
    int bytes_received = recv(sockfd, response, BUFSIZE, 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the HTTP response
    printf("%s", response);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}