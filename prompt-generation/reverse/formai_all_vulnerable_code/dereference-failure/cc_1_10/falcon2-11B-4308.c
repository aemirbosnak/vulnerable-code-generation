//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: peaceful
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <time.h>

int main() {
    struct sockaddr_in addr;
    struct hostent *server;
    struct timeval timeout;
    int sockfd, n;
    char buf[1024];

    // Initialize the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set the timeout for the socket
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    // Set the server address
    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname() failed\n");
        exit(1);
    }
    memcpy(&addr.sin_addr, server->h_addr, server->h_length);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send the ping request
    n = send(sockfd, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n"), 0);
    if (n < 0) {
        perror("send failed");
        exit(1);
    }

    // Receive the response
    bzero(buf, sizeof(buf));
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv failed");
        exit(1);
    }

    // Print the response
    printf("Response:\n%s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}