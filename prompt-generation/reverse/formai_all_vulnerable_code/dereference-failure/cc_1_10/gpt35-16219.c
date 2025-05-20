//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *url = argv[1];

    // Find hostname and path
    char hostname[BUF_SIZE];
    char path[BUF_SIZE];
    sscanf(url, "http://%[^/]/%s", hostname, path);

    struct hostent *server = gethostbyname(hostname);

    if (server == NULL) {
        fprintf(stderr, "ERROR: Could not resolve hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: Could not connect to server");
        exit(EXIT_FAILURE);
    }

    // Send HTTP request
    char request[BUF_SIZE];
    sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("ERROR: Could not send request");
        exit(EXIT_FAILURE);
    }

    // Receive response
    char response[BUF_SIZE];
    int n;
    while ((n = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[n] = '\0';
        printf("%s", response);
    }
    if (n < 0) {
        perror("ERROR: Could not receive response");
        exit(EXIT_FAILURE);
    }

    // Close socket
    close(sockfd);

    return 0;
}