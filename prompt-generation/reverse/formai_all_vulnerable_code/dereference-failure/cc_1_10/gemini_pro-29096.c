//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 8192

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    const int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    const char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    if (write(sockfd, request, strlen(request)) == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    char buffer[MAX_LINE];
    int bytes_received;
    while ((bytes_received = read(sockfd, buffer, sizeof(buffer))) > 0) {
        // Process the received data here
    }

    if (bytes_received == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    close(sockfd);
    return EXIT_SUCCESS;
}