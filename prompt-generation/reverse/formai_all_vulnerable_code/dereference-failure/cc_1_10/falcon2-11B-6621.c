//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 100

int main(int argc, char *argv[])
{
    int port;
    struct sockaddr_in server;
    int sockfd, newsockfd, valread;
    int yes = 1;

    if (argc!= 2) {
        printf("Usage: %s <target_host> <target_port>\n", argv[0]);
        return 1;
    }

    if (inet_aton(argv[1], &server.sin_addr) <= 0) {
        printf("Invalid hostname or IP address\n");
        return 1;
    }

    port = atoi(argv[2]);
    if (port <= 0 || port > 65535) {
        printf("Invalid port number\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    bzero(&(server.sin_zero), 8);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    printf("Port %d is open\n", port);

    close(sockfd);
    return 0;
}