//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_IP_ADDR_LENGTH 256
#define PORT_NUM 80

int is_valid_ip_address(const char *ip_address) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip_address, &(sa.sin_addr));
    return result != 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Please provide IP address as argument.\n");
        return 1;
    }

    char *ip_address = argv[1];

    if (!is_valid_ip_address(ip_address)) {
        printf("Invalid IP address provided.\n");
        return 1;
    }

    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket.\n");
        return 1;
    }

    server = gethostbyname(ip_address);
    if (server == NULL) {
        printf("Error resolving host.\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT_NUM);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        printf("Error connecting to host.\n");
        return 1;
    }

    char remote_ip_address[MAX_IP_ADDR_LENGTH];
    struct sockaddr_in local_addr;
    socklen_t addrlen = sizeof(local_addr);

    if (getsockname(sockfd, (struct sockaddr *)&local_addr, &addrlen) == -1) {
        printf("Error getting local IP address.\n");
        return 1;
    }

    inet_ntop(AF_INET, &(local_addr.sin_addr), remote_ip_address, INET_ADDRSTRLEN);

    printf("Connected to %s from %s\n", ip_address, remote_ip_address);

    close(sockfd);

    return 0;
}