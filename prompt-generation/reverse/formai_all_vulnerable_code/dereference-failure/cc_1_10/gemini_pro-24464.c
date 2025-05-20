//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char sendline[MAX_LINE], recvline[MAX_LINE];
    struct sockaddr_in servaddr;

    if (argc != 3) {
        printf("Usage: %s <destination IP address> <destination port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    while (1) {
        bzero(sendline, MAX_LINE);
        bzero(recvline, MAX_LINE);
        printf("> ");
        fgets(sendline, MAX_LINE, stdin);

        if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
            printf("Send failed\n");
            exit(1);
        }

        if (strncmp(sendline, "QUIT", 4) == 0) {
            break;
        }

        if (recv(sockfd, recvline, MAX_LINE, 0) == 0) {
            printf("Server closed connection\n");
            exit(1);
        }

        printf("%s", recvline);
    }

    close(sockfd);
    return 0;
}