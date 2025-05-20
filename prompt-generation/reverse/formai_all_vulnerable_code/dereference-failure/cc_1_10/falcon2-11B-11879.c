//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 3);

    int client_fd = accept(sockfd, NULL, NULL);
    if (client_fd < 0)
        error("ERROR on accept");

    char buffer[256];
    bzero(buffer, sizeof(buffer));

    while (1) {
        int n = recv(client_fd, buffer, sizeof(buffer), 0);
        if (n < 0)
            error("ERROR reading from socket");

        if (n == 0)
            break;

        send(client_fd, buffer, n, 0);
    }

    close(client_fd);
    close(sockfd);

    return 0;
}