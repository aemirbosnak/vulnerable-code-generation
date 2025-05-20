//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80

int main() {
    int sockfd, bytes_sent;
    struct sockaddr_in servaddr;
    char buffer[256], request[256], response[256];
    struct hostent *server;
    struct sockaddr_in server_address;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    memset((char *) &servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    strcpy(request, "GET / HTTP/1.1\r\n");
    strcat(request, "Host: www.google.com\r\n\r\n");

    bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent < 0) {
        perror("send failed");
        exit(1);
    }

    bytes_sent = recv(sockfd, response, 256, 0);
    if (bytes_sent < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("Response: %s\n", response);

    close(sockfd);
    return 0;
}