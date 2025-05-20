//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("ERROR on listen");
        exit(1);
    }

    while (1) {
        sockfd = accept(sockfd, NULL, NULL);
        if (sockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

        bzero(buffer, sizeof(buffer));
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        write(sockfd, buffer, n);
        printf("Received: %s\n", buffer);

        close(sockfd);
    }

    return 0;
}