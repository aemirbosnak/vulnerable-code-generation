//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host as %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error: could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    char *http_request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char request[BUFFER_SIZE];
    sprintf(request, http_request, hostname);

    if (write(sockfd, request, strlen(request)) < 0) {
        fprintf(stderr, "Error: could not write to socket\n");
        exit(EXIT_FAILURE);
    }

    char response[BUFFER_SIZE];
    int total_bytes_read = 0;
    int bytes_read;
    while ((bytes_read = read(sockfd, response + total_bytes_read, BUFFER_SIZE - total_bytes_read - 1)) > 0) {
        total_bytes_read += bytes_read;
    }

    if (bytes_read < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        exit(EXIT_FAILURE);
    }

    response[total_bytes_read] = '\0';
    printf("%s", response);

    close(sockfd);
    return 0;
}