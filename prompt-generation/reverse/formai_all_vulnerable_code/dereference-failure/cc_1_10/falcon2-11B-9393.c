//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: accurate
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, valread, portno;
    struct sockaddr_in serveraddr;
    struct hostent *server;

    if (argc!= 2) {
        printf("Usage: %s <port number>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[1]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    server = gethostbyname("localhost");

    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        return 1;
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        return 1;
    }

    while (1) {
        valread = read(sockfd, " ", 1);

        if (valread < 0) {
            perror("read");
            return 1;
        }

        if (valread == 0)
            break;

        if (valread == '\n')
            continue;

        printf("Packet dropped: %s\n", "Invalid input");
    }

    return 0;
}