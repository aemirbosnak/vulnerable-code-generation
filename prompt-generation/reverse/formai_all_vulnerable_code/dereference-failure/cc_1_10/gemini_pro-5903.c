//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: ephemeral
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    struct addrinfo hints, *addr_info;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    int ret = getaddrinfo(argv[1], argv[2], &hints, &addr_info);
    if (ret < 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return EXIT_FAILURE;
    }
    
    int fd = socket(addr_info->ai_family, addr_info->ai_socktype, addr_info->ai_protocol);
    if (fd < 0) {
        perror("socket");
        freeaddrinfo(addr_info);
        return EXIT_FAILURE;
    }
    
    ret = connect(fd, addr_info->ai_addr, addr_info->ai_addrlen);
    if (ret < 0) {
        perror("connect");
        close(fd);
        freeaddrinfo(addr_info);
        return EXIT_FAILURE;
    }
    
    freeaddrinfo(addr_info);
    
    char *req = "GET / HTTP/1.1\r\nHost: "
                 "%s\r\n\r\n";
    int len = strlen(req) + strlen(argv[1]);
    
    char *buf = malloc(len);
    if (buf == NULL) {
        perror("malloc");
        close(fd);
        return EXIT_FAILURE;
    }
    
    snprintf(buf, len, req, argv[1]);
    
    ret = send(fd, buf, len, 0);
    if (ret < 0) {
        perror("send");
        free(buf);
        close(fd);
        return EXIT_FAILURE;
    }
    
    free(buf);
    
    char rbuf[4096];
    while ((ret = recv(fd, rbuf, sizeof(rbuf), 0)) > 0) {
        rbuf[ret] = '\0';
        printf("%s", rbuf);
    }
    
    if (ret < 0) {
        perror("recv");
        close(fd);
        return EXIT_FAILURE;
    }
    
    close(fd);
    return EXIT_SUCCESS;
}