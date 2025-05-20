//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
    int sockfd, portnum;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct servent *service;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error in socket");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    service = getservbyname("http", "tcp");
    if (service == NULL) {
        fprintf(stderr, "Error, no such service\n");
        exit(1);
    }

    portnum = service->s_port;

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portnum);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error in connect");
        exit(1);
    }

    printf("Connection established with %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    while (1) {
        int n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("Error reading from socket");
            exit(1);
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}