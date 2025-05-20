//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[1024];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    serv_addr.sin_port = htons(POP3_PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: could not connect to host\n");
        exit(1);
    }

    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        exit(1);
    }

    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "USER %s\r\n", argv[2]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket\n");
        exit(1);
    }

    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        exit(1);
    }

    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "STAT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket\n");
        exit(1);
    }

    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket\n");
        exit(1);
    }

    printf("%s", buffer);

    close(sockfd);

    return 0;
}