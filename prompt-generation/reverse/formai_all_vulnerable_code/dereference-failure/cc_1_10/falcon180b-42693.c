//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX 100
#define TRUE 1
#define FALSE 0
#define PORT 22

void scan_network(char* network, int netmask) {
    int sockfd, newsockfd, addrlen, bytes_received;
    char buffer[1024];
    struct sockaddr_in server_addr, client_addr;
    char *ip;
    int opt = TRUE;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    inet_pton(AF_INET, network, &server_addr.sin_addr);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    addrlen = sizeof(struct sockaddr_in);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen);

        inet_ntop(AF_INET, &client_addr.sin_addr, ip, sizeof(ip));

        printf("Connection from %s\n", ip);

        close(newsockfd);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <network> <netmask>\n", argv[0]);
        return 1;
    }

    char network[MAX];
    strcpy(network, argv[1]);

    int netmask = atoi(argv[2]);

    scan_network(network, netmask);

    return 0;
}