//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert host string to IP address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Create a socket for communication
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the socket address structure
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    memmove(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send a HTTP request
    char *request = "GET / HTTP/1.1\r\n\
Host: www.example.com\r\n\
Connection: close\r\n\
\r\n";
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the HTTP response
    char *buf = malloc(1024);
    memset(buf, 0, 1024);
    int n = recv(sockfd, buf, 1023, 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the HTTP response
    printf("%s\n", buf);

    // Cleanup
    free(buf);
    close(sockfd);

    return EXIT_SUCCESS;
}