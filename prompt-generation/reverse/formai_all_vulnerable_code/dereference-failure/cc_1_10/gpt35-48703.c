//FormAI DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define PACKET_SIZE 64
#define IP_ADDR_LEN 16
#define PING_WAIT 500000
#define TIMEOUT 2

struct packet {
    struct icmphdr header;
    char data[PACKET_SIZE - sizeof(struct icmphdr)];
};

int ping(char* target) {
    struct sockaddr_in addr;
    int sock, count, sent = 0, recv = 0, rcvlen, ttl = 255;
    char ip[IP_ADDR_LEN];
    struct hostent *host;
    struct packet pack;
    struct timeval tv_out;
    tv_out.tv_sec = TIMEOUT;
    tv_out.tv_usec = 0;
    
    inet_pton(AF_INET, target, &(addr.sin_addr));
    if ((host = gethostbyname(target)) != NULL) {
        strcpy(ip, (char*)inet_ntoa(*(struct in_addr*)host->h_addr_list[0]));
    } else {
        printf("Unknown host %s\n", target);
        return 0;
    }
    
    if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        printf("Socket failed\n");
        return 0;
    }
    
    if (setsockopt(sock, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) != 0) {
        printf("Setsockopt failed\n");
        close(sock);
        return 0;
    }
    
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv_out, sizeof(tv_out)) != 0) {
        printf("Setsockopt failed\n");
        close(sock);
        return 0;
    }
    
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    
    for (count = 0; count < 4; count++) {
        pack.header.type = ICMP_ECHO;
        pack.header.un.echo.id = getpid();
        if ((count + 1) * sizeof(pack.data) > PACKET_SIZE - sizeof(struct icmphdr))
            pack.header.un.echo.sequence = htons(PACKET_SIZE - sizeof(struct icmphdr));
        else
            pack.header.un.echo.sequence = htons((count + 1) * sizeof(pack.data));
        gettimeofday((struct timeval*)pack.data, NULL);
        if (sendto(sock, &pack, sizeof(pack), 0, (struct sockaddr*) &addr, sizeof(addr)) <= 0) {
            printf("Sendto failed\n");
            close(sock);
            return 0;
        }
        sent++;
        usleep(PING_WAIT);
        if (recvfrom(sock, &pack, sizeof(pack), 0, (struct sockaddr*) &addr, &rcvlen) > 0) {
            recv++;
            printf("Response from %s time=%.2fms\n", target, (double)(clock() / CLOCKS_PER_SEC) * 1000);
        } else {
            printf("Request to %s timed out\n", target);
        }
    }
    
    printf("Ping statistics for %s:\n", target);
    printf("    Packets: Sent = %d, Received = %d, Lost = %d (%d%% lost)\n", sent, recv, sent - recv, (sent - recv) * 100 / sent);
    
    close(sock);
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }
    ping(argv[1]);
    return 0;
}