//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

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

    while (1) {
        cli_addr.sin_family = AF_INET;
        cli_addr.sin_addr.s_addr = INADDR_ANY;
        cli_addr.sin_port = htons(0);

        n = sizeof(cli_addr);
        sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &n);
        if (sockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        bzero(buffer, sizeof(buffer));
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        printf("Received: %s\n", buffer);

        bzero(buffer, sizeof(buffer));
        n = write(sockfd, "Hello from server!", strlen("Hello from server!"));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        close(sockfd);
    }

    return 0;
}