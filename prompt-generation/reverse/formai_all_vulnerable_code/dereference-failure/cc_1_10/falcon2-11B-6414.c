//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname failed\n");
        exit(EXIT_FAILURE);
    }

    memset((char *) &serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);
    while (1) {
        if ((portno = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("Connected with %s\n", inet_ntoa(cli_addr.sin_addr));

        while ((n = recv(portno, NULL, 1, 0)) > 0) {
            printf("Received: %s\n", "Hello, World!");
        }

        close(portno);
    }

    return 0;
}