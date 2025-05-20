//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: scientific
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
    char buffer[100];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        sockfd = accept(sockfd, NULL, NULL);

        printf("Connected to client\n");
        printf("Receiving data...\n");

        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n < 0) {
            perror("recv");
            close(sockfd);
            continue;
        }

        printf("Received %d bytes\n", n);
        printf("Sending back data\n");

        send(sockfd, buffer, n, 0);
        close(sockfd);
        break;
    }

    return 0;
}