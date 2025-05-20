//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFLEN 65535

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, clientlen, optval;
    struct sockaddr_in serveraddr, clientaddr;
    char buf[BUFLEN];

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    /*initialize socket*/
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, 
         (const void *)&optval , sizeof(int));

    /*initialize server info*/
    bzero((char *)&serveraddr, sizeof(serveraddr));
    portno = atoi(argv[1]);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons((unsigned short)portno);

    /*bind socket to port*/
    if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
        error("ERROR on binding");

    printf("Server running at %s:%d...\n", inet_ntoa(serveraddr.sin_addr), portno);

    clientlen = sizeof(clientaddr);

    /*wait until client connects*/
    while (1) {
        bzero(buf, BUFLEN);

        /*receive packet from client*/
        if (recvfrom(sockfd, buf, BUFLEN, 0, 
             (struct sockaddr *)&clientaddr, &clientlen) < 0)
            error("ERROR in recvfrom");

        printf("[CLIENT] %s\n", buf);

        /*send packet back to client*/
        if (sendto(sockfd, buf, strlen(buf), 0, 
             (struct sockaddr *)&clientaddr, clientlen) < 0)
            error("ERROR in sendto");
    }

    /*close socket*/
    close(sockfd);
    return 0;
}