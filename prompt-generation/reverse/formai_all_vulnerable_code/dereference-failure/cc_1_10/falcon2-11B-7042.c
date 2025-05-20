//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname count\n", argv[0]);
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Unknown host\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(5000);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    for (n = 0; n < atoi(argv[2]); n++) {
        if (send(sockfd, "Hello, world!", 13, 0) < 0) {
            perror("send");
            return 1;
        }
        if (recv(sockfd, "Hello, world!", 13, 0) < 0) {
            perror("recv");
            return 1;
        }
    }

    close(sockfd);

    return 0;
}