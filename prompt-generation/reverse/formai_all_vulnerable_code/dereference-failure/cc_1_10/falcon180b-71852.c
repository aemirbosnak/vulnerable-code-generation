//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Cryptic
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
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid server address\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        fprintf(stderr, "Failed to connect to server: %s\n", strerror(errno));
        exit(1);
    }

    sprintf(sendline, "USER %s\r\n", argv[2]);
    send(sockfd, sendline, strlen(sendline), 0);
    recv(sockfd, recvline, MAX_LINE, 0);

    sprintf(sendline, "PASS %s\r\n", argv[3]);
    send(sockfd, sendline, strlen(sendline), 0);
    recv(sockfd, recvline, MAX_LINE, 0);

    while (1) {
        memset(sendline, 0, MAX_LINE);
        memset(recvline, 0, MAX_LINE);
        sprintf(sendline, "LIST\r\n");
        send(sockfd, sendline, strlen(sendline), 0);
        recv(sockfd, recvline, MAX_LINE, 0);

        printf("Server response: %s", recvline);

        if (strstr(recvline, ".")!= NULL) {
            printf("\nEnd of message\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}