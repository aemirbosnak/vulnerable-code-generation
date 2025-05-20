//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];
    char *host = argv[1]; // Replace with the server's IP address
    int port = atoi(argv[2]); // Replace with the server's port number

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 3);

    while (1) {
        socklen_t clilen = sizeof(struct sockaddr_in);
        int newsockfd = accept(sockfd, (struct sockaddr *) &serv_addr, &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        printf("Got connection from %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

        while ((n = recv(newsockfd, buffer, BUF_SIZE, 0)) > 0) {
            printf("Received %d bytes from client: %s\n", n, buffer);
            send(newsockfd, buffer, n, 0);
        }

        printf("Connection closed from %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}