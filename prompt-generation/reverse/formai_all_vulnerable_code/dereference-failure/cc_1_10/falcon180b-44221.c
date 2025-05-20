//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct addrinfo hints, *servinfo;
    char username[50];
    char password[50];
    char hostname[100];
    char port[10];
    char buff[BUFF_SIZE];
    int n;

    printf("Enter POP3 Server Hostname: ");
    scanf("%s", hostname);

    printf("Enter POP3 Server Port: ");
    scanf("%s", port);

    printf("Enter POP3 Username: ");
    scanf("%s", username);

    printf("Enter POP3 Password: ");
    scanf("%s", password);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    n = getaddrinfo(hostname, port, &hints, &servinfo);
    if (n!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(n));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to POP3 Server\n");

    send(sockfd, "USER ", 5, 0);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buff, BUFF_SIZE, 0);
    printf("Server Response: %s", buff);

    send(sockfd, "PASS ", 5, 0);
    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buff, BUFF_SIZE, 0);
    printf("Server Response: %s", buff);

    close(sockfd);

    return 0;
}