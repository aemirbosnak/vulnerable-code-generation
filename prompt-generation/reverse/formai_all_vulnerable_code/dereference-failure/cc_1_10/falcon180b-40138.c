//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 110
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendline[MAX_LINE];
    char recvline[MAX_LINE];

    if (argc!= 3) {
        printf("Usage: %s <server> <username>\n", argv[0]);
        exit(1);
    }

    strcpy(sendline, "USER ");
    strcat(sendline, argv[2]);
    strcat(sendline, "\r\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to %s\n", argv[1]);

    while (1) {
        memset(recvline, 0, sizeof(recvline));
        if ((n = read(sockfd, recvline, sizeof(recvline))) < 0) {
            perror("read failed");
            exit(1);
        }

        printf("%s", recvline);
    }

    close(sockfd);
    return 0;
}