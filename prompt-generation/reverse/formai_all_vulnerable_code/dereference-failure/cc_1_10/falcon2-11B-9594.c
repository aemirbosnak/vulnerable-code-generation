//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "usage %s port_num\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        sockfd = accept(sockfd, NULL, NULL);
        if (sockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Received %d bytes: %s\n", n, buffer);
        n = write(sockfd, "Message received, thank you!\n", 26);
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        close(sockfd);
    }

    return 0;
}