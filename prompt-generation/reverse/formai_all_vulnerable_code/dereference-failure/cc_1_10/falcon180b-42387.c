//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage:./server <port number> <message>\n");
        exit(0);
    }

    portno = atoi(argv[1]);
    strcpy(buffer, argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error_handling("socket failed");

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error_handling("bind failed");

    if (listen(sockfd, 5) < 0)
        error_handling("listen");

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0)
        error_handling("accept");

    send(newsockfd, buffer, BUFFER_SIZE, 0);
    close(newsockfd);
    close(sockfd);

    return 0;
}