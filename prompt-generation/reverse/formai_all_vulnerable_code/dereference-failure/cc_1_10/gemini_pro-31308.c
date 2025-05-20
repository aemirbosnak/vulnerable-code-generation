//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Get the host and port from the command line arguments.
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 2;
    }

    // Get the host's IP address.
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        herror("gethostbyname");
        return 3;
    }

    // Connect to the host.
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr, he->h_addr, he->h_length);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 4;
    }

    // Send a request to the host.
    char request[] = "GET / HTTP/1.1\r\n\r\n";
    if (write(sockfd, request, strlen(request)) < 0) {
        perror("write");
        return 5;
    }

    // Receive a response from the host.
    char buffer[1024];
    int n;
    while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        printf("%s", buffer);
    }
    if (n < 0) {
        perror("read");
        return 6;
    }

    // Close the socket.
    close(sockfd);

    return 0;
}