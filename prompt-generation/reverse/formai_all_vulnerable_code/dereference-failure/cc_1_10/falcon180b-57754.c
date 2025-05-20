//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT "80"
#define HTTP_REQUEST "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n"

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, opt, addrlen, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    char hostname[256];
    int n;
    struct hostent *server;

    if (argc!= 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);
    portno = atoi(PORT);

    if ((server = gethostbyname(hostname)) == NULL) {
        printf("No such host\n");
        exit(1);
    }

    if (server->h_addrtype!= AF_INET) {
        printf("Not an IPv4 address\n");
        exit(1);
    }

    bcopy(server->h_addr, &serv_addr.sin_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to %s\n", argv[1]);

    while (1) {
        bzero(buffer, BUF_SIZE);
        n = read(sockfd, buffer, BUF_SIZE);
        if (n <= 0) {
            printf("Disconnected\n");
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}