//FormAI DATASET v1.0 Category: Network Ping Test ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define PACKET_SIZE 4096
#define MAX_WAIT_TIME 5
#define MAX_NO_PACKETS 3

int sockfd;
pid_t pid;
char sendpacket[PACKET_SIZE];
char recvpacket[PACKET_SIZE];
int packetsize = 56;

struct sockaddr_in dest_addr;
struct sockaddr_in from;

int nsend = 0, nreceived = 0;
double totaltime = 0;
double maxtime = 0, mintime = 1000;

void statistics()
{
    printf("\n-------PING Statistics-------\n");
    printf("%d packets transmitted, %d received, %.2f%% packet loss\n",
          nsend, nreceived, (nsend - nreceived) * 100.0 / nsend);
    if (nreceived > 0)
    {
        printf("round-trip min/avg/max/mdev = %.2f/%.2f/%.2f/%.2f ms\n",
              mintime, totaltime / nreceived, maxtime, sqrt(totaltime * totaltime / nreceived - (totaltime / nreceived) * (totaltime / nreceived)));
    }
}

unsigned short cal_chksum(unsigned short *addr, int len)
{
    int nleft = len;
    int sum = 0;
    unsigned short *w = addr;
    unsigned short answer = 0;

    while (nleft > 1)
    {
        sum += *w++;
        nleft -= 2;
    }

    if (nleft == 1)
    {
        *(unsigned char *)(&answer) = *(unsigned char *)w;
        sum += answer;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = ~sum;
    return answer;
}

void send_packet()
{
    nsend++;
    struct icmp *icmp = (struct icmp *)sendpacket;
    icmp->icmp_type = ICMP_ECHO;
    icmp->icmp_code = 0;
    icmp->icmp_cksum = 0;
    icmp->icmp_id = pid;
    icmp->icmp_seq = nsend;
    memset(icmp->icmp_data, nsend, packetsize);

    struct timeval tv;
    gettimeofday(&tv, NULL);
    icmp->icmp_cksum = cal_chksum((unsigned short *)icmp, packetsize);

    int res = sendto(sockfd, sendpacket, packetsize, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (res < 0)
    {
        perror("sendto error");
        return;
    }
}

void recv_packet()
{
    struct timeval tv;
    tv.tv_sec = MAX_WAIT_TIME;
    tv.tv_usec = 0;
    fd_set readfd;
    FD_ZERO(&readfd);
    FD_SET(sockfd, &readfd);

    int n;
    socklen_t from_len = sizeof(from);
    n = select(sockfd + 1, &readfd, NULL, NULL, &tv);
    if (n == -1)
    {
        perror("select error");
        return;
    }
    else if (n == 0)
    {
        printf("Timeout\n");
        return;
    }

    int res = recvfrom(sockfd, recvpacket, sizeof(recvpacket), 0, (struct sockaddr *)&from, &from_len);
    if (res < 0)
    {
        perror("recvfrom error");
        return;
    }

    nreceived++;
    struct iphdr *iphdr = (struct iphdr *)recvpacket;
    struct icmp *icmp = (struct icmp *)(recvpacket + (iphdr->ihl << 2));
    struct timeval endtv;
    gettimeofday(&endtv, NULL);
    double rtt = (double)(endtv.tv_sec - ((struct timeval *)icmp->icmp_data)->tv_sec) * 1000.0 + (double)(endtv.tv_usec - ((struct timeval *)icmp->icmp_data)->tv_usec) / 1000.0;
    totaltime += rtt;
    if (rtt > maxtime)
        maxtime = rtt;
    if (rtt < mintime)
        mintime = rtt;

    printf("%d bytes from %s: icmp_seq=%u ttl=%d time=%.2f ms\n", packetsize, inet_ntoa(from.sin_addr), icmp->icmp_seq, iphdr->ttl, rtt);
}

void handler(int signo)
{
    if (signo == SIGALRM)
    {
        send_packet();
        alarm(1);
    }
    else if (signo == SIGINT)
    {
        printf("\n-------PING INTERRUPTED BY USER-------\n");
        statistics();
        close(sockfd);
        exit(0);
    }
}

void set_addr(char *str)
{
    struct hostent *host;

    if ((dest_addr.sin_addr.s_addr = inet_addr(str)) == INADDR_NONE)
    {
        if ((host = gethostbyname(str)) == NULL)
        {
            perror("gethostbyname error");
            exit(1);
        }

        memcpy((char *)&dest_addr.sin_addr, host->h_addr, host->h_length);
    }

    dest_addr.sin_family = AF_INET;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <hostname/IP address>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        perror("socket error");
        exit(1);
    }

    int size = 60 * 1024;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &size, sizeof(size));

    pid = getpid();

    memset(&dest_addr, 0, sizeof(dest_addr));
    set_addr(argv[1]);

    signal(SIGALRM, handler);
    signal(SIGINT, handler);

    printf("PING %s (%s) %d bytes of data.\n", argv[1], inet_ntoa(dest_addr.sin_addr), packetsize);

    alarm(1);

    while (1)
    {
        recv_packet();
    }

    return 0;
}