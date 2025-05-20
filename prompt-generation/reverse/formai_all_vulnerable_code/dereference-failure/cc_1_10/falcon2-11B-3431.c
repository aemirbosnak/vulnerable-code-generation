//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in servaddr;

    if (argc!= 3) {
        fprintf(stderr,"Usage: %s <target host> <target port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(portno);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "ERROR, invalid address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to %s on port %d\n", argv[1], ntohs(servaddr.sin_port));

    if (send(sockfd, "Hello, world!", 13, 0) < 0) {
        perror("ERROR sending data");
        exit(1);
    }

    if (recv(sockfd, "Received: ", 9, 0) < 0) {
        perror("ERROR receiving data");
        exit(1);
    }

    printf("Received: %s\n", "Received: ");

    if (close(sockfd) < 0) {
        perror("ERROR closing socket");
        exit(1);
    }

    return 0;
}