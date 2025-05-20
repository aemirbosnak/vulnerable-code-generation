//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 1000

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    FILE *fp;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    portno = 8080;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

        if (newsockfd < 0) {
            perror("accept failed");
            exit(1);
        }

        printf("new connection\n");

        sd = open("text.txt", O_RDONLY);

        if (sd < 0) {
            perror("open");
            exit(1);
        }

        printf("file opened\n");

        while ((fgets(buffer, MAX, fp))!= NULL) {
            send(newsockfd, buffer, strlen(buffer), 0);
        }

        printf("file sent\n");

        close(newsockfd);
    }

    return 0;
}