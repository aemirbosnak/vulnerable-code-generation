//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

void main() {
    int sockfd, newsockfd, portno, clilen, recv_len;
    char buffer[1025];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    int yes = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

    server = gethostbyname("127.0.0.1");
    if (server == NULL) {
        fprintf(stderr, "No such host");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(12345);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("accept failed");
        exit(1);
    }

    while (1) {
        bzero(buffer, 1025);
        recv_len = recv(newsockfd, buffer, 1024, 0);
        if (recv_len <= 0) {
            break;
        }
        buffer[recv_len] = '\0';
        printf("Received message: %s\n", buffer);
        send(newsockfd, buffer, strlen(buffer), 0);
    }

    close(newsockfd);
    close(sockfd);
}