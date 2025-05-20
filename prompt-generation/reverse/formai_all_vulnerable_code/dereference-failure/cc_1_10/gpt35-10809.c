//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 2) {
        printf("usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket error: %s\n", strerror(errno));
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(143); // IMAP default port

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("connect error: %s\n", strerror(errno));
        exit(1);
    }

    // send login credentials
    char *username = "myusername";
    char *password = "mypassword";
    char login_msg[MAXLINE];
    sprintf(login_msg, "LOGIN %s %s\r\n", username, password);
    if (send(sockfd, login_msg, strlen(login_msg), 0) < 0) {
        printf("send error: %s\n", strerror(errno));
        exit(1);
    }

    // read server response
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) < 0) {
        printf("recv error: %s\n", strerror(errno));
        exit(1);
    }

    recvline[n] = '\0';
    printf("Server response: %s", recvline);

    close(sockfd);
    return 0;
}