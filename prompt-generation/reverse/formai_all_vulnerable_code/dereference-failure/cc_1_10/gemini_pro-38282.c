//GEMINI-pro DATASET v1.0 Category: Networking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    // Initialize and check for errors
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(1);
    }

    // Name resolution
    struct hostent *he = gethostbyname("www.google.com");
    if (he == NULL) {
        herror("gethostbyname() failed");
        exit(1);
    }

    // Prepare server address
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr = *((struct in_addr *)he->h_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }

    // Prepare HTTP request
    char *req = "GET /index.html HTTP/1.1\r\n"
                "Host: www.google.com\r\n"
                "Connection: close\r\n"
                "User-Agent: Mozilla/5.0\r\n"
                "\r\n";

    // Send HTTP request
    int n = write(sockfd, req, strlen(req));
    if (n < 0) {
        perror("write() failed");
        exit(1);
    }

    // Receive HTTP response
    char buf[4096];
    while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
        write(STDOUT_FILENO, buf, n);
    }

    if (n < 0) {
        perror("read() failed");
        exit(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}