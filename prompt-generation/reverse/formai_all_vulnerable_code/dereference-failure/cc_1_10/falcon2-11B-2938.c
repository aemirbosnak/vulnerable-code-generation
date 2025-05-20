//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define SERVER_PORT 8080

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "usage: %s <hostname>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(0);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("ERROR opening socket");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    char buffer[1024];

    while ((n = read(sockfd, buffer, 1024)) > 0) {
        printf("%s", buffer);
        fflush(stdout);
    }

    if (n < 0)
        error("ERROR reading from socket");

    close(sockfd);

    return 0;
}