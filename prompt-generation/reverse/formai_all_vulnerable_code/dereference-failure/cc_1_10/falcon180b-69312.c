//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, opt = 1, ret;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (ret <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        printf("Received data: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}