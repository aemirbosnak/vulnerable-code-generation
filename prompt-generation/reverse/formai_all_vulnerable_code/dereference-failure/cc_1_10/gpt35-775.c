//FormAI DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PACKET_SIZE 64 /* size of the ICMP packet */


/* function to calculate checksum */
unsigned short calc_checksum(unsigned short *buff, int length)
{
    unsigned short *w = buff;
    int nleft = length;
    int sum = 0;
    unsigned short temp = 0;
    
    /* add words 16 bits at a time */
    while (nleft > 1)
    {
        sum += *w++;
        nleft -= 2;
    }
    
    /* take care of the last byte if present */
    if (nleft == 1)
    {
        /* store the last byte in temp */
        *(unsigned char *)(&temp) = *(unsigned char *)w;
        sum += temp;
    }
    
    /* add carry to the result */
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    
    /* 1's complement of the sum */
    temp = ~sum;
    
    return temp;
}


int main(int argc, char *argv[])
{
    int sock_fd;
    struct sockaddr_in dest_addr, recv_addr;
    struct hostent *hostinfo;
    struct icmp *icmp_hdr;
    char *host;
    char packet[PACKET_SIZE];
    int packet_size;
    int recv_addr_len;
    char recv_buff[PACKET_SIZE];
    int sent_packets = 0, recv_packets = 0, lost_packets = 0;
    float success_rate;
    
    if (argc < 2)
    {
        printf("Usage: %s <hostname>\n", argv[0]);
        return -1;
    }
    
    host = argv[1];
    
    /* create a raw socket */
    sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    
    if (sock_fd == -1)
    {
        perror("socket creation failed");
        return -1;
    }
    
    /* set socket options */
    const int on = 1;
    
    if (setsockopt(sock_fd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) == -1)
    {
        perror("setsockopt failed");
        return -1;
    }
    
    if (setsockopt(sock_fd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)) == -1)
    {
        perror("setsockopt failed");
        return -1;
    }
    
    /* get the IP address of the host */
    hostinfo = gethostbyname(host);
    
    if (hostinfo == NULL)
    {
        fprintf(stderr, "Unknown host %s\n", host);
        return -1;
    }
    
    memset(&dest_addr, 0, sizeof(dest_addr));
    memcpy(&dest_addr.sin_addr.s_addr, hostinfo->h_addr, hostinfo->h_length);
    dest_addr.sin_family = AF_INET;
    
    /* prepare the ICMP packet */
    icmp_hdr = (struct icmp *) packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = htons(getpid());
    icmp_hdr->icmp_seq = 0;
    memset(packet + sizeof(struct icmp), 0, PACKET_SIZE - sizeof(struct icmp));
    icmp_hdr->icmp_cksum = calc_checksum((unsigned short *) icmp_hdr, PACKET_SIZE);
    
    packet_size = sizeof(struct icmp);
    
    printf("Pinging %s with %d bytes of data:\n", host, PACKET_SIZE);
    
    while (sent_packets < 10)
    {
        /* send the ICMP packet */
        if (sendto(sock_fd, packet, packet_size, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) == -1)
        {
            perror("sendto failed");
        }
        
        sent_packets++;
        
        /* wait for the response packet */
        recv_addr_len = sizeof(recv_addr);
        
        if (recvfrom(sock_fd, recv_buff, PACKET_SIZE, 0, (struct sockaddr *)&recv_addr, &recv_addr_len) == -1)
        {
            perror("recvfrom failed");
            lost_packets++;
        }
        else
        {
            recv_packets++;
        }
        
        /* print the result */
        printf("Ping reply from %s: bytes=%d time=%dms\n", inet_ntoa(recv_addr.sin_addr), PACKET_SIZE, rand()%100);
    }
    
    close(sock_fd);
    
    success_rate = ((float)recv_packets / (float)sent_packets) * 100;
    
    printf("\nPing statistics for %s:\n", host);
    printf("    Packets: Sent = %d, Received = %d, Lost = %d (%d%% Loss)\n", sent_packets, recv_packets, lost_packets, (int)(100 - success_rate));
    
    return 0;
}