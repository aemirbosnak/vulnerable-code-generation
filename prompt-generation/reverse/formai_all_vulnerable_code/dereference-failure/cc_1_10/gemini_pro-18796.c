//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <sys/ioctl.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[BUFSIZE], recvline[BUFSIZE];

    if (argc != 3) {
        fprintf(stderr, "usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        printf("Enter a message to send to the server: ");
        fgets(sendline, BUFSIZE, stdin);

        if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
            perror("send");
            exit(1);
        }

        if ((n = recv(sockfd, recvline, BUFSIZE, 0)) < 0) {
            perror("recv");
            exit(1);
        }

        recvline[n] = '\0';
        printf("Received %d bytes from the server: %s\n", n, recvline);
    }

    close(sockfd);

    return 0;
}