//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_DATA_LEN 64

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo *addrinfo;
    char hostname[MAX_HOSTNAME_LEN];
    char data[MAX_DATA_LEN];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname message\n", argv[0]);
        return 1;
    }

    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN - 1);
    strncpy(data, argv[2], MAX_DATA_LEN - 1);

    if ((addrinfo = getaddrinfo(hostname, NULL, NULL, NULL)) == NULL) {
        fprintf(stderr, "Error resolving hostname: %s\n", gai_strerror(errno));
        return 1;
    }

    sockfd = socket(addrinfo->ai_family, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    sendto(sockfd, data, strlen(data), 0, addrinfo->ai_addr, addrinfo->ai_addrlen);
    freeaddrinfo(addrinfo);

    char buffer[MAX_DATA_LEN];
    memset(buffer, 0, MAX_DATA_LEN);
    int bytes_received = recv(sockfd, buffer, MAX_DATA_LEN, 0);

    if (bytes_received == -1) {
        fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    printf("Received message: %s\n", buffer);

    close(sockfd);
    return 0;
}