//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clientlen, server_sockfd, n;
    struct sockaddr_in serv_addr, cli_addr, server_addr;
    struct hostent *server;
    char buffer[MAX_SIZE], request[MAX_SIZE], response[MAX_SIZE];
    fd_set fds;

    if (argc < 3) {
        error("Usage: ./proxy <proxy_port> <server_ip> <server_port>");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
            sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    if (listen(sockfd, 5) < 0) {
        error("ERROR on listening");
    }

    printf("Proxy server is running...\n");

    while (1) {
        clientlen = sizeof(cli_addr);
        newsockfd = accept(sockfd,
                (struct sockaddr *) &cli_addr, &clientlen);
        if (newsockfd < 0) {
            error("ERROR on accept");
        }

        bzero(buffer, MAX_SIZE);
        read(newsockfd, buffer, MAX_SIZE);
        strcpy(request, buffer);

        server = gethostbyname(argv[2]);
        if (server == NULL) {
            fprintf(stderr,"ERROR, no such host\n");
            exit(0);
        }

        server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd < 0) {
            error("ERROR opening socket");
        }

        bzero((char *) &server_addr, sizeof(server_addr));
        portno = atoi(argv[3]);
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)server->h_addr_list[0]));
        server_addr.sin_port = htons(portno);

        if (connect(server_sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr)) < 0) {
            error("ERROR connecting");
        }

        write(server_sockfd, request, strlen(request));
        bzero(response, MAX_SIZE);

        while (1) {
            FD_ZERO(&fds);
            FD_SET(server_sockfd, &fds);
            n = select(server_sockfd + 1, &fds, NULL, NULL, NULL);

            if (n < 0) {
                error("select() failed");
                break;
            }

            if (FD_ISSET(server_sockfd, &fds)) {
                n = read(server_sockfd, response, MAX_SIZE);
                if (n <= 0) {
                    break;
                }

                write(newsockfd, response, n);
            }
        }

        close(newsockfd);
        close(server_sockfd);
    }

    close(sockfd);
    return 0;
}