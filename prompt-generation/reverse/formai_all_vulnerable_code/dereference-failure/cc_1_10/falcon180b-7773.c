//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendline[MAX_LINE_LENGTH], recvline[MAX_LINE_LENGTH];

    if (argc!= 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
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
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        memset(recvline, 0, MAX_LINE_LENGTH);
        if ((n = recv(sockfd, recvline, MAX_LINE_LENGTH, 0)) < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        printf("%s", recvline);
    }

    return 0;
}