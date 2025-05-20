//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    char hostname[NI_MAXHOST];

    if ((server = gethostbyname("localhost")) == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    portno = htons(80);

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting\n");
        exit(1);
    }

    while (1) {
        n = read(sockfd, buffer, 1024);

        if (n < 0) {
            fprintf(stderr, "Error reading from socket\n");
            exit(1);
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}