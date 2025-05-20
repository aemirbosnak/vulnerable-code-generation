//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_SIZE 1024

// Some helpful macros
#define HTTP_GET "GET / HTTP/1.1\r\nHost: %s\r\n\r\n"
#define HTTP_POST "POST / HTTP/1.1\r\nHost: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %d\r\n\r\n%s"

int main(int argc, char **argv) {
    // Check if there are enough arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the host and port from the arguments
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket for the connection
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Resolve the hostname to an IP address
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Create a sockaddr_in structure for the server's address
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr = *((struct in_addr *)hostent->h_addr_list[0]);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the HTTP request to the server
    int n = 0;
    if ((n = send(sockfd, HTTP_GET, strlen(HTTP_GET), 0)) < 0) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the HTTP response from the server
    char buffer[MAX_SIZE];
    memset(buffer, 0, MAX_SIZE);
    while ((n = recv(sockfd, buffer, MAX_SIZE, 0)) > 0) {
        fwrite(buffer, 1, n, stdout);
    }
    if (n < 0) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}