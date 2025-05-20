//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>

int main() {
    struct hostent *server;
    struct in_addr **addr_list;
    struct sockaddr_in sin;
    struct timeval tv;
    int sockfd, numbytes;
    int i;
    char buf[1024];
    char *url = "http://www.google.com";

    // Convert URL to IPv4 address
    addr_list = gethostbyname(url);
    if (addr_list == NULL) {
        fprintf(stderr, "Error: Host not found\n");
        exit(1);
    }

    server = *addr_list;

    // Create socket and connect to server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Unable to create socket\n");
        exit(1);
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(80);
    bcopy((char *)server->h_addr, (char *)&sin.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("Error: Unable to connect to server\n");
        exit(1);
    }

    // Send HTTP request and receive response
    numbytes = send(sockfd, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n", 53, 0);
    if (numbytes < 0) {
        perror("Error: Unable to send request\n");
        exit(1);
    }

    bzero(buf, 1024);
    numbytes = recv(sockfd, buf, sizeof(buf), 0);
    if (numbytes < 0) {
        perror("Error: Unable to receive response\n");
        exit(1);
    }

    // Check response code
    if (buf[0]!= '1' && buf[0]!= '2') {
        printf("Error: %s\n", buf);
        exit(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}