//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sendfile.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <server> <port> <file>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *port = argv[2];
    char *file = argv[3];

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(server, port, &hints, &result)!= 0) {
        error("getaddrinfo");
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        error("socket");
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        error("connect");
    }

    char cmd[1024];
    sprintf(cmd, "STOR %s\r\n", file);
    send(sockfd, cmd, strlen(cmd), 0);

    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        error("open");
    }

    char buffer[BUFFER_SIZE];
    while ((size_t)read(fd, buffer, BUFFER_SIZE) > 0) {
        send(sockfd, buffer, strlen(buffer), 0);
    }

    close(fd);
    close(sockfd);

    return 0;
}