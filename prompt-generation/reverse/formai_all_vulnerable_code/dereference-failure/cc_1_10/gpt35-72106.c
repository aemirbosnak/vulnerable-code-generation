//FormAI DATASET v1.0 Category: Network Ping Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

// Define the size of the buffer used in the ping packet
#define PING_PKT_SIZE 64

// Define the maximum time in seconds to wait for a server response
#define MAX_WAIT_TIME 5

// Define the max number of ping requests to be sent
#define MAX_PING_REQUESTS 100

struct ping_pkt {
    struct icmphdr hdr;
    char msg[PING_PKT_SIZE - sizeof(struct icmphdr)];
};

// Calculates the ChecksumValue of given data
unsigned short checksum(void *b, int len)
{    
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for ( sum = 0; len > 1; len -=2 )
        sum += *buf++;

    if ( len == 1 )
        sum += *(unsigned char*)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

// Pings the server and prints the results
void ping(struct sockaddr_in *addr, int seq)
{
    // Create a socket for ICMP packets
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd < 0) {
        perror("Ping: Socket Creation Failed. Aborting");
        return;
    }

    // Setting up the packet headers
    struct ping_pkt packet;
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    packet.hdr.un.echo.sequence = seq;

    memset(&packet.msg, 0x00, sizeof(packet.msg));
    clock_t ts;
    ts = clock();
    strncpy(packet.msg, "Hello from Ping App", sizeof(packet.msg) - 1);
    packet.hdr.checksum = checksum(&packet, sizeof(packet));

    // Send the packet to the address
    int sentsize = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)addr, sizeof(*addr));

    if (sentsize <= 0) {
        perror("Ping: Error Sending Packet. Aborting");
        close(sockfd);
        return;
    }

    // Get the response packet back from the address
    unsigned char buf[256];
    socklen_t addrlen = sizeof(addr);
    ssize_t nbytes = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)addr, &addrlen);

    if (nbytes < 0) {
        perror("Ping: No Response from Host. Aborting");
    } else {
        // Record the current timestamp and calculate round-trip-time
        ts = clock() - ts;
        double time_taken = ((double)ts) / CLOCKS_PER_SEC * 1000;

        // Print the results of the ping
        struct iphdr *ip = (struct iphdr*)buf;
        struct icmphdr *icmp = (struct icmphdr*)(buf + (ip->ihl << 2));

        if ((icmp->type == ICMP_ECHOREPLY) && (icmp->un.echo.id == getpid())) {
            printf("Ping: Reply received from %s: icmp_seq=%d ttl=%d time=%.1f ms\n",
                    inet_ntoa(addr->sin_addr), seq, ip->ttl, time_taken);
        } else {
            printf("Ping: Invalid reply from %s. Skipping\n", inet_ntoa(addr->sin_addr));
        }
    }

    close(sockfd);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./ping [hostname / IP Address]\n");
        exit(1);
    }

    struct hostent *host = gethostbyname(argv[1]);

    // Ensure that the hostname was resolved successfully
    if (!host) {
        printf("Ping: Cannot resolve the IP address of '%s'\n", argv[1]);
        exit(1);
    }

    // Create a sockaddr_in struct to store the IP address
    struct sockaddr_in addr;
    memset(&addr, 0x00, sizeof(addr));
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Start sending ping packets
    printf("Ping %s:\n", argv[1]);

    for (int seq = 1; seq <= MAX_PING_REQUESTS; ++seq) {
        ping(&addr, seq);
        sleep(2);
    }

    return 0;
}