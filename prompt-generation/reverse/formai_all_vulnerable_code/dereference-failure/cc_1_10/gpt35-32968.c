//FormAI DATASET v1.0 Category: Network Ping Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#define PACKET_SIZE 64
#define MAX_HOPS 16

/* Function to calculate ICMP checksum */
uint16_t checksum(void *buf, int len) {
    uint32_t sum = 0;
    uint16_t *ip = buf;
    while (len > 1) {
        sum += *ip++;
        len -= 2;
    }
    if (len) {
        sum += *(uint8_t *)ip;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return ~sum;
}

/* Function to parse IP address from host name */
char *lookup_address(char *host_name) {
    struct hostent *host_details;
    struct in_addr **addr_list;
    char *ip_address;
    int i;
    if ((host_details = gethostbyname(host_name)) == NULL) {
        perror("Couldn't resolve hostname");
        exit(EXIT_FAILURE);
    }
    addr_list = (struct in_addr **) host_details->h_addr_list;
    for (i = 0; addr_list[i] != NULL; i++) {
        ip_address = strdup(inet_ntoa(*addr_list[i]));
    }
    return ip_address;
}

/* Function to send ICMP Echo Request and receive ICMP Echo Reply */
double ping(int sockfd, struct sockaddr_in *dest_address, int ttl) {
    char recv_packet[PACKET_SIZE];
    char send_packet[PACKET_SIZE];
    memset(send_packet, 0, PACKET_SIZE);
    memset(recv_packet, 0, PACKET_SIZE);
    struct icmp *icmp_header;
    struct timeval start_time, end_time;
    int icmp_sequence = 0, recv_len, msg_count = 0;
    double rtt = 0, total_rtt = 0;
    icmp_header = (struct icmp *) send_packet;
    icmp_header->icmp_type = ICMP_ECHO;
    icmp_header->icmp_code = 0;
    icmp_header->icmp_id = getpid() & 0xFFFF;
    icmp_header->icmp_seq = icmp_sequence++;
    memset(icmp_header->icmp_data, 0xa5, sizeof(icmp_header->icmp_data));
    icmp_header->icmp_cksum = checksum((uint16_t *) icmp_header, sizeof(struct icmp));
    if (setsockopt(sockfd, SOL_IP, IP_TTL, &ttl, sizeof(ttl)) != 0) {
        perror("setsockopt error");
        exit(EXIT_FAILURE);
    }
    if (gettimeofday(&start_time, NULL) < 0) {
        perror("gettimeofday error");
        exit(EXIT_FAILURE);
    }
    if (sendto(sockfd, send_packet, sizeof(send_packet),
               0, (struct sockaddr *) dest_address, sizeof(*dest_address)) <= 0) {
        perror("sendto error");
        exit(EXIT_FAILURE);
    }
    msg_count++;
    if ((recv_len = recvfrom(sockfd, recv_packet, sizeof(recv_packet),
                             0, NULL, NULL)) <= 0) {
        perror("recvfrom error");
        exit(EXIT_FAILURE);
    }
    if (gettimeofday(&end_time, NULL) < 0) {
        perror("gettimeofday error");
        exit(EXIT_FAILURE);
    }
    struct iphdr *ip_header = (struct iphdr *) recv_packet;
    icmp_header = (struct icmp *) (recv_packet + ip_header->ihl * 4);
    if ((icmp_header->icmp_type == ICMP_ECHOREPLY) &&
        (icmp_header->icmp_id == getpid() & 0xFFFF)) {
        rtt = (double) (end_time.tv_sec - start_time.tv_sec) * 1000.0;
        rtt += (double) (end_time.tv_usec - start_time.tv_usec) / 1000.0;
        total_rtt += rtt;
        printf("%d\t\t%s\t\t%f ms\n", ttl, inet_ntoa(dest_address->sin_addr), rtt);
    }
    return total_rtt / msg_count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *host_name = argv[1];
    char *ip_address = lookup_address(host_name);
    printf("Pinging %s [%s] with %d bytes of data:\n\n", host_name, ip_address, PACKET_SIZE);
    struct sockaddr_in dest_address;
    struct timeval timeout = {3, 0};
    double mean_rtt = 0;
    int sockfd, ttl = 1, failures = 0;
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt error");
        exit(EXIT_FAILURE);
    }
    while (ttl <= MAX_HOPS && failures < 3) {
        dest_address.sin_family = AF_INET;
        dest_address.sin_addr.s_addr = inet_addr(ip_address);
        mean_rtt = ping(sockfd, &dest_address, ttl++);
        if (mean_rtt == 0) {
            printf("%d\t\t*\t\tRequest timed out.\n", ttl - 1);
            failures++;
        } else {
            failures = 0;
        }
    }
    printf("\nPing statistics for %s:\n", ip_address);
    printf("\t\tPackets: Sent = %d, Received = %d, Lost = %d (%.2f%% loss), Average RTT = %.2f ms\n",
           ttl - 2, ttl - failures - 2, failures, (double) failures / (double) (ttl - 2) * 100.0, mean_rtt);
    return 0;
}