//FormAI DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PACKET_SIZE 64
#define ICMP_HEADER_LEN 8

struct sockaddr_in address;

/* Function to display error message */
void error(const char *msg)
{
    perror(msg);
    exit(0);
}

/* Function to calculate checksum */
unsigned short calculate_checksum(unsigned short *buf, int length)
{
    unsigned int sum = 0;
    unsigned short odd_byte;
    while (length > 1) {
        sum += *buf++;
        length -= 2;
    }
    if (length == 1) {
        odd_byte = 0;
        *((unsigned char *)&odd_byte) = *(unsigned char *)buf;
        sum += odd_byte;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

/* Function to send ICMP Echo Request packet */
void send_packet(int sockfd, int sequence)
{
    char packet[PACKET_SIZE];
    bzero(packet, sizeof(packet));
    struct icmp *icmp_hdr = (struct icmp *) packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_hun.ih_idseq.icd_id = getpid();
    icmp_hdr->icmp_hun.ih_idseq.icd_seq = sequence;
    icmp_hdr->icmp_cksum = calculate_checksum((unsigned short *)icmp_hdr, ICMP_HEADER_LEN);
    if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&address, sizeof(address)) <= 0) {
        error("Error: Failed to send packet");
    }
}

/* Function to receive ICMP Echo Response packet */
int receive_packet(int sockfd, int sequence, int timeout)
{
    char packet[PACKET_SIZE];
    struct sockaddr_in src_address;
    socklen_t len = sizeof(src_address);
    
    struct timeval tv;
    tv.tv_sec = timeout;
    tv.tv_usec = 0;
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    int status = select(sockfd + 1, &readfds, NULL, NULL, &tv);
    if (status == -1) {
        error("Error: Select failed");
    } else if (status > 0) {
        recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&src_address, &len);
        struct iphdr *ip_hdr = (struct iphdr *) packet;
        if (ip_hdr->protocol == IPPROTO_ICMP) {
            struct icmp *icmp_hdr = (struct icmp *)(packet + (ip_hdr->ihl * 4));
            if (icmp_hdr->icmp_type == ICMP_ECHOREPLY && icmp_hdr->icmp_hun.ih_idseq.icd_id == getpid() && icmp_hdr->icmp_hun.ih_idseq.icd_seq == sequence) {
                return 1;
            }
        }
    }
    return 0;
}

/* Function to perform Ping Test */
void ping(int sockfd, char *dest_address, int count, int interval, int timeout, int sequence)
{
    int i, success_count = 0;
    printf("\nPing %s (%s):\n", dest_address, inet_ntoa(address.sin_addr));
    for (i = 1; i <= count; i++) {
        send_packet(sockfd, sequence + i);
        if (receive_packet(sockfd, sequence + i, timeout) == 1) {
            printf("Ping successful - Sequence Number %d\n", sequence + i);
            success_count++;
        } else {
            printf("Ping failed - Sequence Number %d\n", sequence + i);
        }
        if (i < count) {
            sleep(interval);
        }
    }
    printf("\nPing Test Complete. Summary:\n");
    printf("Packets Sent: %d | Packets Received: %d\n", count, success_count);
}

/* Main Function */
int main(int argc, char *argv[])
{
    int sockfd, sequence, count, interval, timeout;
    char dest_address[INET_ADDRSTRLEN];
    struct hostent *host;
    /* Check for Required Arguments */
    if (argc < 2) {
        error("Error: Destination Address is required");
    }
    strcpy(dest_address, argv[1]);
    /* Set Default Options */
    count = 4;
    interval = 1;
    timeout = 5;
    /* Parse Options */
    int opt;
    while ((opt = getopt(argc, argv, "c:i:t:")) != -1) {
        switch (opt) {
            case 'c':
                count = atoi(optarg);
                break;
            case 'i':
                interval = atoi(optarg);
                break;
            case 't':
                timeout = atoi(optarg);
                break;
            default:
                error("Error: Invalid Option");
        }
    }
    /* Create Socket */
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        error("Error: Failed to create socket");
    }
    /* Get Destination Address */
    host = gethostbyname(dest_address);
    if (host == NULL) {
        error("Error: Failed to get destination address");
    }
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&address.sin_addr.s_addr, host->h_length);
    /* Perform Ping Test */
    sequence = (int)time(NULL);
    ping(sockfd, dest_address, count, interval, timeout, sequence);
    /* Close Socket */
    close(sockfd);
    return 0;
}