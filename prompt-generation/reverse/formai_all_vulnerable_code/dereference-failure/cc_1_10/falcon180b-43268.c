//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, maxfd, newsockfd, clilen, i, valread, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1025];
    fd_set readfds;

    if (argc!= 3) {
        printf("Usage:./portscanner <IP Address> <Port Range>\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        exit(0);
    }

    portno = atoi(argv[2]);
    maxfd = sockfd;
    FD_ZERO(&readfds);

    while (portno <= atoi(argv[2]) + 1024) {
        clilen = sizeof(cli_addr);
        if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen)) < 0) {
            printf("Error on accept\n");
            exit(0);
        }

        if (FD_ISSET(newsockfd, &readfds)) {
            if ((valread = read(newsockfd, buffer, 1024)) < 0) {
                printf("Error reading from socket\n");
                exit(0);
            }
            printf("Port %d is open\n", ntohs(cli_addr.sin_port));
            close(newsockfd);
        }
        portno++;
    }

    close(sockfd);
    return 0;
}