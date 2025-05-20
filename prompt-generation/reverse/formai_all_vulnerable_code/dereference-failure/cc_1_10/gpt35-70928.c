//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define PACKET_SIZE 64
#define MAX_HOPS 32
#define DEFAULT_TIMEOUT 5

struct packet
{
    struct icmphdr header;
    char data[PACKET_SIZE-sizeof(struct icmphdr)];
};

struct ping_result
{
    char* hostname;
    struct sockaddr_in addr;
    int success;
    int time;
    int ttl;
};

int send_packet(int fd, struct sockaddr_in* dest_addr, int ttl, int seq)
{
    struct packet packet;
    packet.header.type = ICMP_ECHO;
    packet.header.code = 0;
    packet.header.un.echo.id = getpid();
    packet.header.un.echo.sequence = seq;
    memset(packet.data, 'a', sizeof(packet.data));
    packet.header.checksum = 0;
    packet.header.checksum = htons(~htons(0)); // Compute checksum
    
    if (setsockopt(fd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) == -1)
    {
        perror("setsockopt");
        return -1;
    }
    
    ssize_t bytes_sent = sendto(fd, &packet, sizeof(packet), 0, (struct sockaddr*)dest_addr, sizeof(struct sockaddr_in));
    
    if (bytes_sent == -1)
    {
        perror("sendto");
        return -1;
    }
    
    return seq;
}

int receive_packet(int fd, int seq, struct ping_result* result)
{
    struct packet packet;
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(struct sockaddr_in);
    struct timeval timeout;
    timeout.tv_sec = DEFAULT_TIMEOUT;
    timeout.tv_usec = 0;
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);
    int select_res = select(fd+1, &readfds, NULL, NULL, &timeout);
    
    if (select_res == -1)
    {
        perror("select");
        return -1;
    }
    else if (select_res == 0)
    {
        return -1; // Timeout
    }
    
    ssize_t bytes_recv = recvfrom(fd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr, &addrlen);
    
    if (bytes_recv == -1)
    {
        perror("recvfrom");
        return -1;
    }
    
    if (packet.header.type == ICMP_ECHOREPLY && packet.header.un.echo.id == getpid() && packet.header.un.echo.sequence == seq)
    {
        result->success = 1;
        result->time = (int)((double)(timeout.tv_sec*1000)+(double)(timeout.tv_usec/1000));
        result->ttl = packet.header.un.echo.sequence;
        result->addr = addr;
        return 0;
    }
    else if (packet.header.type == ICMP_TIME_EXCEEDED)
    {
        struct iphdr* ip = (struct iphdr*)packet.data;
        struct icmphdr* icmp = (struct icmphdr*)(packet.data + (ip->ihl*4)); // Skip IP header
        if (icmp->un.echo.sequence == seq)
        {
            result->success = 0;
            result->addr = addr;
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}

int ping(char* hostname)
{
    int fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    
    if (fd == -1)
    {
        perror("socket");
        return -1;
    }
    
    struct hostent* host = gethostbyname(hostname);
    
    if (host == NULL)
    {
        herror("gethostbyname");
        return -1;
    }
    
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = 0;
    memcpy(&dest_addr.sin_addr, host->h_addr, host->h_length);
    
    int seq = 1;
    int ttl;
    struct ping_result result;
    result.hostname = hostname;
    
    printf("Pinging %s [%s]:\n", hostname, inet_ntoa(dest_addr.sin_addr));
    
    for (ttl = 1; ttl <= MAX_HOPS; ttl++)
    {
        int i;
        printf("%2d ", ttl);
        
        for (i = 0; i < 3; i++)
        {
            send_packet(fd, &dest_addr, ttl, seq);
            int recv_res = receive_packet(fd, seq, &result);
            seq++;
            
            if (recv_res == -1)
            {
                printf(" *  ");
            }
            else
            {
                printf("%3d ", result.time);
            }
        }
        
        printf("ms   %s\n", inet_ntoa(result.addr.sin_addr));
        
        if (result.success)
        {
            break;
        }
    }
    
    close(fd);
    
    if (result.success)
    {
        printf("Ping succeeded after %d hops.\n", ttl);
    }
    else
    {
        printf("Ping failed after %d hops :(\n", MAX_HOPS);
    }
    
    return 0;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }
    
    ping(argv[1]);
    return 0;
}