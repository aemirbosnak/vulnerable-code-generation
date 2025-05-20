//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LEN 1000

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[MAX_LEN];
    int n, len;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error in creating socket\n");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("Error in getting host\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    portno = 8080;
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error in connecting\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        bzero(buffer, MAX_LEN);
        fgets(buffer, MAX_LEN, stdin);
        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            printf("Error in sending message\n");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}