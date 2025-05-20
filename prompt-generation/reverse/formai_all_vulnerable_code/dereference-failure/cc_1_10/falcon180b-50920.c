//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 1024

int main(int argc, char *argv[])
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char send_buffer[MAX];
    char recv_buffer[MAX];

    if (argc < 4)
    {
        printf("Usage:./ftp_client <IP address> <port number> <command>\n");
        exit(0);
    }

    portno = atoi(argv[2]);
    strcpy(send_buffer, argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("Error opening socket\n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error connecting to server\n");
        exit(0);
    }

    send(sockfd, send_buffer, strlen(send_buffer), 0);

    bzero(recv_buffer, MAX);
    bzero(send_buffer, MAX);

    while (1)
    {
        int n = read(sockfd, recv_buffer, MAX);

        if (n <= 0)
        {
            printf("Connection closed by server\n");
            break;
        }

        printf("%s", recv_buffer);
    }

    close(sockfd);

    return 0;
}