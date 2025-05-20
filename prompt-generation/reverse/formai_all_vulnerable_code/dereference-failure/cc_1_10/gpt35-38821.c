//FormAI DATASET v1.0 Category: Network Ping Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>

#define PACKET_SIZE 64
#define PORT_NO 0
#define MAX_HOPS 64

struct icmp_packet
{
    struct icmphdr header;
    char payload[PACKET_SIZE - sizeof(struct icmphdr)];
};

unsigned short in_cksum(unsigned short *ptr, int size)
{
    unsigned long chksum = 0;

    while(size > 1)
    {
        chksum += *ptr++;
        size -= sizeof(unsigned short);
    }

    if(size)
    {
        chksum += *(unsigned char*)ptr;
    }

    chksum = (chksum >> 16) + (chksum & 0xFFFF);
    chksum = ~(chksum + (chksum >> 16));

    return (unsigned short)chksum;
}

void display_usage(char* argv[])
{
    printf("Usage: %s [-c count] [-h max_hops] [--timeout timeout_ms] hostname/IP\n", argv[0]);
    printf("Optional parameters:\n");
    printf("\t-c\tThe number of packets to send (default: unlimited)\n");
    printf("\t-h\tThe maximum number of hops (default: 64)\n");
    printf("\t--timeout\tThe timeout for each packet in milliseconds (default: 1000)\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    int c = -1, h = MAX_HOPS, timeout_ms = 1000, sockfd;
    struct hostent *host;
    struct sockaddr_in dest_addr;
    char send_buf[PACKET_SIZE], recv_buf[PACKET_SIZE];
    long double rtt[MAX_HOPS][3];
    struct icmp_packet* icmp_packet = (struct icmp_packet*)send_buf;
    struct timeval start, end, timeout;
    struct timeval* tv;

    //check if hostname/ip is provided
    if(argc < 2)
    {
        printf("Hostname/IP not provided!\n");
        display_usage(argv);
    }

    //parse parameters
    int i;
    for(i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "-c") == 0)
        {
            if(i == argc - 1) display_usage(argv);
            c = atoi(argv[++i]);
        }
        else if(strcmp(argv[i], "-h") == 0)
        {
            if(i == argc - 1) display_usage(argv);
            h = atoi(argv[++i]);
        }
        else if(strcmp(argv[i], "--timeout") == 0)
        {
            if(i == argc - 1) display_usage(argv);
            timeout_ms = atoi(argv[++i]);
        }
        else
        {
            host = gethostbyname(argv[i]);
            if(!host)
            {
                printf("Invalid hostname/IP!\n");
                display_usage(argv);
            }
            break;
        }
    }

    //set up destination address and socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(PORT_NO);
    memcpy(&dest_addr.sin_addr, host->h_addr_list[0], host->h_length);

    //set up timeout for recvfrom() function
    timeout.tv_sec = timeout_ms / 1000;
    timeout.tv_usec = (timeout_ms % 1000) * 1000;

    //print details of the ping test
    printf("PING %s (%s) - %d bytes of data.\n", argv[i], inet_ntoa(dest_addr.sin_addr), PACKET_SIZE);

    //start iterating over hops
    int ttl;
    for(ttl = 1; ttl <= h; ttl++)
    {
        //set up time-to-live option
        printf("%-2d  ", ttl);
        setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int));

        //send packets
        int packet_sent = 0, packet_received = 0;
        memset(rtt[ttl - 1], -1, sizeof(rtt[0]));
        for(i = 0; c == -1 || i < c; i++)
        {
            //populate icmp packet
            memset(send_buf, 0, PACKET_SIZE);
            icmp_packet->header.type = ICMP_ECHO;
            icmp_packet->header.code = 0;
            icmp_packet->header.un.echo.id = getpid() & 0xFFFF;
            icmp_packet->header.un.echo.sequence = i+1;
            memset(&icmp_packet->payload, rand() % 26 + 65, PACKET_SIZE - sizeof(struct icmphdr));
            icmp_packet->header.checksum = in_cksum((unsigned short*)icmp_packet, PACKET_SIZE);

            //send packet
            gettimeofday(&start, NULL);
            if(sendto(sockfd, send_buf, PACKET_SIZE, 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr)) == -1)
            {
                perror("sendto");
                exit(EXIT_FAILURE);
            }
            packet_sent++;

            //receive response
            socklen_t addrlen = sizeof(dest_addr);
            if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0)
            {
                perror("setsockopt");
                exit(EXIT_FAILURE);
            }
            while(1)
            {
                memset(recv_buf, 0, PACKET_SIZE);
                if(recvfrom(sockfd, recv_buf, PACKET_SIZE, 0, (struct sockaddr*)&dest_addr, &addrlen) == -1)
                {
                    printf("* ");
                    fflush(stdout);
                    break;
                }

                struct iphdr* iphdr = (struct iphdr*)recv_buf;
                struct icmphdr* icmphdr = (struct icmphdr*)(recv_buf + iphdr->ihl*4);
                if(icmphdr->type == ICMP_ECHOREPLY)
                {
                    gettimeofday(&end, NULL);
                    rtt[ttl - 1][i] = (long double)(end.tv_sec + end.tv_usec/1000000.0 - start.tv_sec - start.tv_usec/1000000.0);
                    printf("%.3Lf ms  ", rtt[ttl - 1][i]*1000);
                    fflush(stdout);
                    packet_received++;
                    break;
                }
                else if(icmphdr->type == ICMP_TIME_EXCEEDED)
                {
                    printf("* ");
                    fflush(stdout);
                    break;
                }
            }
            if(packet_received == packet_sent) break;
        }
        printf("\n");

        //print summary
        if(c != -1 && packet_received == c) break;
        else if(packet_received == 0)
        {
            printf("Request timed out.\n");
            continue;
        }
        else if(packet_received < packet_sent)
        {
            printf("Ping test incomplete (received = %d, sent = %d).\n", packet_received, packet_sent);
        }
        printf("rtt min/avg/max = %.3Lf/%.3Lf/%.3Lf ms\n", rtt[ttl - 1][0]*1000, (packet_received > 1 ? ((long double)packet_received / packet_sent) * rtt[ttl - 1][packet_received - 1] * 1000 : rtt[ttl - 1][0]*1000), rtt[ttl - 1][packet_received - 1]*1000);

        if(dest_addr.sin_addr.s_addr == inet_addr(inet_ntoa(dest_addr.sin_addr))) break;
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}