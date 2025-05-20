//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;
    struct hostent *host;

    if (argc != 2) {
        printf("Please provide the hostname as argument\n");
        return 1;
    }

    if ((host = gethostbyname(argv[1])) == NULL) {
        printf("Error: Invalid hostname %s\n", argv[1]);
        return 1;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    memcpy(&servaddr.sin_addr, host->h_addr_list[0], host->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error: Could not connect to the server\n");
        return 1;
    }

    char request[MAXLINE + 1];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);
    write(sockfd, request, strlen(request));

    while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
    }

    close(sockfd);
    return 0;
}