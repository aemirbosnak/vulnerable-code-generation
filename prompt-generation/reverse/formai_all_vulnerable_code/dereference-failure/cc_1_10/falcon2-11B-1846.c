//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc!= 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "no such host\n");
        exit(2);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(3);
    }

    while (1) {
        char buffer[100];
        int len = read(sockfd, buffer, 100);

        if (len < 0) {
            perror("read");
            exit(4);
        }

        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}