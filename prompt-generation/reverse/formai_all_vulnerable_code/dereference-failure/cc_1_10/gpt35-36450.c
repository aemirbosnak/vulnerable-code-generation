//FormAI DATASET v1.0 Category: Port Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Usage: ./love_port_scanner <ip> <port>\n");
        exit(1);
    }
    
    printf("Starting our Love Port Scanner...\n");
    printf("Scanning for Love on %s:%s\n", argv[1], argv[2]);

    int sockfd, flags;
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    fcntl(sockfd, F_SETFL, O_NONBLOCK);

    addr.sin_family = AF_INET;
    inet_aton(argv[1], &addr.sin_addr);
    addr.sin_port = htons(atoi(argv[2]));

    connect(sockfd, (struct sockaddr *)&addr, len);

    fd_set set;
    FD_ZERO(&set);
    FD_SET(sockfd, &set);

    struct timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    int res = select(sockfd + 1, NULL, &set, NULL, &timeout);

    if (res == -1) {
        printf("Our love is blocked by a firewall...\n");
    } else if (res == 0) {
        printf("Sorry, our love hasn't been received yet.\n");
    } else {
        printf("Our love has been received, the port is open!\n");
    }

    close(sockfd);
    return 0;
}