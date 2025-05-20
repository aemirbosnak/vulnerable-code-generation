//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>

#define MAX_MSG_LEN 1024

void receive_messages(int sockfd) {
    char buf[MAX_MSG_LEN];
    while (1) {
        memset(buf, 0, MAX_MSG_LEN);
        int n = recv(sockfd, buf, MAX_MSG_LEN, 0);
        if (n <= 0) {
            break;
        }
        printf("%s", buf);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    int status = connect(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    if (status == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buf[MAX_MSG_LEN];
    memset(buf, 0, MAX_MSG_LEN);
    int n = recv(sockfd, buf, MAX_MSG_LEN, 0);
    if (n <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    memset(buf, 0, MAX_MSG_LEN);
    strcpy(buf, "USER username\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    memset(buf, 0, MAX_MSG_LEN);
    n = recv(sockfd, buf, MAX_MSG_LEN, 0);
    if (n <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    memset(buf, 0, MAX_MSG_LEN);
    strcpy(buf, "PASS password\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    memset(buf, 0, MAX_MSG_LEN);
    n = recv(sockfd, buf, MAX_MSG_LEN, 0);
    if (n <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    memset(buf, 0, MAX_MSG_LEN);
    strcpy(buf, "LIST\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    memset(buf, 0, MAX_MSG_LEN);
    n = recv(sockfd, buf, MAX_MSG_LEN, 0);
    if (n <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    memset(buf, 0, MAX_MSG_LEN);
    strcpy(buf, "RETR 1\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    receive_messages(sockfd);

    memset(buf, 0, MAX_MSG_LEN);
    strcpy(buf, "QUIT\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    close(sockfd);
    return EXIT_SUCCESS;
}