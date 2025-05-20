//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[1024], recvline[1024];

    if (argc != 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        bzero(sendline, 1024);
        bzero(recvline, 1024);
        printf("Enter your message: ");
        fgets(sendline, 1024, stdin);

        if (strcmp(sendline, "exit\n") == 0) {
            break;
        }

        write(sockfd, sendline, strlen(sendline));
        n = read(sockfd, recvline, 1024);
        printf("Received: %s", recvline);
    }

    close(sockfd);
    return 0;
}