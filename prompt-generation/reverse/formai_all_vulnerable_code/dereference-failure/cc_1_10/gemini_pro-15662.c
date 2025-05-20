//GEMINI-pro DATASET v1.0 Category: Networking ; Style: invasive
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

// A simple echo server that listens on a specified port and echoes back any data it receives.

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if (bind(listenfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(listenfd, 10) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        struct sockaddr_in cliaddr;
        socklen_t len = sizeof(cliaddr);
        int connfd = accept(listenfd, (struct sockaddr*) &cliaddr, &len);
        if (connfd < 0) {
            perror("accept");
            continue;
        }

        char buf[1024];
        int n;
        while ((n = read(connfd, buf, sizeof(buf))) > 0) {
            if (write(connfd, buf, n) < 0) {
                perror("write");
                break;
            }
        }

        if (n < 0) {
            perror("read");
        }

        close(connfd);
    }

    close(listenfd);

    return 0;
}