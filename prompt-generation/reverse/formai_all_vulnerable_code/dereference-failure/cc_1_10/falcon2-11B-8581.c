//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define BACKLOG 10

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = *(long int *)server->h_addr;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR on binding\n");
        exit(1);
    }

    listen(sockfd, BACKLOG);

    while (1) {
        n = sizeof(struct sockaddr_in);
        sockfd = accept(sockfd, (struct sockaddr *) &serv_addr, (socklen_t *) &n);
        if (sockfd < 0) {
            fprintf(stderr, "ERROR on accept\n");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));
        char buf[1024];
        bzero(buf, sizeof(buf));
        n = read(sockfd, buf, sizeof(buf));
        if (n < 0) {
            fprintf(stderr, "ERROR reading from socket\n");
            exit(1);
        }
        buf[n] = '\0';
        printf("Received: %s\n", buf);
        write(sockfd, buf, strlen(buf));
        close(sockfd);
    }

    close(sockfd);
    return 0;
}