//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, newsockfd, addrlen;
    struct sockaddr_in serv_addr;

    if (argc!= 2) {
        fprintf(stderr, "usage %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    if (portno < 0 || portno > 65535) {
        fprintf(stderr, "Invalid port number\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error in socket creation");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error in binding");
        exit(1);
    }

    listen(sockfd, 5);

    newsockfd = accept(sockfd, (struct sockaddr *) &serv_addr, (socklen_t *) &addrlen);

    if (newsockfd < 0) {
        perror("Error in accept");
        exit(1);
    }

    int n;
    char buf[1024];

    while ((n = recv(newsockfd, buf, sizeof(buf), 0)) > 0) {
        printf("Received %d bytes: %s\n", n, buf);
        send(newsockfd, buf, n, 0);
    }

    close(newsockfd);

    return 0;
}