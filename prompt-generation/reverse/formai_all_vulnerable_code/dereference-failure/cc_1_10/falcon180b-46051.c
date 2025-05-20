//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024
#define PORT 25

int main(int argc, char *argv[])
{
    int sockfd, ret;
    struct sockaddr_in serv_addr;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];
    char *cmd = "HELO example.com\r\n";
    char *user = "test@example.com\r\n";
    char *pass = "password\r\n";
    char *data = "Hello World!\r\n";

    if (argc!= 4)
    {
        printf("Usage:./smtp_client <server_ip> <server_port> <data_file>\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error: socket creation failed.\n");
        return -2;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1)
    {
        printf("Error: connection failed.\n");
        return -3;
    }

    printf("Connected to server.\n");

    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, recv_buf, BUF_SIZE, 0);

    printf("Server response: %s\n", recv_buf);

    send(sockfd, user, strlen(user), 0);
    recv(sockfd, recv_buf, BUF_SIZE, 0);

    printf("Server response: %s\n", recv_buf);

    send(sockfd, pass, strlen(pass), 0);
    recv(sockfd, recv_buf, BUF_SIZE, 0);

    printf("Server response: %s\n", recv_buf);

    send(sockfd, data, strlen(data), 0);
    recv(sockfd, recv_buf, BUF_SIZE, 0);

    printf("Server response: %s\n", recv_buf);

    close(sockfd);

    return 0;
}