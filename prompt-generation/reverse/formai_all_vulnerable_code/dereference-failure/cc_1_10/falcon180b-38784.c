//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *host;
    char *ip;
    int port;
    char buf[BUF_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    host = gethostbyname(ip);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);
    servaddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))!= 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        memset(buf, 0, BUF_SIZE);
        if (read(sockfd, buf, BUF_SIZE) <= 0) {
            printf("Error reading from server\n");
            break;
        }
        printf("%s", buf);
    }

    close(sockfd);
    return 0;
}