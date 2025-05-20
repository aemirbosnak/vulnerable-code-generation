//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd, ret, val;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char *ip;
    int port;
    char *hostname;
    int i;
    char buffer[1025];
    struct timeval tv;
    fd_set readfds;
    int maxfd;

    if (argc!= 3) {
        printf("Usage: %s <hostname/ip> <port>\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    port = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);

    // Resolve hostname
    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    // Copy IP address to servaddr
    memcpy(&servaddr.sin_addr, server->h_addr, server->h_length);

    // Connect to server
    ret = connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    maxfd = sockfd;

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    ret = select(maxfd + 1, &readfds, NULL, NULL, &tv);
    if (ret == -1) {
        printf("Error selecting\n");
        exit(1);
    }

    if (FD_ISSET(sockfd, &readfds)) {
        ret = recv(sockfd, buffer, 1024, 0);
        if (ret == -1) {
            printf("Error receiving data\n");
            exit(1);
        }
        buffer[ret] = '\0';
        printf("Received data: %s\n", buffer);
    }

    close(sockfd);
    exit(0);
}