//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, newsockfd, portno, clilen, recv_len;
    char buffer[MAX_DATA_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    int opt = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(errno);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8000);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(errno);
    }

    listen(sockfd, 5);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept failed");
            exit(errno);
        }

        printf("Connection from %s on port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buffer, MAX_DATA_SIZE);
            recv_len = recv(newsockfd, buffer, MAX_DATA_SIZE, 0);
            if (recv_len <= 0) {
                if (recv_len == 0) {
                    printf("Client disconnected\n");
                } else {
                    perror("recv failed");
                }
                close(newsockfd);
                break;
            }

            printf("Received message: %s\n", buffer);

            if (strcmp(buffer, "exit") == 0) {
                printf("Exiting...\n");
                close(newsockfd);
                break;
            }
        }
    }

    close(sockfd);
    return 0;
}