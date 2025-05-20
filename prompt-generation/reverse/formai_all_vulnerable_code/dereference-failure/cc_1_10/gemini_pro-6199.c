//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

// A simple echo server using sockets

int main(int argc, char* argv[]) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to an address and port
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    struct sockaddr_in cliaddr;
    socklen_t clilen = sizeof(cliaddr);
    int connfd;

    while (1) {
        connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &clilen);
        if (connfd == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Handle the connection
        char buf[1024];
        int n;

        while ((n = read(connfd, buf, sizeof(buf))) > 0) {
            if (write(connfd, buf, n) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        if (n == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Close the connection
        close(connfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}