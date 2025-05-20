//FormAI DATASET v1.0 Category: Network Ping Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n, portno, i;
    struct sockaddr_in serv_addr;
    struct in_addr ipv4addr;
    struct hostent *server;
    char buffer[256];

    if (argc < 2) {
      fprintf(stderr,"Usage: %s hostname [port]\n", argv[0]);
      exit(1);
    }

    portno = argc < 3 ? 80 : atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    printf("Pinging %s:%d:\n", argv[1], portno);

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    for (i = 1; i <= 10; i++) {
        if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
            printf("%d. Connection failed!\n", i);
        } else {
            inet_pton(AF_INET, argv[1], &ipv4addr);
            printf("%d. %s is alive! (%s)\n", i, argv[1], inet_ntoa(ipv4addr));
            close(sockfd);
            sleep(1);
        }
    }

    return 0;
}