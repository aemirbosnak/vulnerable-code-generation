//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    int sockfd, len, n;
    struct hostent *host;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) host->h_addr, (char *) &serv_addr.sin_addr.s_addr, host->h_length);
    serv_addr.sin_port = htons(PORT);

    len = sizeof(serv_addr);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, len) < 0) {
        perror("connect failed");
        exit(1);
    }

    while (1) {
        n = read(sockfd, (char *) &serv_addr, sizeof(serv_addr));
        if (n < 0) {
            perror("read failed");
            exit(1);
        }

        if (n!= sizeof(serv_addr)) {
            fprintf(stderr, "read error\n");
            exit(1);
        }

        printf("Received data: %s\n", argv[1]);

        n = write(sockfd, "Hello, world!", 13);
        if (n < 0) {
            perror("write failed");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}