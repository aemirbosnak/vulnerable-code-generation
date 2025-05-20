//FormAI DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define DEFAULT_TIMEOUT 1000
#define MAX_PACKET_SIZE 4096

char *hostname;

unsigned short in_cksum(unsigned short *ptr, int nbytes)
{
    register long sum;
    u_short oddbyte;
    register u_short answer;

    sum = 0;
    while (nbytes > 1)
    {
        sum += *ptr++;
        nbytes -= 2;
    }

    if (nbytes == 1)
    {
        oddbyte = 0;
        *((u_char *)&oddbyte) = *(u_char *)ptr;
        sum += oddbyte;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = (u_short)~sum;

    return (answer);
};

void ping(int sock, struct sockaddr_in *pingaddr, unsigned char *packet, int packet_size, int timeout)
{
    struct timeval tv;
    fd_set readfds;
    int ret;
    socklen_t len = sizeof(struct sockaddr_in);

    sendto(sock, (char *)packet, packet_size, 0, (struct sockaddr *)pingaddr, sizeof(struct sockaddr));
    gettimeofday(&tv, NULL);
    tv.tv_usec += timeout * 1000;
    tv.tv_sec += tv.tv_usec / 1000000;
    tv.tv_usec %= 1000000;

    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);

    ret = select(sock + 1, &readfds, NULL, NULL, &tv);

    if (ret == -1)
    {
        perror("select()");
    }
    else if (ret)
    {
        unsigned char packet_recv[MAX_PACKET_SIZE];
        struct sockaddr_in recvaddr;
        int recvsize = sizeof(recvaddr);

        memset(packet_recv, 0, MAX_PACKET_SIZE);
        recvfrom(sock, packet_recv, MAX_PACKET_SIZE, 0, (struct sockaddr *)&recvaddr, &recvsize);
        printf("%s\ticmp_seq=%d\tttl=%d\n", inet_ntoa(recvaddr.sin_addr), packet_recv[20], packet_recv[8]);
    }
    else
    {
        printf("Request timed out.\n");
    }
}

int main(int argc, char *argv[])
{
    char *ip;
    int sock;
    struct hostent *host;
    struct sockaddr_in pingaddr;
    unsigned char packet[MAX_PACKET_SIZE];
    int packet_size;
    int timeout = DEFAULT_TIMEOUT;
    int ttl = 255;
    int i;
    
    if (argc < 2)
    {
        printf("Usage: %s <hostname/IP address> [timeout] [ttl]\n", argv[0]);
        exit(0);
    }

    hostname = argv[1];
    timeout = (argc > 2) ? atoi(argv[2]) : DEFAULT_TIMEOUT;
    ttl = (argc > 3) ? atoi(argv[3]) : ttl;

    if ((host = gethostbyname(hostname)) == NULL)
    {
        fprintf(stderr, "%s: unknown host\n", hostname);
        exit(1);
    }

    if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        perror("socket()");
        exit(1);
    }

    if (setsockopt(sock, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) != 0)
    {
        perror("setsockopt()");
        exit(1);
    }

    memset(&pingaddr, 0, sizeof(struct sockaddr_in));
    pingaddr.sin_family = AF_INET;
    pingaddr.sin_port = 0;
    memcpy(&pingaddr.sin_addr, host->h_addr_list[0], sizeof(pingaddr.sin_addr));

    packet_size = 64;
    memset(packet, 0, sizeof(packet));
    packet[0] = 8;
    packet[1] = 0;
    packet[2] = 0;
    packet[3] = 0;
    packet[4] = 0;
    packet[5] = 0;
    packet[6] = 0;
    packet[7] = 0;
    packet[8] = 0;
    packet[9] = 0;
    packet[10] = 0;
    packet[11] = 0;
    packet[12] = 0;
    packet[13] = 0;
    packet[14] = 0;
    packet[15] = 0;
    packet[16] = 0;
    packet[17] = 0;
    packet[18] = 0;
    packet[19] = 0;
    packet[20] = 1;
    packet[21] = 0;
    packet[22] = in_cksum((unsigned short *)packet, packet_size);
    packet[23] = in_cksum((unsigned short *)packet, packet_size) >> 8;

    for (i = 0; i < 4; i++)
    {
        ping(sock, &pingaddr, packet, packet_size, timeout);
        sleep(1);
    }

    close(sock);

    return 0;
}