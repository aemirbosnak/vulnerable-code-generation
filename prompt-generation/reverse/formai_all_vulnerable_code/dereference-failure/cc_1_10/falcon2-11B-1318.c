//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char *filename = argv[1];

    if ((server = gethostbyname("localhost")) == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = *((unsigned long *)server->h_addr);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    send(sockfd, "GET / HTTP/1.1\r\n", 28, 0);
    send(sockfd, "Host: localhost\r\n", 19, 0);
    send(sockfd, "Connection: close\r\n", 25, 0);
    send(sockfd, "Content-Length: 0\r\n\r\n", 28, 0);

    recv(sockfd, filename, 1024, 0);

    if (close(sockfd) < 0) {
        perror("ERROR closing socket");
        return 1;
    }

    return 0;
}