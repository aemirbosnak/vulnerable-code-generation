//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buffer[BUF_SIZE], recv_buffer[BUF_SIZE];
    char *login_str = "USER anonymous\r\n";
    char *pass_str = "PASS anonymous@example.com\r\n";
    char *cmd_str = "LIST\r\n";

    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <port> <filename>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    send(sockfd, login_str, strlen(login_str), 0);
    send(sockfd, pass_str, strlen(pass_str), 0);
    send(sockfd, cmd_str, strlen(cmd_str), 0);

    while (1) {
        bzero(recv_buffer, BUF_SIZE);
        n = recv(sockfd, recv_buffer, BUF_SIZE, 0);
        if (n <= 0) {
            break;
        }
        printf("%s", recv_buffer);
    }

    close(sockfd);
    return 0;
}