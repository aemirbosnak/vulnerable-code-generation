//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

#define MAXDATASIZE 256

void sigpipe_handler(int sig) {
    exit(0);
}

int main(int argc, char *argv[]) {

    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    char *host, *port;
    struct addrinfo hints, *res;
    struct sockaddr_in server_addr;

    if (argc != 3) {
        fprintf(stderr, "usage: %s host port\n", argv[0]);
        return 1;
    }

    host = argv[1];
    port = argv[2];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, port, &hints, &res) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        return 1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        freeaddrinfo(res);
        return 1;
    }

    // set up non-blocking I/O
    int flags = fcntl(sockfd, F_GETFL);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);

    // set up SIGPIPE handler
    signal(SIGPIPE, sigpipe_handler);

    // connect to the server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        if (errno != EINPROGRESS) {
            perror("connect");
            freeaddrinfo(res);
            close(sockfd);
            return 1;
        }
    }

    freeaddrinfo(res);

    while (1) {
        // read from the socket
        numbytes = recv(sockfd, buf, MAXDATASIZE, 0);
        if (numbytes > 0) {
            // echo the message back to the server
            if (send(sockfd, buf, numbytes, 0) == -1) {
                perror("send");
                close(sockfd);
                return 1;
            }
        } else if (numbytes == 0) {
            // the server has closed the connection
            close(sockfd);
            break;
        } else if (errno == EAGAIN) {
            // the socket is non-blocking so this means there is no data to read
            continue;
        } else {
            perror("recv");
            close(sockfd);
            return 1;
        }
    }

    return 0;
}