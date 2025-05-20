//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    int sockfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    int yes = 1;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("ERROR on binding\n");
        return 1;
    }

    listen(sockfd, 5);
    while (1) {
        printf("Waiting for connection...\n");
        bzero((char *) &cli_addr, sizeof(cli_addr));
        n = sizeof(cli_addr);
        if ((sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &n)) < 0) {
            printf("ERROR on accept\n");
            return 1;
        }

        printf("Connected to %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buffer, 1024);
            n = read(sockfd, buffer, 1024);
            if (n < 0) {
                printf("ERROR reading from socket\n");
                return 1;
            }

            printf("Client: %s\n", buffer);

            bzero(buffer, 1024);
            n = write(sockfd, buffer, 1024);
            if (n < 0) {
                printf("ERROR writing to socket\n");
                return 1;
            }

            if (strcmp(buffer, "quit") == 0) {
                break;
            }
        }

        printf("Client disconnected\n");
        close(sockfd);
    }

    return 0;
}