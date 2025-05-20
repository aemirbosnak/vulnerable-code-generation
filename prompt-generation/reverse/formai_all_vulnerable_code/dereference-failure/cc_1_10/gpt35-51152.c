//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char *host, *port, *path, *headers;
    char buf[BUFSIZE];
    struct addrinfo hints, *res, *p;

    // Parse command-line arguments
    if (argc != 4) {
        printf("Usage: %s host port path\n", argv[0]);
        exit(1);
    }
    host = argv[1];
    port = argv[2];
    path = argv[3];

    // Set up hints for getaddrinfo
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get list of possible addresses for given host/port
    if (getaddrinfo(host, port, &hints, &res) != 0) {
        printf("Unable to resolve %s:%s\n", host, port);
        exit(1);
    }

    // Loop through results and connect to first successful one
    for (p = res; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) continue;

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        break; // Connected successfully
    }
    if (p == NULL) {
        printf("Unable to connect to %s:%s\n", host, port);
        exit(1);
    }

    // Construct GET request
    headers = "Host: %s\r\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:89.0) Gecko/20100101 Firefox/89.0\r\nAccept: */*";
    snprintf(buf, BUFSIZE, "GET %s HTTP/1.1\r\n%s\r\n\r\n", path, headers);
    
    // Send GET request
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        printf("Error sending data\n");
        exit(1);
    }

    // Receive HTTP response and print it to stdout
    memset(buf, 0, BUFSIZE);
    while ((n = recv(sockfd, buf, BUFSIZE - 1, 0)) > 0) {
        fwrite(buf, 1, n, stdout);
        memset(buf, 0, BUFSIZE);
    }

    // Clean up
    close(sockfd);
    freeaddrinfo(res);

    return 0;
}