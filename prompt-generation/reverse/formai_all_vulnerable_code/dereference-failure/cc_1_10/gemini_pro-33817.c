//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>

// Macros
#define BUFLEN 1500

// Function prototypes
int create_raw_socket(void);
void send_ping(int sockfd, struct sockaddr_in *addr, char *payload);
void recv_pong(int sockfd);

// Global variables
int sockfd = -1;
struct sockaddr_in addr;

// Main function
int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <payload>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a raw socket
    sockfd = create_raw_socket();
    if (sockfd == -1) {
        perror("create_raw_socket");
        exit(EXIT_FAILURE);
    }

    // Set the address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Send a ping
    send_ping(sockfd, &addr, argv[2]);

    // Receive a pong
    recv_pong(sockfd);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}

// Function to create a raw socket
int create_raw_socket(void) {
    // Create a raw socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        return -1;
    }

    // Set the IP_HDRINCL option
    int optval = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(optval)) == -1) {
        close(sockfd);
        return -1;
    }

    return sockfd;
}

// Function to send a ping
void send_ping(int sockfd, struct sockaddr_in *addr, char *payload) {
    // Create an ICMP header
    struct icmphdr icmphdr;
    memset(&icmphdr, 0, sizeof(icmphdr));
    icmphdr.type = ICMP_ECHO;
    icmphdr.code = 0;
    icmphdr.un.echo.id = getpid();
    icmphdr.un.echo.sequence = 1;

    // Create an IP header
    struct iphdr iphdr;
    memset(&iphdr, 0, sizeof(iphdr));
    iphdr.version = 4;
    iphdr.ihl = 5;
    iphdr.tos = 0;
    iphdr.tot_len = htons(sizeof(iphdr) + sizeof(icmphdr) + strlen(payload));
    iphdr.id = getpid();
    iphdr.frag_off = 0;
    iphdr.ttl = 255;
    iphdr.protocol = IPPROTO_ICMP;
    iphdr.saddr = 0;
    iphdr.daddr = addr->sin_addr.s_addr;

    // Create a buffer
    char buf[BUFLEN];
    memset(buf, 0, BUFLEN);
    memcpy(buf, &iphdr, sizeof(iphdr));
    memcpy(buf + sizeof(iphdr), &icmphdr, sizeof(icmphdr));
    strcpy(buf + sizeof(iphdr) + sizeof(icmphdr), payload);

    // Send the ping
    if (sendto(sockfd, buf, sizeof(iphdr) + sizeof(icmphdr) + strlen(payload), 0, (struct sockaddr *)addr, sizeof(*addr)) == -1) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }
}

// Function to receive a pong
void recv_pong(int sockfd) {
    // Create a buffer
    char buf[BUFLEN];
    memset(buf, 0, BUFLEN);

    // Receive the pong
    if (recvfrom(sockfd, buf, BUFLEN, 0, NULL, NULL) == -1) {
        perror("recvfrom");
        exit(EXIT_FAILURE);
    }

    // Check the ICMP header
    struct icmphdr *icmphdr = (struct icmphdr *)(buf + sizeof(struct iphdr));
    if (icmphdr->type != ICMP_ECHOREPLY || icmphdr->code != 0 || icmphdr->un.echo.id != getpid() || icmphdr->un.echo.sequence != 1) {
        fprintf(stderr, "Invalid ICMP header\n");
        exit(EXIT_FAILURE);
    }

    // Print the payload
    printf("%s\n", buf + sizeof(struct iphdr) + sizeof(struct icmphdr));
}