//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE] = {0};

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr,"ERROR opening socket: %s\n", strerror(errno));
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr,"ERROR connecting: %s\n", strerror(errno));
        exit(1);
    }

    char *message = "GET / HTTP/1.1\r\nHost: www.example.org\r\nUser-Agent: Mozilla/5.0\r\nConnection: close\r\n\r\n";
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    while ((n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    if (n < 0) {
        fprintf(stderr,"ERROR reading from socket: %s\n", strerror(errno));
        exit(1);
    }

    close(sockfd);
    return 0;
}