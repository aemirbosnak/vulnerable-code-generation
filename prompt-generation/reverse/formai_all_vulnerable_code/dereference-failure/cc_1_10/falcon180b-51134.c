//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/time.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in serv_addr;
    char send_buff[BUF_SIZE], recv_buff[BUF_SIZE];
    char *cmd;
    int len;
    fd_set readfds;
    struct timeval tv;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket failed\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        printf("Error: connect failed\n");
        exit(1);
    }

    cmd = "USER myusername\r\n";
    send(sockfd, cmd, strlen(cmd), 0);

    cmd = "PASS mypassword\r\n";
    send(sockfd, cmd, strlen(cmd), 0);

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        tv.tv_sec = 0;
        tv.tv_usec = 100000;

        ret = select(sockfd + 1, &readfds, NULL, NULL, &tv);
        if (ret == -1) {
            printf("Error: select failed\n");
            exit(1);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            len = recv(sockfd, recv_buff, BUF_SIZE, 0);
            if (len <= 0) {
                printf("Error: recv failed\n");
                exit(1);
            }

            recv_buff[len] = '\0';
            printf("Received: %s", recv_buff);
        }
    }

    close(sockfd);
    exit(0);
}