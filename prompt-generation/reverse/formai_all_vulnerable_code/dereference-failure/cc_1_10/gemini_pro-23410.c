//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[256];

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        return 2;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect");
        return 3;
    }

    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "USER username\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "PASS password\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "RETR 1\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    close(sockfd);
    return 0;
}