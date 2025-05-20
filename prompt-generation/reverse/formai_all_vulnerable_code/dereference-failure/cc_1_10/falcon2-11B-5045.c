//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>

#define BACKLOG 10
#define MAXLINE 1024

void catch_sigint(int sig) {
    printf("Interrupted by user!\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <port> <filename>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    char *filename = argv[2];

    int serverfd, newsockfd;
    struct sockaddr_in servaddr, cliaddr;
    int addrlen = sizeof(servaddr);

    signal(SIGINT, catch_sigint);

    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    if (bind(serverfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(serverfd, BACKLOG) < 0) {
        perror("ERROR on listening");
        exit(1);
    }

    while (1) {
        newsockfd = accept(serverfd, (struct sockaddr *)&cliaddr, (socklen_t*)&addrlen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
        int file = open(filename, O_RDONLY);
        if (file < 0) {
            printf("ERROR opening file %s\n", filename);
            exit(1);
        }

        char buf[MAXLINE];
        while (1) {
            int n = read(newsockfd, buf, sizeof(buf));
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }

            if (n == 0)
                break;

            int nwrite = write(newsockfd, buf, n);
            if (nwrite < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }

            if (nwrite!= n) {
                printf("WARNING: only wrote %d of %d bytes\n", nwrite, n);
            }
        }

        printf("Disconnected from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
        close(newsockfd);
    }

    close(serverfd);
    return 0;
}