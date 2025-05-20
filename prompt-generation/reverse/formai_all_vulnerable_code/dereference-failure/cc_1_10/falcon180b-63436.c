//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define MAX 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];

    if (argc < 3) {
        printf("Error: Insufficient arguments\n");
        exit(0);
    }

    portno = atoi(argv[1]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Socket creation failed\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Bind failed\n");
        exit(0);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        puts("Waiting for connections...");
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

        if (newsockfd < 0) {
            printf("Error: Accept failed\n");
            exit(0);
        }

        printf("Connection established with %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        sd = dup(newsockfd);
        close(newsockfd);

        switch(fork()) {
            case -1:
                printf("Error: Fork failed\n");
                exit(0);
            case 0:
                close(sockfd);
                while(1) {
                    memset(buffer, 0, sizeof(buffer));
                    valread = read(sd, buffer, MAX);
                    if(valread <= 0) {
                        break;
                    }
                    write(1, buffer, strlen(buffer));
                }
                close(sd);
                exit(0);
            default:
                close(sd);
        }
    }

    return 0;
}