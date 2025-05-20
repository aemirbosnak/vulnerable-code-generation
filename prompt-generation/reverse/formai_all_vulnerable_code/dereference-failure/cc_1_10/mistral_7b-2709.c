//MISTRAL-7B DATASET v1.0 Category: Firewall ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_BUF 1024
#define SHAPE_SHIFT 5

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_BUF];
    char shape[SHAPE_SHIFT][MAX_BUF];
    int i, j;
    time_t t;

    srand((unsigned)time(&t));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    listen(sockfd, 5);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        bzero(buffer, MAX_BUF);
        read(newsockfd, buffer, MAX_BUF);

        for (i = 0; i < SHAPE_SHIFT; i++) {
            strcpy(shape[i], buffer);
        }

        for (i = 0; i < SHAPE_SHIFT; i++) {
            for (j = 0; j < i; j++) {
                if (strcmp(shape[i], shape[j]) == 0) {
                    goto shape_collision;
                }
            }
        }

        for (i = 0; i < SHAPE_SHIFT; i++) {
            write(newsockfd, shape[i], strlen(shape[i]));
            printf("Sent shape %s to client\n", shape[i]);
        }

        shape_collision: {};

        for (i = 0; i < SHAPE_SHIFT; i++) {
            if (strcmp(shape[i], buffer) == 0) {
                close(newsockfd);
                printf("Client sent duplicate shape %s. Closing connection.\n", shape[i]);
                continue;
            }
        }

        for (i = 0; i < SHAPE_SHIFT; i++) {
            strcpy(shape[i], buffer);
        }

        close(newsockfd);
        printf("Connection closed with client.\n");
    }

    close(sockfd);
    return 0;
}