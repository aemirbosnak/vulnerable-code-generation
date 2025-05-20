//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PACKET_SIZE 4096
#define MAX_HOPS 30
#define MAX_ATTEMPTS 3
#define TIMEOUT 1000

/* Function for calculating checksum */
unsigned short calculate_checksum(const void *data, int length)
{
    // Cast the data as 16-bit blocks
    unsigned short *ptr = (unsigned short*) data;
    unsigned int sum = 0;
    
    for (int i = 0; i < length / 2; i++)
    {
        sum += ptr[i];
    }
    
    // If data length is odd, add the last byte as well
    if (length % 2)
    {
        sum += ((unsigned char*) data)[length - 1];
    }
    
    // Fold the 32 bit sum into 16 bits
    while (sum >> 16)
    {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }
    
    // Invert the checksum
    return ~sum;
}

/* Function for creating the IP header */
void create_ip_header(struct iphdr *iph, const char *target_ip)
{
    // Put the IP version in the first 4 bits of the header
    iph->version = 4;
    
    // Set the header length to 5, which means it's 20 bytes long
    iph->ihl = 5;
    
    // Set the type of service to 0
    iph->tos = 0;
    
    // Calculate the total length of the packet (IP header + ICMP header + Data)
    iph->tot_len = htons(sizeof(struct iphdr) + sizeof(struct icmphdr) + PACKET_SIZE);
    
    // Assign an ID for this packet (we can set it to any number)
    iph->id = htons(1337);
    
    // Set the fragmentation flags to 0
    iph->frag_off = 0;
    
    // Set the time-to-live (TTL) field to MAX_HOPS
    iph->ttl = MAX_HOPS;
    
    // Set the protocol to ICMP, which has a value of 1
    iph->protocol = IPPROTO_ICMP;
    
    // Set the source IP to 0.0.0.0 (we will later overwrite it with the real source IP)
    iph->saddr = inet_addr("0.0.0.0");
    
    // Set the destination IP
    iph->daddr = inet_addr(target_ip);
    
    // Calculate the checksum for the IP header
    iph->check = calculate_checksum(iph, sizeof(struct iphdr));
}

/* Function for creating the ICMP header */
void create_icmp_header(struct icmphdr *icmph)
{
    // Set the type to ICMP Echo Request (8)
    icmph->type = ICMP_ECHO;
    
    // Set the code to 0
    icmph->code = 0;
    
    // Set the identifier to 1234
    icmph->un.echo.id = htons(1234);
    
    // Set the sequence number to 0 (we will later increment it for each packet)
    icmph->un.echo.sequence = htons(0);
    
    // Calculate the checksum for the ICMP header (we will later overwrite it)
    icmph->checksum = 0;
}

/* Function for sending an ICMP packet to a given IP address */
int send_icmp_packet(const char *target_ip, int ttl, int seq_num, struct sockaddr_in *src_addr)
{
    // Create a new raw socket for sending ICMP packets
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    
    if (sockfd < 0)
    {
        perror("socket");
        return -1;
    }
    
    // Set the TTL option on the socket
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0)
    {
        perror("setsockopt");
        return -1;
    }
    
    // Set the source IP address on the socket
    if (src_addr && bind(sockfd, (struct sockaddr*) src_addr, sizeof(struct sockaddr_in)) < 0)
    {
        perror("bind");
        return -1;
    }
    
    char buffer[PACKET_SIZE];
    struct iphdr *iph = (struct iphdr*) buffer;
    struct icmphdr *icmph = (struct icmphdr*) (buffer + sizeof(struct iphdr));
    
    // Create the IP and ICMP headers
    create_ip_header(iph, target_ip);
    create_icmp_header(icmph);
    
    // Overwrite the sequence number in the ICMP header
    icmph->un.echo.sequence = htons(seq_num);
    
    // Calculate the checksum for the ICMP header
    icmph->checksum = calculate_checksum(icmph, sizeof(struct icmphdr));
    
    struct sockaddr_in dest;
    memset(&dest, 0, sizeof(dest));
    
    // Set the destination address for the packet
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(target_ip);
    
    // Send the packet to the destination
    int bytes_sent = sendto(sockfd, buffer, sizeof(struct iphdr) + sizeof(struct icmphdr) + PACKET_SIZE, 0, (struct sockaddr*) &dest, sizeof(dest));
    
    if (bytes_sent < 0)
    {
        perror("sendto");
        return -1;
    }
    
    return 0;
}

