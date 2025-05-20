//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: mathematical
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char recvline[1024], sendline[1024];

    if (argc != 3) {
        fprintf(stderr, "usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    while (1) {
        printf("POP3> ");
        fgets(sendline, 1024, stdin);

        if (strcmp(sendline, "quit\n") == 0) {
            break;
        }

        n = write(sockfd, sendline, strlen(sendline));
        if (n == -1) {
            perror("write");
            exit(1);
        }

        n = read(sockfd, recvline, 1024);
        if (n == -1) {
            perror("read");
            exit(1);
        }

        printf("%s", recvline);
    }

    close(sockfd);
    return 0;
}