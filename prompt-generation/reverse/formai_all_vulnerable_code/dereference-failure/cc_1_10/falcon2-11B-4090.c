//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char sendbuf[1000], recvbuf[1000];

    if (argc!= 3) {
        printf("Usage: ping <IP address> <port>\n");
        return 1;
    }

    portno = atoi(argv[2]);
    if (portno <= 0) {
        printf("Port number should be positive integer.\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    sendbuf[0] = 'P';
    sendbuf[1] = 'I';
    sendbuf[2] = 'N';
    sendbuf[3] = 'G';
    sendbuf[4] = '\r';
    sendbuf[5] = '\n';

    n = write(sockfd, sendbuf, 6);
    if (n < 0) {
        perror("write");
        return 1;
    }

    bzero(recvbuf, sizeof(recvbuf));
    n = read(sockfd, recvbuf, sizeof(recvbuf));
    if (n < 0) {
        perror("read");
        return 1;
    }

    printf("Received: %s\n", recvbuf);

    close(sockfd);
    return 0;
}