//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#define MAX_LINE_LENGTH 1024
#define BUFFER_SIZE 10240

int main(int argc, char *argv[])
{
    if (argc!= 4)
    {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    struct addrinfo hints, *servinfo;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(server, "21", &hints, &servinfo)!= 0)
    {
        printf("getaddrinfo error: %s\n", gai_strerror(errno));
        return 1;
    }

    int sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

    if (sockfd == -1)
    {
        printf("socket error: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1)
    {
        printf("connect error: %s\n", strerror(errno));
        return 1;
    }

    char login_command[MAX_LINE_LENGTH] = "USER ";
    strcat(login_command, username);
    strcat(login_command, "\r\n");

    send(sockfd, login_command, strlen(login_command), 0);

    char password_command[MAX_LINE_LENGTH] = "PASS ";
    strcat(password_command, password);
    strcat(password_command, "\r\n");

    send(sockfd, password_command, strlen(password_command), 0);

    char command[MAX_LINE_LENGTH] = "PWD\r\n";

    send(sockfd, command, strlen(command), 0);

    char buffer[BUFFER_SIZE];

    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (bytes_received <= 0)
    {
        printf("recv error: %s\n", strerror(errno));
        return 1;
    }

    buffer[bytes_received] = '\0';

    printf("Current directory: %s\n", buffer);

    close(sockfd);

    return 0;
}