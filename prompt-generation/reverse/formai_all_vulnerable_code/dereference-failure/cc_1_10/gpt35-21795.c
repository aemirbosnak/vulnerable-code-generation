//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HEADER_SIZE 2048

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[8192];
    char header[MAX_HEADER_SIZE];
    char *hostname, *path;

    if (argc < 2) {
        fprintf(stderr,"usage %s http://hostname:port/path\n", argv[0]);
        exit(0);
    }

    // Parse the URL to get hostname, port, and path
    char *url = argv[1];
    hostname = strstr(url, "://") + strlen("://");
    char *port_ptr = strstr(hostname, ":");
    char *path_ptr = strstr(hostname, "/");
    if (port_ptr != NULL) {
        *port_ptr++ = '\0';
        portno = atoi(port_ptr);
    } else {
        portno = 80;
    }

    if (path_ptr != NULL) {
        *path_ptr++ = '\0';
        path = path_ptr;
    } else {
        path = "/";
    }

    // Open socket connection
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr)<=0) {
        fprintf(stderr, "Invalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Construct HTTP request header
    snprintf(header, MAX_HEADER_SIZE, "GET /%s HTTP/1.0\r\n"
                                        "Host: %s:%d\r\n"
                                        "User-Agent: HTTPClient/1.0\r\n"
                                        "Accept: */*\r\n\r\n",
                                        path, hostname, portno);
    printf("HTTP Request Header:\n%s\n", header);

    // Write HTTP request header to socket
    n = write(sockfd, header, strlen(header));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read server response and print to console
    memset(buffer, '0', sizeof(buffer));
    while ((n = read(sockfd, buffer, sizeof(buffer)-1)) > 0) {
        printf("%s", buffer);
        memset(buffer, '0', sizeof(buffer));
    }

    if (n < 0) {
        error("ERROR reading from socket");
    }

    close(sockfd);
    return 0;
}