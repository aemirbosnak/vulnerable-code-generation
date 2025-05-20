//FormAI DATASET v1.0 Category: Network Ping Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define ICMP_ECHO_REQ      8   // ICMP echo request code
#define ICMP_PACKET_SIZE   64  // Size of ICMP packet in bytes
#define MAX_TIMEOUTS       3   // Maximum number of timeouts
#define MAX_PACKETS        10  // Maximum number of packets to send

// Function to calculate checksum
unsigned short calculate_checksum(unsigned short *ptr, int nbytes) {
    unsigned long sum;

    for (sum=0; nbytes>0; nbytes--)
        sum += *ptr++;

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);

    return ~sum;
}

// Function to receive ICMP echo replies
int receive_packet(int sockfd, struct sockaddr_in *addr) {
    char recvbuf[256] = {0};
    socklen_t addrlen = sizeof(struct sockaddr_in);
    struct timeval tv;
    fd_set readfds;

    tv.tv_sec = 1;
    tv.tv_usec = 0;

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    int ready = select(sockfd+1, &readfds, NULL, NULL, &tv);

    if (ready < 0)
    {
        perror("select");
        return -1;
    }
    else if (ready == 0)
    {
        return 0;
    }
    else
    {
        int nbytes = recvfrom(sockfd, recvbuf, sizeof(recvbuf), 0, (struct sockaddr*)addr, &addrlen);
        if (nbytes < 0)
        {
            perror("recvfrom");
            return -1;
        }

        struct icmphdr *icmp_hdr = (struct icmphdr*)recvbuf;

        if (icmp_hdr->type == ICMP_ECHOREPLY)
            return 1;

        return 0;
    }

}

int main(){
    struct sockaddr_in addr;
    struct hostent *host;
    char *hostname = "www.example.com"; // enter the hostname or ip address here
    int sockfd;
    int packet_count = 0;
    int timeout_count = 0;

    if ((host = gethostbyname(hostname)) == NULL)
    {
        perror("gethostbyname");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr*)host->h_addr);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd < 0)
    {
        perror("socket");
        return -1;
    }

    printf("Ping Test: %s\n\n", hostname);

    while (packet_count < MAX_PACKETS)
    {
        struct icmphdr icmp_hdr;

        memset(&icmp_hdr, 0, sizeof(icmp_hdr));
        icmp_hdr.type = ICMP_ECHO_REQ;
        icmp_hdr.code = 0;
        icmp_hdr.checksum = calculate_checksum((unsigned short*)&icmp_hdr, sizeof(icmp_hdr));

        if (sendto(sockfd, &icmp_hdr, sizeof(icmp_hdr), 0, (struct sockaddr*)&addr, sizeof(addr)) < 0)
        {
            perror("sendto");
            return -1;
        }

        printf("Sent ICMP packet %d to %s\n", packet_count+1, hostname);

        int received_packet = receive_packet(sockfd, &addr);

        if (received_packet == -1) // error occurred
        {
            printf("Error occurred while receiving packet %d\n", packet_count+1);
            break;
        }
        else if (received_packet == 0) // timeout occurred
        {
            printf("Timeout occurred while receiving packet %d\n", packet_count+1);
            timeout_count++;

            if (timeout_count == MAX_TIMEOUTS)
                break;
        }
        else // received packet successfully
        {
            printf("Received ICMP packet %d from %s\n", packet_count+1, hostname);
        }

        packet_count++;
        sleep(1);
    }

    if (packet_count == 0)
        printf("No packets were sent.\n");
    else
        printf("\nSummary:\n Packets sent: %d\n Packets received: %d\n Packets lost: %d\n", 
                packet_count, packet_count-timeout_count, timeout_count);

    close(sockfd);

    return 0;
}