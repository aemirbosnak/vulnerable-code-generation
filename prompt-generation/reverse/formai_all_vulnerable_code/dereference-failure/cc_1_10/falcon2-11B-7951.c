//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char* argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connection established!\n");

    if (send(sockfd, "Hello World", 13, 0) < 0) {
        perror("send");
        exit(1);
    }

    if (recv(sockfd, "Received", 8, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("Received: %s\n", "Received");

    if (close(sockfd) < 0) {
        perror("close");
        exit(1);
    }

    return 0;
}