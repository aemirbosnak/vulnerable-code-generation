//FormAI DATASET v1.0 Category: Network Ping Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>

#define IP_ADDR_MAX_LEN 15
#define PING_PKT_S 64

struct PingPacket {
    struct timeval tv_start;
    struct timeval tv_end;
};

char g_ipAddr[IP_ADDR_MAX_LEN] = {0};

int ping(struct sockaddr_in *pingAddress)
{
    struct PingPacket ping_packet;
    int ping_sockfd, flag_sent, msg_received, ret_val = -1, addr_len, i;
    struct sockaddr_in reply_addr;
    struct timeval tv_out = {5, 0};

    ping_packet.tv_start.tv_sec = ping_packet.tv_start.tv_usec = 0;
    ping_packet.tv_end.tv_sec = ping_packet.tv_end.tv_usec = 0;

    if ((ping_sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        fprintf(stderr, "Error: socket() %s\n", strerror(errno));
        return -1;
    }

    setsockopt(ping_sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv_out, sizeof(tv_out));

    flag_sent = 1;

    for (i = 0; i < PING_PKT_S; i++)
        ((char*)&ping_packet)[sizeof(struct timeval) + i] = i % 10 + '0';

    ping_packet.tv_start.tv_sec = time(NULL);

    if (sendto(ping_sockfd, &ping_packet, sizeof(ping_packet), 0, (struct sockaddr*) pingAddress, sizeof(*pingAddress)) <= 0) {
        fprintf(stderr, "Error: sendto() %s\n", strerror(errno));
        flag_sent = 0;
    }

    addr_len = sizeof(reply_addr);

    if ((msg_received = recvfrom(ping_sockfd, &ping_packet, sizeof(ping_packet), 0, (struct sockaddr*)&reply_addr, (socklen_t*)&addr_len)) <= 0) {
        fprintf(stderr, "Error: recvfrom() %s\n", strerror(errno));
    }
    else {
        ping_packet.tv_end.tv_sec = time(NULL);

        if (flag_sent) {
            printf("%s responded in %d ms\n", g_ipAddr, (int)(1000 * (ping_packet.tv_end.tv_sec - ping_packet.tv_start.tv_sec) + (ping_packet.tv_end.tv_usec - ping_packet.tv_start.tv_usec) / 1000));
        }

        ret_val = 0;
    }

    close(ping_sockfd);

    return ret_val;
}

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <IP>\n", argv[0]);
        return -1;
    }

    if (strlen(argv[1]) > IP_ADDR_MAX_LEN - 1) {
        printf("Error: IP address too long!\n");
        return -1;
    }

    strncpy(g_ipAddr, argv[1], IP_ADDR_MAX_LEN);

    struct hostent *host = (struct hostent*)gethostbyname(g_ipAddr);

    if (!host) {
        printf("Error: Unable to resolve the hostname!\n");
        return -1;
    }

    struct sockaddr_in pingAddress;
    memset(&pingAddress, 0, sizeof(pingAddress));
    pingAddress.sin_family = AF_INET;
    pingAddress.sin_addr.s_addr = *((unsigned long*)host->h_addr);

    printf("Testing connectivity to %s...\n", g_ipAddr);

    if (ping(&pingAddress) == 0) {
        printf("Ping test successful!\n");
    }
    else {
        printf("Ping test failed!\n");
    }

    return 0;
}