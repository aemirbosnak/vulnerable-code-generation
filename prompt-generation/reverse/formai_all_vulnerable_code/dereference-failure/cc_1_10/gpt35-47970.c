//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <fcntl.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket(struct sockaddr_in server) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket\n");

    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0)
        error("ERROR connecting\n");

    return sockfd;
}

void recursive_proxy(int browser_sockfd, struct sockaddr_in server_addr) {

    int server_sockfd = create_socket(server_addr);
    int maxfd = (browser_sockfd > server_sockfd) ? browser_sockfd : server_sockfd;
    fd_set readfds;

    while (1) {

        FD_ZERO(&readfds);
        FD_SET(browser_sockfd, &readfds);
        FD_SET(server_sockfd, &readfds);

        if (select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0)
            error("ERROR in select");

        if (FD_ISSET(browser_sockfd, &readfds)) {

            char buffer[10000];
            memset(buffer, 0, 10000);
            int n = read(browser_sockfd, buffer, 9999);
            if (n < 0) error("ERROR reading from browser");

            write(server_sockfd, buffer, n);
        }

        if (FD_ISSET(server_sockfd, &readfds)) {

            char buffer[10000];
            memset(buffer, 0, 10000);
            int n = read(server_sockfd, buffer, 9999);
            if (n < 0) error("ERROR reading from server");

            write(browser_sockfd, buffer, n);
        }
    }
}

int main(int argc, char *argv[]) {

    if (argc < 4 ) {
        fprintf(stderr,"usage %s <ip_address> <port> <proxy_port>\n", argv[0]);
        exit(0);
    }

    int proxy_port = atoi(argv[3]);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket\n");

    int option = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) < 0)
        error("ERROR setting socket options");

    struct sockaddr_in proxy_addr, server_addr;
    memset((char *) &proxy_addr, 0, sizeof(proxy_addr));
    memset((char *) &server_addr, 0, sizeof(server_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(proxy_port);

    if (bind(sockfd, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);
    socklen_t client_len = sizeof(server_addr);

    while (1) {

        int browser_sockfd = accept(sockfd, (struct sockaddr *) &server_addr, &client_len);
        if (browser_sockfd < 0) error("ERROR on accept");

        pid_t pid = fork();
        if (pid == 0) {
            close(sockfd);
            recursive_proxy(browser_sockfd, server_addr);
            exit(0);
        } 
        else if (pid < 0) error("ERROR on fork");
        else close(browser_sockfd);
    }

    close(sockfd);
    return 0;
}