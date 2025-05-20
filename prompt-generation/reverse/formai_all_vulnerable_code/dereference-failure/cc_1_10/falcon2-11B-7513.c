//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    int yes = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 3);

    while (1) {
        socklen_t clilen = sizeof(struct sockaddr_in);
        int newsockfd = accept(sockfd, (struct sockaddr *) &serv_addr, &clilen);

        if (newsockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        bzero(buffer, 256);
        n = read(newsockfd, buffer, 256);

        if (n < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }

        buffer[n] = '\0';
        printf("Message received: %s\n", buffer);
        send(newsockfd, buffer, n, 0);
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}