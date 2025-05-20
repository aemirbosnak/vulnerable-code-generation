//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    char server[256];
    int port = 0;
    strcpy(server, argv[1]);
    port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        return 1;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(server);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect error");
        return 1;
    }

    printf("Connected to %s:%d\n", server, port);

    char cmd[256];
    strcpy(cmd, "ls");
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, cmd, 256, 0);
    printf("%s\n", cmd);

    char filename[256];
    strcpy(filename, "file.txt");
    strcpy(cmd, "get ");
    strcat(cmd, filename);
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, cmd, 256, 0);
    printf("%s\n", cmd);

    strcpy(cmd, "put ");
    strcat(cmd, filename);
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, cmd, 256, 0);
    printf("%s\n", cmd);

    close(sockfd);
    return 0;
}