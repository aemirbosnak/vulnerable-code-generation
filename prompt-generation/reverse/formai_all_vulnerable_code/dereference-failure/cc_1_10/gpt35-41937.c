//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: unable to resolve hostname \"%s\"\n", hostname);
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_address = {
        .sin_family = AF_INET,
        .sin_port = htons(80),
        .sin_addr = *((struct in_addr *) host->h_addr)
    };

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: failed to create socket");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error: failed to connect to server");
        close(sockfd);
        return EXIT_FAILURE;
    }

    char request[BUFFER_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);
    ssize_t bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent < 0) {
        perror("Error: failed to send request");
        close(sockfd);
        return EXIT_FAILURE;
    }

    char response[BUFFER_SIZE];
    ssize_t bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Error: failed to receive response");
        close(sockfd);
        return EXIT_FAILURE;
    }
    response[bytes_received] = '\0';

    printf("Response:\n%s", response);

    close(sockfd);
    return EXIT_SUCCESS;
}