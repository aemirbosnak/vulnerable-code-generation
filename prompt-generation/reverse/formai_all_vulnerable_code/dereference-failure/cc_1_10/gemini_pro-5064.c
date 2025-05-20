//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    // Get the host's IP address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: Could not resolve host %s\n", argv[1]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Could not create socket");
        return 1;
    }

    // Connect to the host
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: Could not connect to host");
        return 1;
    }

    // Send an HTTP GET request
    char buf[MAX_BUF_SIZE];
    sprintf(buf, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("Error: Could not send HTTP request");
        return 1;
    }

    // Receive the HTTP response
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, buf, MAX_BUF_SIZE, 0)) > 0) {
        printf("%s", buf);
    }

    if (bytes_received < 0) {
        perror("Error: Could not receive HTTP response");
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}