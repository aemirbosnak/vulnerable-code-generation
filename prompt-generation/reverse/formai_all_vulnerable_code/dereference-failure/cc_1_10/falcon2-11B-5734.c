//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // Create socket and bind it to a port
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR on binding\n");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        cli_addr.sin_family = AF_INET;
        cli_addr.sin_port = htons(0);

        portno = htons(atoi(argv[1]));

        n = sizeof(cli_addr);
        if ((sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &n)) < 0) {
            perror("accept");
            exit(1);
        }

        char buffer[256];
        bzero(buffer, 256);

        while ((n = recv(sockfd, buffer, 256, 0)) > 0) {
            printf("%s\n", buffer);
            fflush(stdout);
        }

        if (n < 0) {
            perror("recv");
            exit(1);
        }

        close(sockfd);
    }

    close(sockfd);
    return 0;
}