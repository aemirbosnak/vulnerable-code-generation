//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    char buffer[256];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(0);
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

    listen(sockfd, 3);

    while (1) {
        socklen_t clilen = sizeof(cli_addr);
        cli_addr.sin_family = AF_INET;
        cli_addr.sin_addr.s_addr = INADDR_ANY;
        cli_addr.sin_port = htons(portno);
        n = sizeof(serv_addr);
        if ((sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen)) < 0) {
            perror("accept");
            exit(1);
        }
        while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
            printf("Received: %s\n", buffer);
        }
        printf("Connection closed\n");
        close(sockfd);
        sleep(1);
    }

    return 0;
}