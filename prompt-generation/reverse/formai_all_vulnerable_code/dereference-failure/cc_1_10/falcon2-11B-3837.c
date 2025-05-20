//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buf[BUF_SIZE];
    bzero(buf, BUF_SIZE);
    while (1) {
        if (read(sockfd, buf, BUF_SIZE) < 0) {
            perror("read");
            exit(1);
        }

        printf("%s\n", buf);

        bzero(buf, BUF_SIZE);
        if (write(sockfd, buf, BUF_SIZE) < 0) {
            perror("write");
            exit(1);
        }

        printf("Received: %s\n", buf);
    }

    return 0;
}