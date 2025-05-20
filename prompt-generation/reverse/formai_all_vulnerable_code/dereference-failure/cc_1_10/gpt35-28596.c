//FormAI DATASET v1.0 Category: Firewall ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

/* IP address to block */
#define BLOCK_IP "192.168.0.1"
/* Port number to block */
#define BLOCK_PORT 8080

/* The main function */
int main() {
    int fd;
    struct sockaddr_in addr;
    struct iphdr *ip;
    struct tcphdr *tcp;
    char buf[65535];

    /* Create a socket */
    if ((fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* Set the address to bind to */
    addr.sin_family = AF_INET;
    addr.sin_port = htons(BLOCK_PORT);
    addr.sin_addr.s_addr = inet_addr(BLOCK_IP);

    /* Bind the socket to the address */
    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    /* Loop forever, receiving packets and checking for the blocked IP */
    while (1) {
        ssize_t n = recv(fd, buf, sizeof(buf), 0);
        if (n == -1) {
            perror("recv");
            continue;
        }

        /* Parse the IP header */
        ip = (struct iphdr*)buf;

        /* Check if the source IP is the one we want to block */
        if (ip->saddr == addr.sin_addr.s_addr) {
            /* Parse the TCP header */
            tcp = (struct tcphdr*)(buf + (ip->ihl * 4));

            /* Drop the packet */
            printf("Blocked packet from %s:%d\n", BLOCK_IP, BLOCK_PORT);
            continue;
        }

        /* Pass the packet along */
        printf("Received packet from %s:%d\n", inet_ntoa(*(struct in_addr *)&ip->saddr), htons(tcp->source));
    }

    /* Close the socket */
    close(fd);
    return 0;
}