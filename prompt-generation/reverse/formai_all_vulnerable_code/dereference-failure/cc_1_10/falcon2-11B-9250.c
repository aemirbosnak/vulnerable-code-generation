//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_CLIENTS 5

int main() {
    int sockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1024];
    int n;
    int clients[MAX_CLIENTS];
    int count = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname failed\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(1234);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);
    while (1) {
        clilen = sizeof(cli_addr);
        cli_addr.sin_family = AF_INET;
        cli_addr.sin_port = 0;
        cli_addr.sin_addr.s_addr = 0;
        sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (sockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        printf("Connection from: %s\n", inet_ntoa(cli_addr.sin_addr));
        clients[count] = sockfd;
        count++;
        if (count == MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            break;
        }
        while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
            write(sockfd, buffer, n);
        }
        close(sockfd);
        count--;
    }

    close(sockfd);
    return 0;
}