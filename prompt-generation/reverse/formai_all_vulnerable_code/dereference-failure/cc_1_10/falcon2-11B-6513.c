//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/time.h>
#include <time.h>

#define MAX_CONNECTION 5

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int sockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname failed\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, MAX_CONNECTION);
    while (1) {
        int clientfd, n;
        struct sockaddr_in cli_addr;
        socklen_t clilen;
        char buffer[256];

        clilen = sizeof(cli_addr);
        clientfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (clientfd < 0) {
            perror("accept failed");
            continue;
        }
        printf("Connection from %s\n", inet_ntoa(cli_addr.sin_addr));
        while (1) {
            n = read(clientfd, buffer, sizeof(buffer));
            if (n < 0) {
                perror("read error");
                close(clientfd);
                continue;
            }
            bzero(buffer, sizeof(buffer));
            n = write(clientfd, buffer, sizeof(buffer));
            if (n < 0) {
                perror("write error");
                close(clientfd);
                continue;
            }
            printf("From client: %s\n", buffer);
            printf("Reply: %s\n", buffer);
        }
    }
    return 0;
}