//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 80
#define BUFFSIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;
    struct timeval timeout;
    char buffer[BUFFSIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((server = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Unknown host\n");
        exit(EXIT_FAILURE);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(struct timeval));

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    if ((n = send(sockfd, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1], argv[1])) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    if ((n = recv(sockfd, buffer, BUFFSIZE, 0)) <= 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    close(sockfd);

    return 0;
}