//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int sockfd;
    struct sockaddr_in serv_addr;
    int addrlen = sizeof(serv_addr);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        int clientfd = accept(sockfd, (struct sockaddr *) &serv_addr, (socklen_t *) &addrlen);
        if (clientfd < 0) {
            perror("accept failed");
            exit(1);
        }

        char buffer[1024];
        int n;

        while ((n = recv(clientfd, buffer, sizeof(buffer), 0)) > 0) {
            buffer[n] = '\0';
            printf("Received: %s\n", buffer);
            send(clientfd, "HTTP/1.1 200 OK\r\nContent-Length: 5\r\n\r\nHello\n", strlen("HTTP/1.1 200 OK\r\nContent-Length: 5\r\n\r\nHello\n"), 0);
        }

        if (n < 0) {
            perror("recv failed");
            close(clientfd);
            exit(1);
        }

        close(clientfd);
    }

    close(sockfd);
    return 0;
}