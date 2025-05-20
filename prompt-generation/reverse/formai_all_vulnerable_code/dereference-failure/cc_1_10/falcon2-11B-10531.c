//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        sockfd = accept(sockfd, (struct sockaddr *) &serv_addr, (socklen_t *) &n);
        if (sockfd < 0) {
            perror("accept failed");
            exit(1);
        }

        bzero(buffer, 1024);
        n = read(sockfd, buffer, 1024);
        if (n < 0) {
            perror("read failed");
            exit(1);
        }

        printf("%s", buffer);

        send(sockfd, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", 51, 0);
        send(sockfd, "<html><head><title>Hello, World!</title></head><body><h1>Hello, World!</h1></body></html>", 66, 0);

        close(sockfd);
        break;
    }

    return 0;
}