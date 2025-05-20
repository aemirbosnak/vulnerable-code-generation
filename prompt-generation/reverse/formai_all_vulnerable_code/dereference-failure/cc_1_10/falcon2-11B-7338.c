//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    int port = 80; // default port for HTTP

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    server = gethostbyname("www.example.com"); // replace with desired hostname
    if (server == NULL) {
        fprintf(stderr, "Error: Unable to resolve hostname\n");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(port);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    int n = read(sockfd, buffer, BUF_SIZE);
    if (n < 0) {
        perror("read");
        exit(1);
    }

    printf("Response: %s\n", buffer);

    close(sockfd);
    return 0;
}