//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char **argv)
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);

    while (1) {
        sockfd = accept(sockfd, (struct sockaddr *) &serv_addr, (socklen_t *) &n);
        if (sockfd < 0)
            error("ERROR on accept");

        printf("New connection from %s\n", inet_ntoa(serv_addr.sin_addr));

        while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
            printf("Received %d bytes: %s\n", n, buffer);
            send(sockfd, buffer, n, 0);
        }

        close(sockfd);
    }

    return 0;
}