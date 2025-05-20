//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>

#define DESTINATION "www.google.com"
#define PACKET_SIZE 4096

double get_time();
int checksum(unsigned short *b, int len);
void display_result(struct hostent *h, struct sockaddr_in *sin);

int main()
{
    struct hostent *hp;
    struct sockaddr_in sin;
    int sock, on = 1;
    char *destination = DESTINATION;
    char packet[PACKET_SIZE];
    int packet_size = sizeof(struct icmphdr);

    if ((hp = gethostbyname(destination)) == NULL)
    {
        fprintf(stderr, "Unknown host %s.\n", destination);
        exit(1);
    }

    if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        perror("socket");
        exit(1);
    }

    if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) < 0)
    {
        perror("IPHDRINCL");
        exit(1);
    }

    sin.sin_family = AF_INET;
    sin.sin_addr = *(struct in_addr *)hp->h_addr;

    int seq = 0;
    struct icmphdr *icmp = (struct icmphdr *)packet;
    icmp->type = ICMP_ECHO;
    icmp->code = 0;
    icmp->checksum = 0;
    icmp->un.echo.id = getpid() & 0xFFFF;

    while (1)
    {
        seq++;
        icmp->un.echo.sequence = htons(seq);
        icmp->checksum = checksum((unsigned short *)packet, packet_size);
        
        double start_time = get_time();
        if (sendto(sock, packet, packet_size, 0, (struct sockaddr *)&sin, sizeof(sin)) <= 0)
        {
            perror("sendto");
            exit(1);
        }

        char buffer[PACKET_SIZE + 1];
        struct sockaddr_in from;
        int fromlen = sizeof(from);
        int read_bytes = recvfrom(sock, buffer, PACKET_SIZE, 0, (struct sockaddr *)&from, &fromlen);

        if (read_bytes <= 0)
        {
            fprintf(stderr, "No response from host\n");
        }
        else
        {
            double end_time = get_time();
            char *ip = inet_ntoa(from.sin_addr);
            int rtt = (int)((end_time - start_time) * 1000);
            printf("Response from IP: %s, RTT: %dms\n", ip, rtt);
        }

        sleep(1);
    }
}

double get_time()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (double)time.tv_sec + (double)time.tv_usec / 1000000.0;
}

int checksum(unsigned short *b, int len)
{
    unsigned long sum = 0;
    for (sum = 0; len > 1; len -= 2)
        sum += *b++;
    if (len == 1)
        sum += *(unsigned char *)b;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}