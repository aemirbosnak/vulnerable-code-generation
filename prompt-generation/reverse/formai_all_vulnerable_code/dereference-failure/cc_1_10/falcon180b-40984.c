//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, ret, i;
    struct sockaddr_in serveraddr;
    char sendbuf[BUF_SIZE];
    char recvbuf[BUF_SIZE];
    struct hostent *hostent;

    if (argc!= 3) {
        printf("Usage:./program <hostname/IP> <port>\n");
        return 1;
    }

    hostent = gethostbyname(argv[1]);
    if (hostent == NULL) {
        printf("Error: Invalid hostname/IP address.\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket.\n");
        return 1;
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    serveraddr.sin_addr = *((struct in_addr *) hostent->h_addr);

    ret = connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr));
    if (ret == -1) {
        printf("Error: Failed to connect to server.\n");
        close(sockfd);
        return 1;
    }

    for (i = 0; i < 5; i++) {
        sprintf(sendbuf, "PING %d\r\n", i + 1);
        send(sockfd, sendbuf, strlen(sendbuf), 0);

        memset(recvbuf, 0, BUF_SIZE);
        ret = recv(sockfd, recvbuf, BUF_SIZE, 0);
        if (ret <= 0) {
            printf("Error: Failed to receive response.\n");
            close(sockfd);
            return 1;
        }

        printf("Response %d: %s", i + 1, recvbuf);
    }

    close(sockfd);
    return 0;
}