/* Function for receiving an ICMP packet */
int receive_icmp_packet(int sockfd, int ttl, struct sockaddr_in *src_addr, long *rtt)
{
    char buffer[BUFFER_SIZE];
    struct timeval start_time, end_time;
    socklen_t addrlen = sizeof(struct sockaddr_in);
    struct sockaddr_in src;
    memset(&src, 0, addrlen);
    
    // Start the timer
    gettimeofday(&start_time, NULL);
    
    // Receive the packet from the socket
    int bytes_recv = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*) &src, &addrlen);
    
    // End the timer
    gettimeofday(&end_time, NULL);
    
    // Calculate the round-trip time (RTT) in milliseconds
    *rtt = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;
    
    if (bytes_recv < 0)
    {
        perror("recvfrom");
        return -1;
    }
    
    struct iphdr *iph = (struct iphdr*) buffer;
    int iph_len = iph->ihl * 4;
    
    // If the TTL of the received packet is less than or equal to the TTL we set on the socket, it means the packet was generated by the target host.
    // In this case, we can extract the source IP address from the packet and return 1 to indicate the target host was reached.
    if (iph->ttl <= ttl)
    {
        *src_addr = src;
        return 1;
    }
    
    struct icmphdr *icmph = (struct icmphdr*) (buffer + iph_len);
    
    // If the received packet is an ICMP Time Exceeded message, it means the packet has reached a router on the way to the target host.
    // In this case, we can extract the source IP address from the packet and return 0 to indicate a successful hop.
    if (icmph->type == ICMP_TIME_EXCEEDED && icmph->code == ICMP_EXC_TTL)
    {
        *src_addr = src;
        return 0;
    }
    
    // If the received packet is an ICMP Echo Reply message, it means there was an error in our code because the target host should have sent us back an ICMP Echo Reply.
    // In this case, we can return -1 to indicate an error occurred.
    if (icmph->type == ICMP_ECHOREPLY && icmph->un.echo.id == htons(1234))
    {
        return -1;
    }
    
    // If we have reached this point, it means we received a packet that does not fit any of the above categories.
    // In this case, we can return -2 to indicate an unknown error occurred.
    return -2;
}

/* Function for mapping the network topology */
int map_network_topology(const char *target_ip)
{
    char ip_str[INET_ADDRSTRLEN];
    struct in_addr addr;
    inet_aton(target_ip, &addr);
    strcpy(ip_str, inet_ntoa(addr));
    
    struct sockaddr_in src_addr;
    memset(&src_addr, 0, sizeof(src_addr));
    
    // Create a new raw socket for sending and receiving ICMP packets
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    
    if (sockfd < 0)
    {
        perror("socket");
        return -1;
    }
    
    int attempts = 0, ttl = 1;
    long rtt[MAX_HOPS] = {0};
    char last_ip[INET_ADDRSTRLEN] = {0};
    
    printf("Tracing route to %s...\n\n", ip_str);
    printf(" Hop    IP Address       RTT (ms)\n");
    printf("----------------------------------\n");
    
    while (ttl <= MAX_HOPS && (attempts < MAX_ATTEMPTS || strcmp(last_ip, ip_str) != 0))
    {
        int success = 0;
        attempts = 0;
        rtt[ttl - 1] = 0;
        
        while (!success && attempts < MAX_ATTEMPTS)
        {
            // Send an ICMP packet to the target IP address with the current TTL
            if (send_icmp_packet(target_ip, ttl, ttl, &src_addr) < 0)
            {
                return -1;
            }
            
            struct sockaddr_in src;
            
            // Receive the ICMP packet and get the source IP address and RTT
            int result = receive_icmp_packet(sockfd, ttl, &src, &rtt[ttl - 1]);
            
            if (result == -1)
            {
                return -1;
            }
            else if (result == -2)
            {
                printf("Error: Unknown error occurred.\n");
                break;
            }
            else if (result == 1)
            {
                inet_ntop(AF_INET, &(src.sin_addr), last_ip, INET_ADDRSTRLEN);
                success = 1;
            }
            else
            {
                inet_ntop(AF_INET, &(src.sin_addr), last_ip, INET_ADDRSTRLEN);
                
                if (attempts == 0)
                {
                    printf("%3d    %s   %5s\n", ttl, last_ip, "*");
                }
                
                attempts++;
            }
        }
        
        // Print the results of this hop
        if (strcmp(last_ip, ip_str) != 0)
        {
            if (attempts == MAX_ATTEMPTS)
            {
                printf("%3d    %s   %5s\n", ttl, last_ip, "Request timed out");
            }
            else
            {
                printf("%3d    %s   %5ld\n", ttl, last_ip, rtt[ttl - 1]);
            }
        }
        
        ttl++;
    }
    
    printf("\nTrace completed.");
    
    return 0;
}

/* Main function */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <target-ip>\n", argv[0]);
        return -1;
    }
    
    if (map_network_topology(argv[1]) < 0)
    {
        printf("Error: An error has occurred.\n");
        return -1;
    }
    
    return 0;
}