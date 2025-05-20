//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 21
#define BUFSIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[BUFSIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    if (argc!= 3) {
        printf("Usage:./client <IP address> <port number>\n");
        exit(0);
    }

    portno = atoi(argv[2]);
    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("No such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_handling("Error opening socket");
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("Error connecting to server");
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command (e.g. ls, cd, get, put): ");
        fgets(buffer, BUFSIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0);

        memset(buffer, 0, BUFSIZE);
        bzero(&cli_addr, sizeof(cli_addr));
        clilen = sizeof(cli_addr);
        recv(sockfd, buffer, BUFSIZE, 0);
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(0);
}