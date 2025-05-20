//FormAI DATASET v1.0 Category: Firewall ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define IP_HDR_SIZE 20
#define TCP_HDR_SIZE 20

// Structure of an IP packet
typedef struct ip_header
{
    unsigned char	iph_ihl:5, iph_ver:4;
    unsigned char	 iph_tos;
    unsigned short int iph_len;
    unsigned short int iph_ident;
    unsigned char	 iph_flag;
    unsigned short int iph_offset;
    unsigned char	 iph_ttl;
    unsigned char	 iph_protocol;
    unsigned short int iph_chksum;
    struct sockaddr_in srcAddr;
    struct sockaddr_in dstAddr;
} ip_header_t;

// Structure of a TCP packet
typedef struct tcp_header
{
    unsigned short int tcph_srcport;
    unsigned short int tcph_dstport;
    unsigned int	   tcph_seqnum;
    unsigned int	   tcph_acknum;
    unsigned char	   tcph_res1:4, tcph_len:4;
    unsigned char	   tcph_flags;
    unsigned short int tcph_win;
    unsigned short int tcph_chksum;
    unsigned short int tcph_urgptr;
} tcp_header_t;

int main()
{
    // Create a raw socket to receive all IP datagrams
    int socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (socket_fd == -1)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Define IP and TCP header variables
    ip_header_t *ip_hdr = NULL;
    tcp_header_t *tcp_hdr = NULL;
    char *data = NULL;
    int datagram_len = 0;

    while(1)
    {
        // Allocate memory for IP header and receive it
        ip_hdr = (ip_header_t*) malloc(IP_HDR_SIZE);
        int n = recv(socket_fd, ip_hdr, IP_HDR_SIZE, 0);
        if (n == -1)
        {
            perror("Error receiving packet");
            continue;
        }

        if (ip_hdr->iph_protocol == IPPROTO_TCP)
        {
            // Allocate memory for TCP header and receive it
            tcp_hdr = (tcp_header_t*) malloc(TCP_HDR_SIZE);
            n = recv(socket_fd, tcp_hdr, TCP_HDR_SIZE, 0);
            if (n == -1)
            {
                perror("Error receiving packet");
                continue;
            }

            // Calculate data length and allocate memory for data
            datagram_len = ntohs(ip_hdr->iph_len) - (IP_HDR_SIZE + TCP_HDR_SIZE);
            data = (char*) malloc(datagram_len);

            // Receive data
            n = recv(socket_fd, data, datagram_len, 0);
            if (n == -1)
            {
                perror("Error receiving packet");
                continue;
            }

            // Check if packet should be blocked
            if (ip_hdr->srcAddr.sin_addr.s_addr == inet_addr("10.0.0.1") || tcp_hdr->tcph_dstport == htons(80))
            {
                printf("Packet blocked\n");
                continue;
            }

            // Print packet information
            printf("Packet received from %s:%d to %s:%d\n", inet_ntoa(ip_hdr->srcAddr.sin_addr), ntohs(tcp_hdr->tcph_srcport), inet_ntoa(ip_hdr->dstAddr.sin_addr), ntohs(tcp_hdr->tcph_dstport));
            printf("Data: %s\n\n", data);
        }
    }

    // Free memory and close socket
    free(ip_hdr);
    free(tcp_hdr);
    free(data);
    close(socket_fd);

    return 0;
}