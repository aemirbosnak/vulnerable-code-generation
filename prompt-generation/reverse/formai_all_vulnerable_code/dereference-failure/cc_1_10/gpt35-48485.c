//FormAI DATASET v1.0 Category: Network Ping Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define PACKET_SIZE   4096
#define PING_TIMEOUT  5000

int seq_no = 0; // Sequence number of packets

struct ping_packet
{
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

// Calculates the checksum for a given packet
unsigned short calc_checksum(void *buf, int bufsize)
{
    unsigned short *bytes = buf;
    unsigned int sum = 0;
    unsigned short result;

    for (; bufsize > 1; bufsize -= 2, bytes++)
    {
        sum += *bytes;
    }

    if (bufsize == 1)
    {
        sum += *((unsigned char *) bytes);
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    result = (unsigned short) ~sum;

    return result;
}

// Sends a ping packet to the specified host
void send_ping(int sockfd, struct sockaddr_in *addr)
{
    struct ping_packet packet;
    struct timeval tv;
    int i;

    seq_no++;

    // Fill the packet with data
    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    packet.hdr.un.echo.sequence = seq_no;
    gettimeofday(&tv, NULL);
    memcpy(packet.msg, &tv, sizeof(tv));
    packet.hdr.checksum = calc_checksum(&packet, sizeof(packet));

    // Send the packet
    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *) addr, sizeof(*addr)) <= 0)
    {
        perror("sendto");
    }
}

// Receives a ping packet from the specified host
int recv_ping(int sockfd, struct sockaddr_in *addr)
{
    struct ping_packet packet;
    fd_set readfds;
    struct timeval timeout;
    int ret;

    // Set up the file descriptor set and timeout
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    timeout.tv_sec = PING_TIMEOUT / 1000;
    timeout.tv_usec = (PING_TIMEOUT % 1000) * 1000;

    // Wait for a packet with a timeout
    ret = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
    if (ret <= 0)
    {
        // Timeout or error
        return 0;
    }

    // Receive the packet
    if (recvfrom(sockfd, &packet, sizeof(packet), 0, NULL, NULL) <= 0)
    {
        perror("recvfrom");
        return 0;
    }

    // Check the packet type and identifier
    if (packet.hdr.type != ICMP_ECHOREPLY || packet.hdr.un.echo.id != getpid())
    {
        return 0;
    }

    // Print the round-trip time for the packet
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long int rtt = (tv.tv_sec - ((struct timeval *)packet.msg)->tv_sec) * 1000L +
                  (tv.tv_usec - ((struct timeval *)packet.msg)->tv_usec) / 1000L;
    printf("Reply from %s: seq=%u time=%ld\n", inet_ntoa(addr->sin_addr), seq_no, rtt);

    return 1;
}

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in addr;
    struct hostent *host;
    char *ip;
    int ret;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Look up the host's IP address
    host = gethostbyname(argv[1]);
    if (!host)
    {
        fprintf(stderr, "Unknown host %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    ip = inet_ntoa(*(struct in_addr *) host->h_addr);

    // Create a socket for sending and receiving packets
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the destination address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);

    // Send and receive 4 ping packets to the host
    for (int i = 0; i < 4; i++)
    {
        send_ping(sockfd, &addr);
        ret = recv_ping(sockfd, &addr);
        if (!ret)
        {
            printf("Timeout for packet %d\n", seq_no);
        }

        // Wait for 1 second before sending the next packet
        sleep(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}