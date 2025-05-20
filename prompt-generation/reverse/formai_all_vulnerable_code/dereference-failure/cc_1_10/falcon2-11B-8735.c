//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: high level of detail
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXLINE 1024
#define HOST "www.google.com"
#define PORT 80

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXLINE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <number_of_pings>\n", argv[0]);
        exit(1);
    }

    int num_pings = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(HOST);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    for (int i = 0; i < num_pings; i++) {
        n = send(sockfd, "GET / HTTP/1.1\r\n\r\n", strlen("GET / HTTP/1.1\r\n\r\n"), 0);
        if (n < 0) {
            perror("Error sending data");
            exit(1);
        }

        bzero(buffer, MAXLINE);
        n = recv(sockfd, buffer, MAXLINE, 0);
        if (n < 0) {
            perror("Error receiving data");
            exit(1);
        }

        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}