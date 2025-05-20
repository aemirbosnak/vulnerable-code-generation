//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "Usage %s host port\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Host name not found\n");
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &portno);
        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        int pid = fork();
        if (pid == 0) {
            close(sockfd);
            dup2(newsockfd, STDIN_FILENO);
            dup2(newsockfd, STDOUT_FILENO);
            dup2(newsockfd, STDERR_FILENO);
            close(newsockfd);
            execvp(argv[3], argv);
            perror("execvp");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}