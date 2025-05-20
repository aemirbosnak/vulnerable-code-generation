//Falcon-180B DATASET v1.0 Category: Networking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    char buffer[1025];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    server = gethostbyname("127.0.0.1");

    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    portno = 8080;

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    clilen = sizeof(cli_addr);

    puts("Connected");

    while (1) {
        bzero(buffer, 1025);

        fgets(buffer, 1024, stdin);

        send(sockfd, buffer, strlen(buffer), 0);

        valread = read(sockfd, buffer, 1024);

        buffer[valread] = '\0';

        puts(buffer);

        if (strcmp(buffer, "exit") == 0) {
            close(sockfd);
            exit(1);
        }
    }

    return 0;
}