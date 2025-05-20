//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        printf("Waiting for connection...\n");
        if ((n = accept(sockfd, (struct sockaddr *) NULL, NULL)) < 0) {
            perror("accept");
            exit(1);
        }

        char buffer[1024];
        bzero(buffer, sizeof(buffer));

        while ((n = recv(n, buffer, sizeof(buffer), 0)) > 0) {
            printf("Received: %s\n", buffer);
            bzero(buffer, sizeof(buffer));
        }

        close(n);
    }

    close(sockfd);
    return 0;
}