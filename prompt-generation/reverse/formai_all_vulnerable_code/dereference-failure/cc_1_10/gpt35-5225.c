//FormAI DATASET v1.0 Category: Network Ping Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>

#define ICMP_ECHO_REQUEST 8
#define BUFFER_SIZE 1024

struct icmp_packet
{
    struct icmphdr header;
    char data[BUFFER_SIZE - sizeof(struct icmphdr)];
};

unsigned short calculate_checksum(unsigned short *addr, int len)
{
    // Internet Checksum algorithm
    register long sum = 0;
    while (len > 1)
    {
        sum += *addr++;
        len -= sizeof(unsigned short);
    }

    if (len == 1)
    {
        sum += *(unsigned char *)addr;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum = sum + (sum >> 16);
    return (unsigned short)(~sum);
}

int ping(char *target_host)
{
    int sockfd, status, packets_sent = 0, packets_received = 0;
    struct protoent *protocol;
    struct sockaddr_in target_addr, from_addr;
    socklen_t from_addr_len = sizeof(from_addr);
    char recv_buffer[BUFFER_SIZE], send_buffer[BUFFER_SIZE];

    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_host);

    // Get the protocol number for ICMP
    if ((protocol = getprotobyname("icmp")) == NULL)
    {
        perror("Error getting protocol number.");
        return -1;
    }

    // Create raw ICMP socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, protocol->p_proto)) < 0)
    {
        perror("Error creating raw socket.");
        return -1;
    }

    // Loop through and send ICMP echo requests, wait for replies
    for (int i = 1; i <= 10; i++)
    {
        // Prepare ICMP header and data
        struct icmp_packet icmp;
        icmp.header.type = ICMP_ECHO_REQUEST;
        icmp.header.code = 0;
        icmp.header.checksum = 0;
        icmp.header.un.echo.sequence = i;
        icmp.header.un.echo.id = getpid();

        // Fill the rest of the packet with random data
        for (int j = 0; j < sizeof(icmp.data); j++)
        {
            icmp.data[j] = rand() % 255;
        }

        // Calculate ICMP checksum
        icmp.header.checksum = calculate_checksum((unsigned short *)&icmp, sizeof(icmp));

        // Send ICMP echo request
        if ((status = sendto(sockfd, &icmp, sizeof(icmp), 0, (struct sockaddr *)&target_addr, sizeof(target_addr))) < 0)
        {
            perror("Error sending ICMP echo request.");
            close(sockfd);
            return -1;
        }

        packets_sent++;

        // Wait for ICMP echo reply
        if ((status = recvfrom(sockfd, &recv_buffer, sizeof(recv_buffer), 0, (struct sockaddr *)&from_addr, &from_addr_len)) < 0)
        {
            perror("Error receiving ICMP echo reply.");
            close(sockfd);
            return -1;
        }

        // Verify ICMP echo reply
        struct icmphdr *reply = (struct icmphdr *)recv_buffer;
        if (reply->type == ICMP_ECHOREPLY && reply->un.echo.id == getpid())
        {
            packets_received++;
            printf("Ping response from %s: icmp_seq=%d time=%.2f ms\n", target_host, reply->un.echo.sequence, (double)(clock()) / CLOCKS_PER_SEC * 1000);
        }

        // Sleep for 1 second between requests
        sleep(1);
    }

    // Display ping statistics
    printf("\n--- %s ping statistics ---\n", target_host);
    printf("%d packets transmitted, %d received, %d%% packet loss, time %.0fms\n", packets_sent, packets_received, (packets_sent - packets_received) * 100 / packets_sent, (double)(clock()) / CLOCKS_PER_SEC * 1000);

    close(sockfd);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <IP address>\n", argv[0]);
        return -1;
    }

    return ping(argv[1]);
}