//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    char *url = argv[1];

    // Parse URL
    char *protocol = strtok(url, "://");
    char *host = strtok(NULL, "/");
    char *path = strtok(NULL, "");

    // Set default values
    if (!path) {
        path = "/";
    }
    if (!protocol) {
        protocol = "http";
    }

    // Resolve host IP address
    struct hostent *he = gethostbyname(host);
    if (!he) {
        printf("Error: Cannot resolve host %s\n", host);
        exit(1);
    }
    char *ip = inet_ntoa(*(struct in_addr *)he->h_addr);

    // Connect to server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Cannot create socket\n");
        exit(1);
    }
    struct sockaddr_in servaddr = {0};
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(80);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error: Cannot connect to server\n");
        exit(1);
    }

    // Send HTTP request
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "GET /%s HTTP/1.1\r\n", path);
    sprintf(buffer + strlen(buffer), "Host: %s\r\n", host);
    sprintf(buffer + strlen(buffer), "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:84.0) Gecko/20100101 Firefox/84.0\r\n");
    sprintf(buffer + strlen(buffer), "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n");
    sprintf(buffer + strlen(buffer), "Accept-Language: en-US,en;q=0.5\r\n");
    sprintf(buffer + strlen(buffer), "Connection: close\r\n\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Receive HTTP response
    memset(buffer, 0, BUFFER_SIZE);
    int total_read = 0;
    int n_read;
    while ((n_read = read(sockfd, buffer + total_read, BUFFER_SIZE - total_read - 1)) > 0) {
        total_read += n_read;
    }
    if (n_read < 0) {
        printf("Error: Cannot read from socket\n");
        exit(1);
    }

    // Extract HTTP headers and body
    char *headers = strtok(buffer, "\r\n\r\n");
    char *body = strtok(NULL, "\0");

    // Print HTTP response
    printf("%s\n%s", headers, body);

    // Close socket
    close(sockfd);

    return 0;
}