//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd, n, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char s[1024];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("google.com");

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Connected to google.com on port 80\n");

    if (send(sockfd, "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n", 59, 0) < 0) {
        perror("ERROR sending data");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, s, 1024, 0) < 0) {
        perror("ERROR receiving data");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", s);

    close(sockfd);
    return 0;
}