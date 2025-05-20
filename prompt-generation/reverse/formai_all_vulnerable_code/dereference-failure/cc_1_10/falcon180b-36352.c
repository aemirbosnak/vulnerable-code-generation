//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct addrinfo *addr_info;
    struct addrinfo hints = {
       .ai_family = AF_INET,
       .ai_socktype = SOCK_STREAM,
       .ai_protocol = IPPROTO_TCP
    };
    char *ip = argv[1];
    int port = atoi(argv[2]);

    if (argc!= 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    ret = getaddrinfo(ip, NULL, &hints, &addr_info);
    if (ret!= 0) {
        printf("Failed to resolve hostname: %s\n", gai_strerror(ret));
        exit(1);
    }

    sockfd = socket(addr_info->ai_family, addr_info->ai_socktype, addr_info->ai_protocol);
    if (sockfd == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        exit(1);
    }

    ret = connect(sockfd, addr_info->ai_addr, addr_info->ai_addrlen);
    if (ret == -1) {
        printf("Failed to connect: %s\n", strerror(errno));
        exit(1);
    }

    char send_buf[] = "PING";
    send(sockfd, send_buf, strlen(send_buf), 0);

    char recv_buf[1024];
    memset(recv_buf, 0, sizeof(recv_buf));
    ret = recv(sockfd, recv_buf, sizeof(recv_buf), 0);
    if (ret == -1) {
        printf("Failed to receive data: %s\n", strerror(errno));
        exit(1);
    }

    printf("Received response: %s\n", recv_buf);

    close(sockfd);
    freeaddrinfo(addr_info);

    return 0;
}