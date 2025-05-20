//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024
#define SERVER_PORT 110
#define USERNAME "your_username"
#define PASSWORD "your_password"

int main() {
    int sockfd, portno;
    char buffer[BUF_SIZE];
    char command[BUF_SIZE];
    char *ptr;
    char *user = USERNAME;
    char *pass = PASSWORD;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("socket failed\n");
        exit(1);
    }

    server = gethostbyname("pop3.example.com");

    if (server == NULL) {
        printf("no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    portno = SERVER_PORT;

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("connect failed\n");
        exit(1);
    }

    printf("connected\n");

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        printf("enter command: ");
        fgets(command, BUF_SIZE, stdin);
        send(sockfd, command, strlen(command), 0);

        n = recv(sockfd, buffer, BUF_SIZE, 0);

        if (n <= 0) {
            printf("disconnected\n");
            exit(1);
        }

        buffer[n] = 0;
        printf("server response: %s", buffer);
    }

    return 0;
}