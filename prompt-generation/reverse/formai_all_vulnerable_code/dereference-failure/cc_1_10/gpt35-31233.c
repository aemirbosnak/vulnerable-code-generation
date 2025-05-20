//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define MAX_SIZE 4096

void set_nonblocking(int fd) {
    int flags;
    if ((flags = fcntl(fd, F_GETFL, 0)) == -1) {
        perror("fcntl");
        exit(1);
    }
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(1);
    }
    char *host = argv[1];
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(host);
    sa.sin_port = htons(80);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
    set_nonblocking(sockfd);
    if (connect(sockfd, (struct sockaddr *)&sa, sizeof(struct sockaddr_in)) < 0) {
        if (errno != EINPROGRESS) {
            perror("connect");
            exit(1);
        }
    }
    char request[MAX_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
    int request_len = strlen(request);
    fd_set wfds;
    struct timeval tv;
    FD_ZERO(&wfds);
    FD_SET(sockfd, &wfds);
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    int rv = select(sockfd + 1, NULL, &wfds, NULL, &tv);
    if (rv == -1) {
        perror("select");
        exit(1);
    } else if (rv == 0) {
        printf("Timeout waiting for socket to be writable");
        exit(1);
    }
    if ((rv = send(sockfd, request, request_len, 0)) != request_len) {
        if (rv == -1) {
            perror("send");
        } else {
            printf("send returned short (%d/%d)", rv, request_len);
        }
        exit(1);
    }
    char response[MAX_SIZE];
    int response_len = 0;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    if ((rv = select(sockfd + 1, &rfds, NULL, NULL, &tv)) == -1) {
        perror("select");
        exit(1);
    } else if (rv == 0) {
        printf("Timeout waiting for socket to be readable");
        exit(1);
    }
    if ((rv = recv(sockfd, response, MAX_SIZE, 0)) == -1) {
        if (errno == EAGAIN) {
            printf("No data available\n");
        } else {
            perror("recv");
        }
    } else {
        response_len += rv;
        response[response_len] = '\0';
    }
    printf("Response:\n%s\n", response);
    close(sockfd);
    return 0;
}