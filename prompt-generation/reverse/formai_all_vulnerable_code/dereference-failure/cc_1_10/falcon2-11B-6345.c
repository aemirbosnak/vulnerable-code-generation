//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int sockfd, newsockfd, connfd;
    struct sockaddr_in serv_addr, cli_addr;
    int addrlen = sizeof(serv_addr);

    char buffer[256];

    if (port <= 0 || port > 65535) {
        fprintf(stderr, "Port number must be between 1 and 65535\n");
        return 1;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        error("ERROR opening socket");

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) == -1)
        error("ERROR setting socket option");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)
        error("ERROR on binding");

    if (listen(sockfd, 3) == -1)
        error("ERROR on listen");

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &addrlen);
        if (newsockfd == -1)
            error("ERROR on accept");

        printf("Connected by client with address: %s\n", inet_ntoa(cli_addr.sin_addr));

        while (1) {
            bzero(buffer, sizeof(buffer));
            read(newsockfd, buffer, sizeof(buffer));

            if (strcmp(buffer, "quit") == 0) {
                printf("Client %s disconnected.\n", inet_ntoa(cli_addr.sin_addr));
                break;
            }

            write(newsockfd, "OK\n", sizeof("OK\n"));
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}