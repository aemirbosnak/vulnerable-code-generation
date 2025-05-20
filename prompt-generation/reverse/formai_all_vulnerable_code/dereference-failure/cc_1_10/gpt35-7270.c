//FormAI DATASET v1.0 Category: Network Ping Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define PACKETSIZE 64
#define MAXPACKETS 100
#define HEADER_SIZE 8

// Structure for storing the ping statistics
typedef struct statistics
{
    int packetsSent;
    int packetsReceived;
    float minTime;
    float maxTime;
    float avgTime;
} statistics;

// Function for calculating the time difference in microseconds
double timevaldiff(struct timeval *tv1, struct timeval *tv2)
{
    return ((double) (tv2->tv_sec - tv1->tv_sec)) * 1000.0 + ((double) (tv2->tv_usec - tv1->tv_usec)) / 1000.0;
}

// Function for creating an ICMP packet
void createPacket(char *packet, int sequence)
{
    struct icmp *icmp = (struct icmp*) packet;
    icmp->icmp_type = ICMP_ECHO;
    icmp->icmp_code = 0;
    icmp->icmp_seq = sequence;
    icmp->icmp_id = getpid();
    gettimeofday((struct timeval*) icmp->icmp_data, NULL);
}

// Function for sending the ICMP packet
int sendPacket(int sockfd, struct sockaddr *addr, char *packet, int packetSize)
{
    if (sendto(sockfd, packet, packetSize, 0, addr, sizeof(*addr)) == -1)
    {
        fprintf(stderr, "Error sending packet\n");
        return -1;
    }

    return 0;
}

// Function for receiving the ICMP packet
int receivePacket(int sockfd, struct sockaddr *addr, char *packet, int packetSize, statistics *stats)
{
    char buffer[PACKETSIZE];
    struct timeval startTime, endTime;
    int recvBytes = 0;

    // Set timeout value to 1 second
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0)
    {
        fprintf(stderr, "Error setting socket option\n");
        return -1;
    }

    if ((recvBytes = recvfrom(sockfd, buffer, PACKETSIZE, 0, addr, (socklen_t*) sizeof(*addr))) <= 0)
    {
        fprintf(stderr, "Error receiving packet\n");
        return -1;
    }

    // Get the end time of the ping response
    gettimeofday(&endTime, NULL);

    // Calculate the ping response time
    double timeElapsed = timevaldiff((struct timeval*) packet + HEADER_SIZE, &endTime);

    // Update the statistics
    stats->packetsReceived++;
    stats->minTime = (timeElapsed < stats->minTime || stats->minTime == 0) ? timeElapsed : stats->minTime;
    stats->maxTime = (timeElapsed > stats->maxTime || stats->maxTime == 0) ? timeElapsed : stats->maxTime;
    stats->avgTime = ((stats->avgTime * (stats->packetsReceived - 1)) + timeElapsed) / stats->packetsReceived;

    return 0;
}

// Function for performing the ping test
statistics ping(char *address, int count)
{
    struct hostent *host;
    struct sockaddr_in addr;
    char packet[PACKETSIZE];
    int sockfd, i;
    statistics stats = {0, 0, 0, 0, 0};

    // Resolve the hostname into an IP address
    if ((host = gethostbyname(address)) == NULL)
    {
        fprintf(stderr, "Error resolving hostname\n");
        return stats;
    }

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        fprintf(stderr, "Error creating socket\n");
        return stats;
    }

    // Set the socket options
    int ttl = 64;
    setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));

    // Set the destination address
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Iterate over the packets and send/receive them
    for (i = 0; i < count; i++)
    {
        // Create the ICMP packet
        createPacket(packet, i);

        // Send the ICMP packet
        if (sendPacket(sockfd, (struct sockaddr*) &addr, packet, PACKETSIZE) == -1)
        {
            continue; // Move on to the next packet
        }

        // Receive the ICMP packet
        if (receivePacket(sockfd, (struct sockaddr*) &addr, packet, PACKETSIZE, &stats) == -1)
        {
            continue; // Move on to the next packet
        }

        // Increment the packets sent count
        stats.packetsSent++;
    }

    // Close the socket
    close(sockfd);

    return stats;
}

// Driver program
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <hostname/IP address> <packet count>\n", argv[0]);
        exit(1);
    }

    // Parse the packet count argument
    int count = atoi(argv[2]);
    if (count <= 0 || count > MAXPACKETS)
    {
        fprintf(stderr, "Invalid packet count\n");
        exit(1);
    }

    // Perform the ping test
    statistics stats = ping(argv[1], count);

    // Print the ping statistics
    printf("Ping Statistics:\n");
    printf("\tPackets sent: %d\n", stats.packetsSent);
    printf("\tPackets received: %d\n", stats.packetsReceived);
    printf("\tMinimum time: %.2f ms\n", stats.minTime);
    printf("\tMaximum time: %.2f ms\n", stats.maxTime);
    printf("\tAverage time: %.2f ms\n", stats.avgTime);

    return 0;
}