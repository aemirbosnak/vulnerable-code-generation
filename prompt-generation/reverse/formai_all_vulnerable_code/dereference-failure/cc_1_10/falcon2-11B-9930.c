//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ultraprecise
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *server;

    if (argc!= 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5000);
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    while (1) {
        char buffer[1024];
        ssize_t nread;

        nread = read(sockfd, buffer, sizeof(buffer));
        if (nread < 0) {
            perror("read");
            return 1;
        }

        printf("Received: %s\n", buffer);
    }

    return 0;
}