//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    int sockfd, valread;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 3);

    cli_addr.sin_family = AF_INET;
    cli_addr.sin_port = htons(0);
    cli_addr.sin_addr.s_addr = INADDR_ANY;

    valread = sizeof(cli_addr);
    sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &valread);
    if (sockfd < 0) {
        perror("accept");
        exit(1);
    }

    int n = read(sockfd, buf, sizeof(buf));
    if (n < 0) {
        perror("read");
        exit(1);
    }

    printf("Received: %s\n", buf);

    n = write(sockfd, "Thank you for connecting!", sizeof("Thank you for connecting!"));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    close(sockfd);

    return 0;
}