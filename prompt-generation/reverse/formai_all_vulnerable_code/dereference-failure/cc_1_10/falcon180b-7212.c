//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define PORT 21
#define MAX_COMMAND_LENGTH 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    char command[MAX_COMMAND_LENGTH];
    FILE *fp;
    int len;
    char *ptr;
    int mode;
    int flag;
    char *path;

    if (argc < 4) {
        printf("Usage:./ftp_client <IP_address> <Username> <Password>\n");
        exit(0);
    }

    strcpy(command, "USER ");
    strcat(command, argv[1]);
    strcat(command, "\r\n");
    send(sockfd, command, strlen(command), 0);

    strcpy(command, "PASS ");
    strcat(command, argv[2]);
    strcat(command, "\r\n");
    send(sockfd, command, strlen(command), 0);

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        n = recv(sockfd, buffer, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Connection closed by server\n");
            exit(0);
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}