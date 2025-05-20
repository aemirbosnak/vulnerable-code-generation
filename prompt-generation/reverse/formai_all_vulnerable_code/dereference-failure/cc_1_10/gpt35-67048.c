//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: irregular
/* Behold! a unique HTTP client in C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define HOST "www.example.com"
#define PORT 80

int main() {
    int sockfd, n, sent, received, total;
    char buffer[4096], request[2048], response[4096];

    struct sockaddr_in server_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(HOST);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host '%s'\n", HOST);
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    sprintf(request, "GET / HTTP/1.0\r\nHost: %s\r\nUser-Agent: myhttpclient/1.0\r\n\r\n", HOST);

    sent = 0;
    total = strlen(request);
    while (sent < total) {
        n = send(sockfd, request + sent, total - sent, 0);
        if (n == -1) {
            perror("Error sending request");
            exit(EXIT_FAILURE);
        }
        sent += n;
    }

    received = 0;
    total = sizeof(response) - 1;
    memset(response, 0, sizeof(response));

    while (received < total) {
        n = recv(sockfd, response + received, total - received, 0);
        if (n == -1) {
            perror("Error receiving response");
            exit(EXIT_FAILURE);
        }
        if (n == 0) {
            break;
        }
        received += n;
    }

    if (received == total) {
        printf("Error: Response too large\n");
        exit(EXIT_FAILURE);
    }

    close(sockfd);

    printf("Response:\n%s", response);

    return 0;
}