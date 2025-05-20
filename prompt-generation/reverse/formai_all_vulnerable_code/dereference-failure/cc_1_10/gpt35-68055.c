//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Alan Touring
// Building a HTTP Client example program in Alan Touring style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    struct sockaddr_in server_addr;
    struct hostent *server;

    int sockfd, portno, n;

    char buffer[4096];

    if (argc < 3) {
        fprintf(stderr,"Usage: %s host port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portno);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    if (connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    char *query = "GET / HTTP/1.0\r\nHost: ";

    strcat(query, argv[1]);
    strcat(query, "\r\n\r\n");

    n = write(sockfd, query, strlen(query));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, sizeof(buffer));

    n = read(sockfd, buffer, sizeof(buffer));

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}