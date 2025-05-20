//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT_NUMBER 80

void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        fprintf(stderr,"Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR: No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR: Could not open socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(PORT_NUMBER);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR: Could not connect");
    }

    char *request = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    sprintf(buffer, request, argv[1]);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR: Could not write to socket");
    }

    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        error("ERROR: Could not read from socket");
    }

    printf("%s\n", buffer);
    close(sockfd);
    return 0;
}