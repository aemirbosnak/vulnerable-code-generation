//FormAI DATASET v1.0 Category: Network Ping Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <unistd.h>

#define PACKET_SIZE 64
#define MAX_WAIT_TIME 5
#define SEND_TIMES 2

int main(int argc, char *argv[]) {
    // Check if there is only one argument provided
    if (argc != 2) {
        printf("Usage: %s [IP address]\n", argv[0]);
        exit(-1);
    }

    char *dest_ip = argv[1];
    int on = 1;
    struct hostent *host = NULL;
    struct sockaddr_in to_addr;

    // Create a raw socket that can access ICMP protocol
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(-1);
    }

    setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on));

    // Get the host by IP address
    if ((host = gethostbyname(dest_ip)) == NULL) {
        printf("Unknown host %s\n", dest_ip);
        exit(-1);
    }

    memset(&to_addr, 0, sizeof(struct sockaddr_in));
    to_addr.sin_family = AF_INET;
    to_addr.sin_addr = *(struct in_addr *) host->h_addr;

    int i, j, pack_count = 0;
    int packet_size = PACKET_SIZE;
    struct timeval tv_out = {MAX_WAIT_TIME, 0};
    char send_buf[PACKET_SIZE];
    char recv_buf[PACKET_SIZE];
    struct icmp *send_icmp = (struct icmp *) send_buf;
    struct icmp *recv_icmp = NULL;
    int send_len = 0;
    int recv_len = 0;

    // Loop to send ping packets
    for (i = 0; i < SEND_TIMES; i++) {
        pack_count++;
        memset(send_buf, 0, packet_size);
        send_icmp->icmp_type = ICMP_ECHO;
        send_icmp->icmp_code = 0;
        send_icmp->icmp_id = getpid();
        send_icmp->icmp_seq = pack_count;
        gettimeofday((struct timeval *) send_icmp->icmp_data, NULL);
        send_len = packet_size;

        if (sendto(sockfd, send_buf, send_len, 0, (struct sockaddr *) &to_addr, sizeof(struct sockaddr)) <= 0) {
            perror("sendto");
            continue;
        }

        // Wait to receive ping response
        for (j = 0; j < MAX_WAIT_TIME; j++) {
            recv_len = sizeof(struct sockaddr);
            memset(recv_buf, 0, sizeof(recv_buf));
            if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv_out, sizeof(tv_out)) < 0) {
                perror("setsockopt");
                exit(-1);
            }
            if (recvfrom(sockfd, recv_buf, recv_len, 0, (struct sockaddr *) &to_addr, &recv_len) <= 0) {
                printf("Timeout\n");
                break;
            }

            struct ip *ip_hdr = (struct ip *) recv_buf;
            recv_icmp = (struct icmp *) (recv_buf + (ip_hdr->ip_hl << 2));
            if (recv_icmp->icmp_type == ICMP_ECHOREPLY) {
                printf("%d bytes from %s icmp_seq=%u ttl=%d time=%ld ms\n", 
                    packet_size, inet_ntoa(to_addr.sin_addr), recv_icmp->icmp_seq, 
                    ip_hdr->ip_ttl, (tv_out.tv_sec * 1000 + tv_out.tv_usec / 1000));
                break;
            }
        }
    }

    close(sockfd);
    return 0;
}