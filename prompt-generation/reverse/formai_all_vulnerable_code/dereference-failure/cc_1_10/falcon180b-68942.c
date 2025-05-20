//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <netdb.h>

int main() {
    int sockfd, newsockfd, portno, clilen, recv_len;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    portno = 8080;
    server = gethostbyname("127.0.0.1");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        fprintf(stdout, "Connection established with client at IP address %s\n", inet_ntoa(cli_addr.sin_addr));

        while (1) {
            recv_len = recv(newsockfd, buffer, sizeof(buffer), 0);
            if (recv_len <= 0) {
                fprintf(stdout, "Client disconnected\n");
                close(newsockfd);
                break;
            }

            fprintf(stdout, "Received message: %s\n", buffer);
            send(newsockfd, buffer, strlen(buffer), 0);
        }
    }

    close(sockfd);
    return 0;
}