//Falcon2-11B DATASET v1.0 Category: Browser Plugin ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PACKET_SIZE 1024
#define PORT 8080

int main(int argc, char* argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char filename[1024];
    strcpy(filename, argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    while ((sockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen)) > 0) {
        if ((n = read(sockfd, filename, MAX_PACKET_SIZE)) <= 0) {
            perror("read");
            exit(1);
        }
        write(sockfd, filename, n);
    }

    close(sockfd);
    return 0;
}