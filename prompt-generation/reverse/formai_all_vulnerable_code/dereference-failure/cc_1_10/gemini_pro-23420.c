//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname filename\n", argv[0]);
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr,"ERROR opening socket\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr,"ERROR connecting\n");
        exit(0);
    }

    FILE *fp = fopen(argv[2], "rb");
    if (fp == NULL) {
        fprintf(stderr,"ERROR opening file\n");
        exit(0);
    }

    char buffer[1024];
    while ((n = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        if (send(sockfd, buffer, n, 0) < 0) {
            fprintf(stderr,"ERROR writing to socket\n");
            exit(0);
        }
    }

    fclose(fp);
    close(sockfd);

    return 0;
}