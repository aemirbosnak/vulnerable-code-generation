//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define PORT 110
#define USER "your_username"
#define PASS "your_password"

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];
    char *cmd = "USER ";
    strcat(cmd, USER);
    strcat(cmd, "\r\n");
    strcat(cmd, "PASS ");
    strcat(cmd, PASS);
    strcat(cmd, "\r\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    memset(recv_buf, 0, sizeof(recv_buf));
    while ((n = recv(sockfd, recv_buf, sizeof(recv_buf), 0)) > 0) {
        printf("Received Message: %s\n", recv_buf);
        memset(recv_buf, 0, sizeof(recv_buf));
    }

    close(sockfd);
    return 0;
}