//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    char buffer[1024];
    struct sockaddr_in serveraddr, clientaddr;
    int opt = 1;
    int addrlen = sizeof(serveraddr);

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        numbytes = recv(sockfd, buffer, sizeof(buffer), 0);
        if (numbytes <= 0) {
            printf("Error receiving data\n");
            break;
        }
        printf("Received data: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}