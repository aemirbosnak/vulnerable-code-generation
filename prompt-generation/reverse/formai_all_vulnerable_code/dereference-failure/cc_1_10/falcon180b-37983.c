//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAX_LINE], recvline[MAX_LINE];

    if (argc!= 4) {
        printf("Usage:./pop3_client <server_address> <username> <password>\n");
        return 1;
    }

    strcpy(sendline, "USER ");
    strcat(sendline, argv[2]);
    strcat(sendline, "\r\n");

    strcpy(sendline, "PASS ");
    strcat(sendline, argv[3]);
    strcat(sendline, "\r\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to %s:%d\n", argv[1], POP3_PORT);

    send(sockfd, sendline, strlen(sendline), 0);
    recv(sockfd, recvline, MAX_LINE, 0);
    printf("Response: %s", recvline);

    send(sockfd, "LIST\r\n", 6, 0);
    recv(sockfd, recvline, MAX_LINE, 0);
    printf("Response: %s", recvline);

    send(sockfd, "RETR 1\r\n", 9, 0);
    recv(sockfd, recvline, MAX_LINE, 0);
    printf("Response: %s", recvline);

    close(sockfd);
    return 0;
}