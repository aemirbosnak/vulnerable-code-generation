//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>

#define PACKET_SIZE 64

void ping(struct sockaddr_in *dest_addr, int ttl, int timeout);

unsigned short checksum(void *b, int len);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: unknown host '%s'\n", argv[1]);
        return 1;
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(0);
    dest_addr.sin_addr = *((struct in_addr *) host->h_addr);

    printf("Pinging %s [%s] with %d bytes of data:\n\n",
           host->h_name, inet_ntoa(dest_addr.sin_addr), PACKET_SIZE);

    for (int ttl = 1; ttl <= 30; ttl++) {
        printf("TTL=%d  ", ttl);
        ping(&dest_addr, ttl, 1000);
    }

    return 0;
}

void ping(struct sockaddr_in *dest_addr, int ttl, int timeout) {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("Error: cannot create socket.\n");
        return;
    }

    if (setsockopt(sockfd, SOL_IP, IP_TTL, &ttl, sizeof(ttl)) != 0) {
        printf("Error: failed to set TTL.\n");
        close(sockfd);
        return;
    }

    char packet[PACKET_SIZE];
    memset(packet, 0, sizeof(packet));

    struct icmp *icmp_hdr = (struct icmp *) packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = htons(getpid() & 0xFFFF);
    icmp_hdr->icmp_seq = htons(1);
    memset(&icmp_hdr->icmp_data, '7', sizeof(icmp_hdr->icmp_data));
    icmp_hdr->icmp_cksum = checksum(packet, PACKET_SIZE);

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    if (sendto(sockfd, packet, sizeof(packet), 0,
               (struct sockaddr *) dest_addr, sizeof(*dest_addr)) < 0) {
        printf("Error: failed to send packet.\n");
        close(sockfd);
        return;
    }

    char buffer[PACKET_SIZE];
    struct sockaddr_in recv_addr;
    socklen_t addr_len = sizeof(recv_addr);

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    struct timeval timeout_tv = {timeout / 1000, (timeout % 1000) * 1000};
    int n = select(sockfd + 1, &readfds, NULL, NULL, &timeout_tv);
    if (n <= 0) {
        printf("Request timed out.\n");
        close(sockfd);
        return;
    }

    int len = recvfrom(sockfd, buffer, sizeof(buffer), 0,
                       (struct sockaddr *) &recv_addr, &addr_len);
    if (len < 0) {
        printf("Error: failed to receive packet.\n");
        close(sockfd);
        return;
    }

    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    double elapsed_time = (double) (current_time.tv_sec - start_time.tv_sec) * 1000.0;
    elapsed_time += (double) (current_time.tv_usec - start_time.tv_usec) / 1000.0;

    printf("Reply from %s: bytes=%d time=%.3fms\n",
           inet_ntoa(recv_addr.sin_addr), len, elapsed_time);

    struct icmp *icmp_reply = (struct icmp *) buffer;
    if (icmp_reply->icmp_type == ICMP_ECHOREPLY) {
        close(sockfd);
        return;
    }

    close(sockfd);
}

unsigned short checksum(void *b, int len) {
    unsigned short *buf = (unsigned short *) b;
    unsigned int sum = 0;
    unsigned short result;

    for (int i = 0; i < len / 2; i++) {
        sum += ntohs(buf[i]);
    }

    if (len % 2 != 0) {
        sum += *((unsigned char *) (b + len - 1));
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}