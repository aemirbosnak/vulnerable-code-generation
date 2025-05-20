//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define BACKLOG 5
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct protoent *proto;
    char buf[MAXLINE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server name>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    proto = getprotobyname("tcp");
    if (proto == NULL) {
        fprintf(stderr, "Error, no such protocol\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, proto->p_proto);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        n = read(sockfd, buf, MAXLINE);
        if (n < 0) {
            perror("read");
            exit(1);
        } else if (n == 0) {
            printf("Server closed the connection.\n");
            break;
        }

        printf("%s", buf);
    }

    close(sockfd);
    return 0;
}