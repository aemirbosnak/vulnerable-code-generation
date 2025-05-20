//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64

// Function to compute checksum for ICMP packets
unsigned short checksum(unsigned short *b, int len) 
{
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;

    if (len == 1)
        sum += *(unsigned char*)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

int main(int argc, char *argv[]) 
{
    struct timeval start_time, end_time;
    struct hostent *host;
    struct sockaddr_in server_addr;
    int sockfd, count = 1, packets_sent = 0, packets_received = 0, ttl_val = 64;
    char *ip;
    char packet[PACKET_SIZE];
    struct icmp *icmp_hdr;
    int failed_attempts = 0;
    int max_tries = 3; // Maximum number of retries
    double time_taken;
    unsigned char retries;

    if (argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];

    if ((host = gethostbyname(ip)) == NULL) {
        perror("Error in gethostbyname");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char*)host->h_addr, (char*)&server_addr.sin_addr.s_addr, host->h_length);
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd < 0) {
        perror("Error in creating socket");
        exit(1);
    }

    icmp_hdr = (struct icmp*) packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = htons(getpid());
    icmp_hdr->icmp_seq = htons(count);
    memset(&(icmp_hdr->icmp_data), 0, sizeof(icmp_hdr->icmp_data));
    gettimeofday(&start_time, NULL);
    icmp_hdr->icmp_cksum = checksum((unsigned short*)icmp_hdr, sizeof(struct icmp));
    retries = max_tries;

    while (retries > 0) 
    {
        packets_sent++;
        if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr*) &server_addr, (socklen_t) sizeof(server_addr)) < 0) 
        {
            perror("Error in sending packet");
            failed_attempts++;
        }
        else
        {
            memset(packet, 0, sizeof(packet));
            if (recv(sockfd, packet, sizeof(packet), 0) > 0) 
            {
                gettimeofday(&end_time, NULL);
                time_taken = (double) (end_time.tv_sec - start_time.tv_sec) * 1000 + (double) (end_time.tv_usec - start_time.tv_usec) / 1000;
                printf("%d bytes from %s: time=%.2fms ttl=%d\n", PACKET_SIZE, ip, time_taken, ttl_val);
                packets_received++;
            }
            else 
            {
                printf("Request timed out.\n");
                failed_attempts++;
            }
            retries--;
        }
    }
    if (failed_attempts == max_tries) 
    {
        printf("Max retries exceeded. Could not connect to server. \n");
        close(sockfd);
        exit(1);
    }
    printf("Ping statistics for %s:\n Packets: Sent = %d, Received = %d, Lost = %d\nApproximate time in milliseconds:\n Minimum = %.2fms, Maximum = %.2fms, Average = %.2fms\n", ip, packets_sent, packets_received, failed_attempts, time_taken, time_taken, time_taken);

    close(sockfd);

    return 0;
}