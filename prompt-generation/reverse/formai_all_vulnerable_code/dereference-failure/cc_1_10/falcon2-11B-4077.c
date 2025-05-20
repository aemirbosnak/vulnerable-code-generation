//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: shocked
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    if (argc < 2) {
        fprintf(stderr, "Usage %s <port>\n", argv[0]);
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
        exit(0);
    }

    listen(sockfd, 5);

    while (1) {
        sockfd = accept(sockfd, NULL, NULL);

        if (sockfd < 0) {
            perror("accept");
            exit(0);
        }

        bzero(buffer, 1024);

        n = read(sockfd, buffer, 1024);

        if (n < 0) {
            perror("read");
            exit(0);
        }

        buffer[n] = '\0';

        if (strcmp(buffer, "firewall") == 0) {
            write(sockfd, "firewall off", 14);
        } else if (strcmp(buffer, "firewall on") == 0) {
            write(sockfd, "firewall on", 12);
        } else {
            write(sockfd, "firewall: invalid command", 30);
        }

        close(sockfd);
    }

    return 0;
}