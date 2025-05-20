//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>

#define MAX_HOPS 30 // Maximum number of hops for a traceroute
#define PORT_NO 33434 // Port number for traceroute

int main(int argc, char *argv[]) {

    struct sockaddr_in addr;
    struct timeval tv;
    struct hostent *host;
    int sockfd, ttl, num_hops, max_hops, timeout, recv_sockfd;
    char ip[INET_ADDRSTRLEN];
    char recv_buf[512];
    char send_buf[512];
    char *dest_addr;
    ssize_t bytes_received;

    if(argc != 2){
        printf("[ERROR] Usage: %s <dest-address>\n", argv[0]);
        return 1;
    }

    dest_addr = argv[1]; // Extract the destination IP address from the command line arguments
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, dest_addr, &addr.sin_addr);

    if((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
        printf("[ERROR] Failed to create socket. Error code: %d\n", errno);
        return 1;
    }

    max_hops = MAX_HOPS;
    ttl = 1;
    printf("Hops\tIP Address\t\tRTT\n");
    while(ttl <= max_hops){
        setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int));
        tv.tv_sec = 5;
        tv.tv_usec = 0;

        if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(struct timeval)) == -1){
            printf("[ERROR] Failed to set socket option \"SO_RCVTIMEO\". Error code: %d\n", errno);
            return 1;
        }

        sprintf(send_buf, "PING");
        if(sendto(sockfd, (const char*)send_buf, strlen(send_buf), 0, (struct sockaddr*)&addr, sizeof(addr)) == -1){
            printf("[ERROR] Failed to send packet. Error code: %d\n", errno);
            return 1;
        }

        struct sockaddr_in recv_addr;
        socklen_t addr_len = sizeof(struct sockaddr_in);

        bytes_received = recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr*)&recv_addr, &addr_len);
        if(bytes_received > 0){
            inet_ntop(AF_INET, &recv_addr.sin_addr, ip, INET_ADDRSTRLEN);
            printf("%d\t%s\t%.3f\n", ttl, ip, ((double)tv.tv_sec * 1000) + ((double)tv.tv_usec / 1000));
        } else {
            printf("%d\t*\t\t*\n", ttl);
        }

        ttl++;
        if(strcmp(ip, dest_addr) == 0){
            break;
        }
    }
    close(sockfd);
    return 0;
}