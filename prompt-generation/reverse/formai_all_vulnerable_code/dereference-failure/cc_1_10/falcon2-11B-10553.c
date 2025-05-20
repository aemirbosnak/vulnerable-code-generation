//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <time.h>

#define PORT 5000

void usage(char *progname)
{
    fprintf(stderr, "Usage: %s [-p port]\n", progname);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    int optval = 1;
    int n;
    char buffer[1024];

    if (argc!= 2) {
        usage(argv[0]);
    }
    portno = atoi(argv[1]);
    if (portno <= 0 || portno > 65535) {
        fprintf(stderr, "Error: Invalid port number\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);
    printf("Chat Server started on port %d\n", portno);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
        if (newsockfd < 0) {
            perror("ERROR on accepting");
            exit(1);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buffer, sizeof(buffer));
            n = read(newsockfd, buffer, sizeof(buffer) - 1);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }

            buffer[n] = '\0';

            printf("Client: %s\n", buffer);

            send(newsockfd, buffer, strlen(buffer), 0);

            if (strcmp(buffer, "quit") == 0) {
                break;
            }
        }

        printf("Client disconnected: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}