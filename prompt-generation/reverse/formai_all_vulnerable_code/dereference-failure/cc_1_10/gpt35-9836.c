//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFLEN 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFLEN];

    // check if user provided enough arguments
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(EXIT_FAILURE);
    }

    // get server details
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    // set server address
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // connect to server
    if (connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR connecting\n");
        exit(EXIT_FAILURE);
    }

    // send HTTP request
    char* request = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: keep-alive\r\n\r\n";
    sprintf(buffer, request, argv[1]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        exit(EXIT_FAILURE);
    }

    // receive HTTP response
    memset(buffer, 0, BUFLEN);
    while ((n = read(sockfd, buffer, BUFLEN-1)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFLEN);
    }
    if (n < 0) {
        fprintf(stderr, "ERROR reading from socket\n");
        exit(EXIT_FAILURE);
    }

    // close socket
    close(sockfd);

    return 0;
}