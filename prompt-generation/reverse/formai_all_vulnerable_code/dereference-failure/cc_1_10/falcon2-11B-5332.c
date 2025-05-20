//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in servaddr, cliaddr;
    struct hostent *server;
    char buffer[BUFSIZ];

    if ((portno = atoi(getenv("PORT")))) {
        printf("Proxy server listening on port %d...\n", portno);
    } else {
        portno = 8080;
        printf("Proxy server listening on port 8080...\n");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("www.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(80); // change to your desired port

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting to server");
        exit(EXIT_FAILURE);
    }

    while (1) {
        bzero((char *) &cliaddr, sizeof(cliaddr));
        n = sizeof(cliaddr);

        if ((sockfd = accept(sockfd, (struct sockaddr *) &cliaddr, &n)) < 0) {
            perror("ERROR accepting connection");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        while ((n = read(sockfd, buffer, BUFSIZ)) > 0) {
            write(sockfd, buffer, n);
            bzero(buffer, BUFSIZ);
        }

        printf("Connection closed\n");
        close(sockfd);
    }

    return 0;
}