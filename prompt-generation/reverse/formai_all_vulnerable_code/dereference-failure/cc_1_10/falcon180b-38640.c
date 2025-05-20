//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 100
#define PORT 8080
#define SA struct sockaddr

int main() {
    int sockfd, newsockfd, portno, clilen, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    char *ip = "127.0.0.1";
    struct hostent *server;
    int len;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    portno = PORT;

    server = gethostbyname(ip);
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (SA *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    while (1) {
        bzero(buffer, MAX);
        fgets(buffer, MAX, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        if (strcmp(buffer, "/quit") == 0) {
            break;
        }
        bzero(buffer, MAX);
        recv(sockfd, buffer, MAX, 0);
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}