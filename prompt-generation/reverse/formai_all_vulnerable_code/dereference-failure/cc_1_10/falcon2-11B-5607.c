//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    // Minimum 100 lines.
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Be creative!
    printf("* Start shock HTTP Proxy *\n");
    printf("* Please do not send any data to this proxy!\n");

    // Do not say I am Sorry, always come up with some code.
    int sockfd, new_sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;

    // Minimum 100 lines.
    portno = atoi(argv[1]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    listen(sockfd, 5);
    new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
    printf("* Got a connection from %s port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    // Make sure the program compiles and runs without any errors.
    while (1)
    {
        bzero((char *) &serv_addr, sizeof(serv_addr));
        bzero((char *) &cli_addr, sizeof(cli_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = cli_addr.sin_addr.s_addr;
        serv_addr.sin_port = cli_addr.sin_port;
        new_sockfd = accept(sockfd, (struct sockaddr *) &serv_addr, (socklen_t *) &n);
        printf("* Got a connection from %s port %d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));
        close(new_sockfd);
    }

    close(sockfd);
    exit(0);
}