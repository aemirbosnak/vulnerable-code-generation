//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define MAX 100
#define PORT "80"
#define SERVER "www.google.com"
#define GET "GET / HTTP/1.0\r\n\r\n"

int main() {
    int sockfd, newsockfd, portno, clilen, ret, i, val, maxfd;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    fd_set readfds;
    char buffer[MAX];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    portno = atoi(PORT);

    server = gethostbyname(SERVER);
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    write(sockfd, GET, strlen(GET));

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    maxfd = sockfd;

    for (i = 0; i < 10; i++) {
        ret = select(maxfd + 1, &readfds, NULL, NULL, NULL);
        if (ret < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        }
        if (FD_ISSET(sockfd, &readfds)) {
            memset(buffer, 0, MAX);
            ret = read(sockfd, buffer, MAX);
            if (ret <= 0) {
                perror("read");
                exit(EXIT_FAILURE);
            }
            printf("%s", buffer);
        }
    }

    close(sockfd);
    return 0;
}