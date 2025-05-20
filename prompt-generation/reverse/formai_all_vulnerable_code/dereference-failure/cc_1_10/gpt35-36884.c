//FormAI DATASET v1.0 Category: Network Ping Test ; Style: imaginative
/*
 * This is a Network Ping Test program
 * 
 * It tests the network connectivity between two hosts using ICMP packets
 *
 * This program sends ICMP echo request packets to the target host 
 * and waits for a response from the host. If the response is received,
 * the program considers the network connectivity to be present.
 *
 * If the response is not received within a timeout period, the program 
 * considers the network connectivity to be lost.
 *
 * This program can be used to test the network connectivity between 
 * any two hosts on the network.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>
#include <errno.h>
#include <signal.h>

#define PACKET_SIZE     64      /* ICMP packet size in bytes */
#define MAX_PACKETS     3       /* Maximum number of ICMP packets to send */
#define TIMEOUT         5000    /* Timeout in milliseconds */

/* Structure of an ICMP header */
struct icmp_hdr
{
    uint8_t     icmp_type;      /* ICMP message type */
    uint8_t     icmp_code;      /* ICMP message code */
    uint16_t    icmp_checksum;  /* ICMP message checksum */
    uint32_t    icmp_id;        /* ICMP message ID */
    uint32_t    icmp_seqnum;    /* ICMP message sequence number */
};

/* Function to calculate the ICMP checksum */
uint16_t calculate_checksum(uint16_t *hdr, uint32_t len)
{
    uint32_t sum = 0;

    while (len > 1) 
    {
        sum += *hdr++;
        len -= 2;
    }

    if (len == 1)
        sum += *((uint8_t*) hdr);

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);

    return ~sum;
}

/* Function to handle the timeout signal */
void handle_timeout(int signo)
{
    printf("Timeout!\n");
}

/* Main function */
int main(int argc, char **argv)
{
    struct addrinfo hints, *res;
    char ipstr[INET_ADDRSTRLEN];
    uint32_t packet_num = 0;
    int sockfd, ret;
    struct icmp_hdr icmp;
    struct timeval timeout;
    fd_set read_fds, write_fds, except_fds;

    if (argc != 2) 
    {
        printf("Usage: %s <hostname>\n", argv[0]);
        return -1;
    }

    /* Get the IP address of the target host */
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME;

    if ((ret = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) 
    {
        printf("Error: Cannot resolve hostname %s (%s)\n", argv[1], gai_strerror(ret));
        return -1;
    }

    inet_ntop(AF_INET, &((struct sockaddr_in *) res->ai_addr)->sin_addr, ipstr, sizeof(ipstr));
    printf("Ping test between %s and %s...\n", argv[1], ipstr);

    /* Create the socket */
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        printf("Error: Cannot create socket\n");
        freeaddrinfo(res);
        return -1;
    }

    /* Set the timeout value for the socket */
    timeout.tv_sec = TIMEOUT / 1000;
    timeout.tv_usec = (TIMEOUT % 1000) * 1000;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0)
        printf("Error: Cannot set timeout on socket\n");

    /* Fill in the ICMP header */
    icmp.icmp_type = 8;     /* Echo request message type */
    icmp.icmp_code = 0;     /* Echo request message code */
    icmp.icmp_id = getpid() & 0xFFFF;   /* Set the ID field to the process ID */
    icmp.icmp_seqnum = 0;

    /* Start sending ICMP packets */
    while (packet_num < MAX_PACKETS) 
    {
        /* Fill in the sequence number field of the ICMP header */
        icmp.icmp_seqnum = packet_num + 1;

        /* Calculate the checksum of the ICMP header and payload */
        icmp.icmp_checksum = 0;
        icmp.icmp_checksum = calculate_checksum((uint16_t*)&icmp, PACKET_SIZE);

        /* Send the ICMP packet */
        if (sendto(sockfd, (void*)&icmp, PACKET_SIZE, 0, res->ai_addr, sizeof(struct sockaddr_in)) <= 0) 
        {
            printf("Error: Cannot send ICMP packet\n");
            close(sockfd);
            freeaddrinfo(res);
            return -1;
        }

        /* Wait for a response */
        FD_ZERO(&read_fds);
        FD_ZERO(&write_fds);
        FD_ZERO(&except_fds);
        FD_SET(sockfd, &read_fds);
        select(sockfd+1, &read_fds, &write_fds, &except_fds, &timeout);

        if (FD_ISSET(sockfd, &read_fds)) 
        {
            /* Response received */
            struct sockaddr_in from_addr;
            socklen_t from_len = sizeof(from_addr);

            uint8_t recv_buf[PACKET_SIZE];
            ssize_t recv_len = recvfrom(sockfd, recv_buf, PACKET_SIZE, 0, (struct sockaddr*)&from_addr, &from_len);

            if (recv_len < 0) 
            {
                printf("Error: Cannot receive ICMP response\n");
                close(sockfd);
                freeaddrinfo(res);
                return -1;
            }

            /* Check if the response is for our ICMP packet */
            struct icmp_hdr *recv_icmp = (struct icmp_hdr *)recv_buf;

            if (recv_icmp->icmp_id != icmp.icmp_id || recv_icmp->icmp_seqnum != icmp.icmp_seqnum) 
            {
                printf("Error: Received ICMP response is not for our ICMP packet\n");
                close(sockfd);
                freeaddrinfo(res);
                return -1;
            }

            printf("ICMP response received from %s\n", inet_ntoa(from_addr.sin_addr));
            packet_num++;
        } 
        else 
        {
            /* Timeout occurred */
            printf("Timeout!\n");
            packet_num++;
        }
    }

    printf("Ping test complete\n");

    /* Close the socket and free the address info structure */
    close(sockfd);
    freeaddrinfo(res);

    return 0;
}