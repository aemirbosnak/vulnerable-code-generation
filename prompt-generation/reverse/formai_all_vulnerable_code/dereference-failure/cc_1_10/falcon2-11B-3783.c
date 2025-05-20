//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    while (1) {
        if ((newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s\n", inet_ntoa(cli_addr.sin_addr));
        char buf[256];
        int len = read(newsockfd, buf, sizeof(buf));
        if (len > 0)
            printf("Received %d bytes: %s\n", len, buf);

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}