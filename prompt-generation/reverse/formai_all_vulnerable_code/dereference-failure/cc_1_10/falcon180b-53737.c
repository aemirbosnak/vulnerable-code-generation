//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <ctype.h>

#define BUF_SIZE 1024
#define MAX_LINE 512
#define DELIM "\r\n"
#define POP3_PORT 110
#define USER "your_username"
#define PASSWORD "your_password"

int main(int argc, char *argv[])
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    char send_buffer[MAX_LINE];
    char recv_buffer[MAX_LINE];
    char *token;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("socket failed\n");
        exit(1);
    }

    server = gethostbyname("your_pop3_server");
    if (server == NULL)
    {
        printf("no such host\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    portno = POP3_PORT;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("connect failed\n");
        exit(1);
    }

    printf("connected\n");

    sprintf(send_buffer, "USER %s\r\n", USER);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    while (1)
    {
        n = recv(sockfd, buffer, BUF_SIZE, 0);
        if (n <= 0)
        {
            printf("disconnected\n");
            exit(1);
        }

        strcat(recv_buffer, buffer);

        token = strtok(recv_buffer, DELIM);
        while (token!= NULL)
        {
            printf("%s", token);
            if (strcasecmp(token, "+OK") == 0)
            {
                break;
            }
            token = strtok(NULL, DELIM);
        }
    }

    close(sockfd);
    return 0;
}