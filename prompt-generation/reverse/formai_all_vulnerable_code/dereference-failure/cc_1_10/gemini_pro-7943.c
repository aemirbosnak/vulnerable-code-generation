//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct hostent* hostinfo = gethostbyname(argv[1]);
    if (hostinfo == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, hostinfo->h_addr, hostinfo->h_length);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char request[] = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    if (write(sockfd, request, strlen(request)) == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    char response[1024];
    int bytes_read = read(sockfd, response, sizeof(response) - 1);
    if (bytes_read == -1) {
        perror("read");
        return EXIT_FAILURE;
    }
    response[bytes_read] = '\0';

    printf("%s", response);

    close(sockfd);

    return EXIT_SUCCESS;
}